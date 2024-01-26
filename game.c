#define _XOPEN_SOURCE_EXTENDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "game.h"
#include "location.h"
#include "player.h"
#include "menu.h"
#include "maze.h"
#include "tree.h"

#define N 1000

Game game_new(){
    Game g;
    g.settings.language = 1;
    g.settings.mode = 0;
    g.player = player_new(g.player.lo);
    g.game_over = 0;

    return g;
}

void save_game(Game g)
{
    // Open the CSV file
    FILE *save = fopen("save.csv", "w");

    if (save == NULL)
    {
        fprintf(stderr, "Failed to open the file.\n");
        exit(1);
    }

    fprintf(save, "%s,%d,%d,%d,%d,%d,%d,%s", g.player.name, g.player.character,g.player.hp, g.player.lo.x,g.player.lo.y, g.settings.language, g.settings.mode,g.player.file);
    fclose(save); // close the file    fclose(save); // close the file
}

int succeed_read(){
    FILE *save = fopen("save.csv", "r");

    if (save == NULL)
    {
        return 0;
    }else{
        fclose(save);
        return 1;
    }
}

void read_save(Game* g){
    char line[N];
    int row = 0;
    int col = 0;

    FILE *save = fopen("save.csv", "r");

    if (save == NULL)
    {
        fprintf(stderr, "Failed to open the file.\n");
        exit(1);
    }

    while (fgets(line, N, save) != NULL) {
        char* token = strtok(line, ",");

        while (token != NULL) {

            switch(col){
                case 0: 
               strcpy(g->player.name, token);
                    break;
                case 1:
                    g->player.character = atoi(token);
                    break;
                case 2:
                    g->player.hp = atoi(token);
                    break;
                case 3:
                    g->player.lo.x = atoi(token);
                    break;
                case 4:
                    g->player.lo.y = atoi(token);
                    break;
                case 5:
                    g->settings.language = atoi(token);
                    break;
                case 6:
                    g->settings.mode = atoi(token);
                    break;
                case 7:
                    strcpy(g->player.file,token);
                default:
                    break;
            }
            token = strtok(NULL, ",");
            if(row == 0)
                col++;
        }
        row++;
    }
    fclose(save);
}

void ask_save(Game g)
{
    char response;

    switch(g.settings.language){
        case 1:
            printf("Do you want to save the game? (Y/N): ");
            scanf(" %c", &response);
            if (response == 'Y' || response == 'y')
            {
                save_game(g);
                printf("Game saved!\n");
            }
            else if (response == 'N' || response == 'n')
            {
                printf("Game not saved\n");
            }
            else
            {
                printf("Invalid response\n");
            }
            break;
        case 2:
            printf("Voulez-vous sauvegarder la partie? (Y/N): ");
            scanf(" %c", &response);
            if (response == 'Y' || response == 'y')
            {
                save_game(g);
                printf("Partie sauvegardée !\n");
            }
            else if (response == 'N' || response == 'n')
            {
                printf("Partie non sauvegardée \n");
            }
            else
            {
                printf("Réponse invalide\n");
            }
            break;
    }
}

void game_run(Game* g, int new_game){
    int loop = 1;
    int reverse_keys = 0;
    int input_result;
    char path[1002];
    WINDOW *w = initscr();
   
    if(new_game){
        sprintf(path, "./levels/%s.csv", ask_level());
        strcpy(g->player.file,path);
    }else{
        strcpy(path,g->player.file);
    }

    g->maze = maze_from_csv(path);
    if(new_game){
        g->player.lo=g->maze->begin;
    }

    if(g->settings.mode == CHEAT){
        print_maze_resolved(g->maze);
        getch();
        refresh();
        erase();
        clear();
        refresh();

        maze_destroy(g->maze);    
        endwin();

        return;
    }

    select_character(g);

    if(g->settings.mode == OBJECT){
        maze_put_potions(g->maze);
    }
 
    clear();
    refresh();
  
    while(loop) {
        input_result=0;
        print_maze(g->maze, g->player);
        player_status_line(g->player);
        input_result=game_input(g,w,reverse_keys);
        
        game_handle_potions(g, &reverse_keys);
      
        if(input_result==1){
            loop=pause_menu(g);
        }

        if (g->player.hp==0) {
            loop = 0;
            g->game_over=1;
        }
        
        if (location_eq(g->player.lo, g->maze->end)){
            loop=0;
        }
    }

    refresh();
    erase();
    clear();
    refresh();
    
    maze_destroy(g->maze);    
    endwin();
}


