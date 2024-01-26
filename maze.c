#define _XOPEN_SOURCE_EXTENDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <curses.h>

#include "maze.h"
#include "player.h"
#include "tree.h"

#define N 1000

char *tile_to_string(TileKind t)
{
    switch (t)
    {
    case WALL:
        return "⬜";
    case EMPTY:
        return "  ";
    case BEGIN:
        return "  ";
    case END:
        return "☕";
    case POTION:
        return "🧪";
    case DIAMOND:
        return "💎";
    case STAR:
        return "🌟";
    case TELEPORTATION:
        return "🔮";
    case EXPLOSION:
        return "💥";
    case TORNADO:
        return "🌪️";
    default:
        return "X";
    }
}

TileList *tile_list_new()
{
    TileList *new = malloc(sizeof(TileList));
    new->len = 0;
    new->capacity = 20;
    new->array = malloc(sizeof(TileList) * new->capacity);

    return new;
}

void tile_list_destroy(TileList *l)
{
    free(l->array);
    free(l);
}

void tile_list_push(TileList *l, TileKind t)
{
    if (l->capacity == l->len)
    {
        l->capacity = l->capacity * 2;
        l->array = realloc(l->array, l->capacity*sizeof(TileList));
    }

    l->array[l->len] = t;
    l->len++;
}

void tile_list_print(TileList *l)
{
    for (int i = 0; i < l->len; i++)
        printf("%s ", tile_to_string(l->array[i]));

    printf("\n");
}

BuildMaze *build_maze_new()
{
    BuildMaze *new = malloc(sizeof(BuildMaze));
    new->len = 0;
    new->capacity = 20;
    new->array = malloc(sizeof(TileList*) * new->capacity);

    return new;
}

void build_maze_destroy(BuildMaze *l)
{
    for(int i=0; i < l->len; i++)
        tile_list_destroy(l->array[i]);
    free(l->array);
    free(l);
}

void build_maze_add_tile(BuildMaze *l, TileKind t) {
    tile_list_push(l->array[l->len-1],t);
}

void build_maze_next_line(BuildMaze *l) {
    if (l->capacity == l->len)
    {
        l->capacity = l->capacity * 2;
        l->array = realloc(l->array, l->capacity*sizeof(TileList*));
    }

    l->array[l->len] = tile_list_new();
    l->len++;
}

TileKind** build_maze_build(BuildMaze *l){
    TileKind** res = malloc(sizeof(TileKind*)*l->len);
    
    for(int i=0; i < l->len; i++) {
        res[i] = l->array[i]->array;
        free(l->array[i]);
    }

    free(l->array);
    free(l);
    return res;
}

Location find_tile(TileKind** t, int x_len, int y_len, TileKind tile, char* err){
    for(int i = 0 ; i < y_len ; i++){
        for(int j = 0 ; j < x_len ; j++){
            if(t[i][j] == tile){
                return location_new(j,i);
            }
        }
    }

    fprintf(stderr, err);
    exit(1);
}

Location find_begin(TileKind** t, int x_len, int y_len){
    return find_tile(t, x_len, y_len, BEGIN, "Le labyrinthe n'a pas de début");
}

Location find_end(TileKind** t, int x_len, int y_len){
    return find_tile(t, x_len, y_len,END, "Le labyrinthe n'a pas de fin");
}

void maze_print_debug(TileKind** t, int x_len, int y_len){
    for(int i = 0 ; i < y_len ; i++){
        for(int j = 0 ; j < x_len ; j++){
            printf("%s", tile_to_string(t[i][j]));
        }
        printf("\n");
    }
}

void print_maze(Maze* m, Player p ){
    int l, c;

    for(int i=0; i<m->y_len;i++){
        l=(LINES/2)-(m->y_len/2)+i;
        for(int j=0;j<m->x_len;j++){
            c=(COLS/2)-(m->x_len)+j*2;
            
            if(p.lo.x==j && p.lo.y==i){
                mvprintw(l,c,"%s", character_to_string(p.character));
            } else {
                mvprintw(l,c,"%s",tile_to_string(m->maze[i][j]));
            }
        }
    }
}


void print_maze_resolved(Maze* m){
    int l, c;

    Tree* t = tree_from_maze(m);
    LocationList* best_path =tree_best_path(t, m->end);

    tree_destroy(t);

    for(int i=0; i<m->y_len;i++){
        l=(LINES/2)-(m->y_len/2)+i;
        for(int j=0;j<m->x_len;j++){
            c=(COLS/2)-(m->x_len)+j*2;
            
            if(location_list_contains(best_path,location_new(j,i)) && m->maze[i][j] != BEGIN && m->maze[i][j] != END){
                mvprintw(l,c,"🐙");
            } else {
                mvprintw(l,c,"%s",tile_to_string(m->maze[i][j]));
            }
        }
    }
    location_list_destroy(best_path);
}

Maze* maze_from_csv(char* path){

    Maze* res = malloc(sizeof(Maze));
    BuildMaze* bm = build_maze_new();
    
    char line[N];
    int row = 0;
    int col = 0;

    FILE* file = fopen(path, "r");

    if (file == NULL) {
        fprintf(stderr, "Le fichier %s n'existe pas.\n", path);
        exit(1);
    }

    while (fgets(line, N, file) != NULL) {
        char* token = strtok(line, ",");
        build_maze_next_line(bm);
        while (token != NULL) {
            int value = atoi(token);
            build_maze_add_tile(bm,value);
            token = strtok(NULL, ",");

            if(row == 0)
                col++;
        }
        row++;
    }

    fclose(file);
    res->x_len = col;
    res->y_len = row;
    res->maze = build_maze_build(bm);
    // maze_print_debug(res->maze, res->x_len, res->y_len);

    res->begin = find_begin(res->maze, res->x_len, res->y_len);
    res->end = find_end(res->maze, res->x_len, res->y_len);

    // location_print_debug(res->begin);
    // location_print_debug(res->end);

    return res;
}

void maze_destroy(Maze* m){
    for(int i = 0; i< m->y_len; i++){
        free(m->maze[i]);
    }

    free(m->maze);
    free(m);
}

void maze_put_potions(Maze* m) {
    srand(time(NULL));

      for(int i = 0 ; i < m->y_len ; i++){
        for(int j = 0 ; j < m->x_len ; j++){
            if(m->maze[i][j]==EMPTY){
                if ((rand() % 300) == 0) {
                    m->maze[i][j]=TORNADO;
                } 
                if ((rand() % 200) == 0) {
                    m->maze[i][j]=EXPLOSION;
                }            
                if ((rand() % 100) == 0) {
                    m->maze[i][j]=POTION;
                }
                if ((rand() % 100) == 0) {
                    m->maze[i][j]=STAR;
                }
                if ((rand() % 100) == 0) {
                    m->maze[i][j]=TELEPORTATION;
                }
                if ((rand() % 50) == 0) {
                    m->maze[i][j]=DIAMOND;
                }
            }
        }
    }
}