int game_input(Game* g, WINDOW *w, int reverse_keys){
    int res=0;
    Location lo;
    LocationList* l;
    int offset_a = reverse_keys ? -1 : 1;
    int offset_b = reverse_keys ? 1 : -1;


    keypad(w, false);
    keypad(w, true);

    int c = getch();

    switch (c) {
    case KEY_UP:
        lo = location_new(g->player.lo.x,g->player.lo.y+offset_b);
      break;
    case KEY_DOWN:
        lo = location_new(g->player.lo.x,g->player.lo.y+offset_a);
          break;
    case KEY_LEFT:
        lo = location_new(g->player.lo.x+offset_b,g->player.lo.y);
        break;
      break;
    case KEY_RIGHT:
        lo = location_new(g->player.lo.x+offset_a,g->player.lo.y);
      break;
    case 10:
        res=1;
        break;
    }
    keypad(w, false);

    l = near_locations(g->player.lo,g->maze->x_len,g->maze->y_len);

    if(location_list_contains(l, lo) && g->maze->maze[lo.y][lo.x]!=WALL){
        g->player.lo = lo;
    }

    location_list_destroy(l);
    return res;
}

int pause_menu(Game* g){
    char choice;

    erase();
    clear();
    refresh();
    if (g->settings.language==1){
        mvprintw(LINES/2-1, COLS/2-8,"0 - quit");
        mvprintw(LINES/2+1, COLS/2-8, "1 - save\n");


    } else {
        mvprintw(LINES/2-1, COLS/2-11,"0 - quitter");
        mvprintw(LINES/2+1, COLS/2-15, "1 - sauvegarder\n");

    }
    refresh();
    choice=getch();

    if(choice=='0'){
        return 0;
    }else if(choice=='1'){
        save_game(*g);
        return 1;
    }

    erase();
    clear();
    refresh();

    return 1;
}

void game_handle_potions(Game* g, int* reverse_keys) {
    LocationList* l;
    Tree* t;

    if(g->maze->maze[g->player.lo.y][g->player.lo.x] == DIAMOND) {
        g->maze->maze[g->player.lo.y][g->player.lo.x] = EMPTY;
        g->player.diamonds++;
    }

    if(g->maze->maze[g->player.lo.y][g->player.lo.x] == STAR) {
        g->maze->maze[g->player.lo.y][g->player.lo.x] = EMPTY;
        g->player.hp++;
    }

    if(g->maze->maze[g->player.lo.y][g->player.lo.x] == POTION) {
        g->maze->maze[g->player.lo.y][g->player.lo.x] = EMPTY;
        g->player.hp--;
    }

    if(g->maze->maze[g->player.lo.y][g->player.lo.x] == EXPLOSION){
        g->maze->maze[g->player.lo.y][g->player.lo.x] = EMPTY;
        g->player.hp--;
        l = near_locations(g->player.lo,g->maze->x_len,g->maze->y_len);

        for(int i=0; i<l->len; i++){
            if (g->maze->maze[l->array[i].y][l->array[i].x] != END && l->array[i].y !=0 && l->array[i].y != g->maze->y_len-1 && l->array[i].x !=0 && l->array[i].x != g->maze->x_len-1 ) {
                g->maze->maze[l->array[i].y][l->array[i].x]= EMPTY;
            }
        }
        location_list_destroy(l);
    }

    if(g->maze->maze[g->player.lo.y][g->player.lo.x] == TELEPORTATION){
        g->maze->maze[g->player.lo.y][g->player.lo.x] = EMPTY;
        t=tree_from_maze(g->maze);
        tree_reduce(t);
        l=tree_collect_locations(t);

        g->player.lo = location_list_random(l);

        tree_destroy(t);
        location_list_destroy(l);
    }
    if(g->maze->maze[g->player.lo.y][g->player.lo.x] == TORNADO){
        g->maze->maze[g->player.lo.y][g->player.lo.x] = EMPTY;
        *reverse_keys = !*reverse_keys;
    }
}

void select_character(Game* g){
    int character;
    char table[12][10];

    table_character(table[0], 12);

    printw("0 | HELIANUX      1 | FOX       2 | FAIRY     3 | DINO        4 | GENIUS      5 | BUTTERFLY       6 | GHOST\n");
    for(int i = 0 ; i < 7 ; i++){
        printw("    %s          ", character_to_string(table[0][i]));
    }
    printw("\n7 | SANTA       8 | PATRICK     9 | RABBIT      10 | FARMER     11 | MARIO\n");
    for(int i = 7 ; i < 12 ; i++){
        printw("    %s          ", character_to_string(table[0][i]));
    }
    printw("\n\n");
    printw("Select your caracter : \n");
    refresh();
    scanw("%d", &character);

    if(g->player.characters_table[character]){
        g->player.character = character;
    }
}
