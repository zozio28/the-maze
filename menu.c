#define _XOPEN_SOURCE_EXTENDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "menu.h"

void printf_center(const char *text[], int text_lines)
{
    struct winsize size;
    ioctl(0, TIOCGWINSZ, &size);
    int i = 0;
    int terminalWidth = size.ws_col;
    int terminalHeight = size.ws_row;
    int textLength;
    int spaces;
    int lines = (terminalHeight) / 2;
    for (int i = 0; i < lines; i++)
    {
        printf("\n");
    }
    textLength = strlen(text[0]);
    spaces = (terminalWidth - textLength) / 2;
    while (text[i] != NULL && i < text_lines)
    {
        printf("%*s%s%*s\n", spaces, "", text[i], spaces, "");
        i++;
    }
    for (int i = 0; i < lines; i++)
    {
        printf("\n");
    }
}


void home_page()
{
    const char *text[7];

    text[0] = "                                                                                               "; // size
    text[1] = "████████╗██╗  ██╗███████╗     \033[0;38;5;57m███╗   ███╗ █████╗ █████████╗███████╗\033[00m ██╗";
    text[2] = "╚══██╔══╝██║  ██║██╔════╝     \033[0;38;5;57m████╗ ████║██╔══██╗╚════███╔╝██╔════╝\033[00m ██║";
    text[3] = "   ██║   ███████║█████╗       \033[0;38;5;57m██╔████╔██║███████║   ███╔═╝ █████╗  \033[00m ██║";
    text[4] = "   ██║   ██╔══██║██╔══╝       \033[0;38;5;57m██║╚██╔╝██║██╔══██║ ███╔═╝   ██╔══╝  \033[00m ╚═╝";
    text[5] = "   ██║   ██║  ██║███████╗     \033[0;38;5;57m██║ ╚═╝ ██║██║  ██║█████████╗███████╗\033[00m ██╗";
    text[6] = "   ╚═╝   ╚═╝  ╚═╝╚══════╝     \033[0;38;5;57m╚═╝     ╚═╝╚═╝  ╚═╝╚════════╝╚══════╝\033[00m ╚═╝";

    printf_center(text, 7);
}

void end_page(int language)
{
    const char *text[7];
    switch (language)
    {
    case 1:
        text[0] = "                                                                                       "; // size
        text[1] = "███████╗███╗   ██╗██████╗      ██████╗ ███████╗     ██████╗  █████╗ ███╗   ███╗███████╗";
        text[2] = "██╔════╝████╗  ██║██╔══██╗    ██╔═══██╗██╔════╝    ██╔════╝ ██╔══██╗████╗ ████║██╔════╝";
        text[3] = "█████╗  ██╔██╗ ██║██║  ██║    ██║   ██║█████╗      ██║  ███╗███████║██╔████╔██║█████╗  ";
        text[4] = "██╔══╝  ██║╚██╗██║██║  ██║    ██║   ██║██╔══╝      ██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  ";
        text[5] = "███████╗██║ ╚████║██████╔╝    ╚██████╔╝██║         ╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗";
        text[6] = "╚══════╝╚═╝  ╚═══╝╚═════╝      ╚═════╝ ╚═╝          ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝";
        break;
    case 2:
        text[0] = "                                                                      "; // size
        text[1] = "███████╗██╗███╗   ██╗    ██████╗ ███████╗         ██╗███████╗██╗   ██╗";
        text[2] = "██╔════╝██║████╗  ██║    ██╔══██╗██╔════╝         ██║██╔════╝██║   ██║";
        text[3] = "█████╗  ██║██╔██╗ ██║    ██║  ██║█████╗           ██║█████╗  ██║   ██║";
        text[4] = "██╔══╝  ██║██║╚██╗██║    ██║  ██║██╔══╝      ██   ██║██╔══╝  ██║   ██║";
        text[5] = "██║     ██║██║ ╚████║    ██████╔╝███████╗    ╚█████╔╝███████╗╚██████╔╝";
        text[6] = "╚═╝     ╚═╝╚═╝  ╚═══╝    ╚═════╝ ╚══════╝     ╚════╝ ╚══════╝ ╚═════╝ ";
        break;

    default:
        break;
    }
    printf_center(text, 7);
}

void shop_page(int language)
{
    system("clear");
    const char *text[7];
    switch (language)
    {
    case 1:
        text[0] = "                                                                                                                    "; // size
        text[1] = "                                                       \033[0;35;5;57m███████╗██╗  ██╗ ██████╗ ███████╗\033[00m";
        text[2] = "                                                       \033[0;35;5;57m██╔════╝██║  ██║██╔═══██╗██╔══██║\033[00m";
        text[3] = "                                                       \033[0;35;5;57m███████╗███████║██║   ██║███████║\033[00m";
        text[4] = "                                                       \033[0;35;5;57m     ██║██╔══██║██║   ██║██╔════╝\033[00m";
        text[5] = "                                                       \033[0;35;5;57m███████║██║  ██║╚██████╔╝██║     \033[00m";
        text[6] = "                                                       \033[0;35;5;57m╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚═╝     \033[00m";
        break;
    case 2:
        text[0] = "                                                                                                                             "; // size
        text[1] = "                                                       \033[0;35;5;57m █████╗  ██████╗██╗  ██╗ █████╗ ████████╗\033[00m";
        text[2] = "                                                       \033[0;35;5;57m██╔══██╗██╔════╝██║  ██║██╔══██╗╚══██╔══╝\033[00m";
        text[3] = "                                                       \033[0;35;5;57m███████║██║     ███████║███████║   ██║   \033[00m";
        text[4] = "                                                       \033[0;35;5;57m██╔══██║██║     ██╔══██║██╔══██║   ██║   \033[00m";
        text[5] = "                                                       \033[0;35;5;57m██║  ██║╚██████╗██║  ██║██║  ██║   ██║   \033[00m";
        text[6] = "                                                       \033[0;35;5;57m╚═╝  ╚═╝ ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝   ╚═╝   \033[00m";
        break;

    default:
        break;
    }
    for(int i = 0; i< 7 ; i++){
        printf("%s\n",text[i]);
    }
    printf("\n\n\n");
}

int game_menu(Game* g){
    system("clear");
    int choice;

    // init_set(g);

    home_page();
    switch (g->settings.language)
    {
    case 1:
        if (succeed_read())
        {
            printf("\033[0;32m0. Continue saved game\033[00m  ");
        }
        else
        {
            printf("0. \x1b[9mNo saved game\x1b[0m  ");
        }

        printf("1. Start  2. Shop  3. Settings  4. Exit\n");
        break;
    case 2:
        if (succeed_read())
        {
            printf("\033[0;32m0. Reprendre la sauvegarde\033[00m  ");
        }
        else
        {
            printf("0. \x1b[9mAucune partie sauvegardé\x1b[0m  ");
        }

        printf("1. Jouer  2. Achat  3. Paramètres  4. Quitter\n");
        break;

    default:
        break;
    }
    scanf(" %d", &choice);
    int d = 0;
    while((d = getchar() != '\n') && d != EOF){}

    if (choice == 0)
    {
        if (succeed_read())
        {
            system("clear");
            read_save(g); // read the save and initialize the game
            game_run(g,0);
        }
        return 1;
    }
    else if (choice == 1)
    {
        game_run(g,1);
        return 1;
    }
    else if (choice == 2)
    {
        print_shop(g);
        return 1;
    }
    else if (choice == 3)
    {
        settings_page(g);
        return 1;
    }
    else if (choice == 4)
    {
        end_page(g->settings.language);
        return 0;
    }
    return 1;
}

char* check_box(int i){
    if(i)
        return "🗹";
    else
        return "☐";
}

void check_box_print(int i, char* car){
    char line[1002];

    sprintf(line,"  %s %s\n",check_box(i),car);
    printf(line);
}

void settings_page(Game* g)
{
    system("clear");
    char response;

    printf("Settings\n\n");
    printf("Language:\n");
    check_box_print(g->settings.language == 1,"English (e)");
    check_box_print(g->settings.language == 2,"French (f)");
    printf("\nCheat:\n");
    check_box_print(g->settings.mode == CHEAT,"Solution (s)");
    printf("\nObjects:\n");
    check_box_print(g->settings.mode == OBJECT,"Objects(o)");
    printf("                                          (q) Save and quit\n");

    scanf(" %c", &response);
    if (response == 'Q' || response == 'q')
    {
        return;
    }
    else
    {
        if (response == 'S' || response == 's')
        {
            if(g->settings.mode == CHEAT)
                g->settings.mode = NORMAL;
            else
                g->settings.mode = CHEAT;
            settings_page(g);
        }
        else if (response == 'O' || response == 'o')
        {
            if(g->settings.mode == OBJECT)
                g->settings.mode = NORMAL;
            else
                g->settings.mode = OBJECT;
            settings_page(g);
        }
        else if (response == 'E' || response == 'e')
        {
            g->settings.language = 1;
            settings_page(g);
        }
        else if (response == 'F' || response == 'f')
        {
            g->settings.language = 2;
            settings_page(g);
        }
        else
        {
            settings_page(g);
        }
    }
}

void table_character(char *table, int size) {
    for (int i = 0; i < size; i++) {
        table[i] = i;
    }
}

void print_shop(Game* g) {
    char table[12][10]; // Choisir une taille fixe pour les chaînes de caractères
    int diamonds[12];

    shop_page(g->settings.language);
    table_character(table[0], 12);
    table_diamonds(diamonds,12);

    printf("       ╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("       ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║\n");
    printf("       ║");
    for (int i = 0; i < 12; i++) {
        printf("    %s    ║", character_to_string(table[0][i]));
    }
    printf("\n       ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║\n");
    printf("       ╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("       ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║\n");
    printf("       ║   FREE   ║");
    for (int i = 1; i < 12; i++) {
        printf("   %d💎   ║", diamonds[i]);
    }
    printf("\n       ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║          ║\n");
    printf("       ╚═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n\n");

    ask_buy(g);
}

void init_bool_table(int* table){
    table[0] = 1;
    for (int i = 1 ; i < 12 ; i++){
        table[i] = 0;
    }
}

int bool_table(Player player,int i){
    player.characters_table[i] = 1;

    return player.characters_table[i];
}

void table_diamonds(int *table, int size) {
    for (int i = 0; i < size; i++) {
        table[i] = i*2+10;
    }
}

void ask_buy(Game* g){
    char response;

    printf("Number of diamonds in your possession : %d💎 \n\n",g->player.diamonds);
    printf("Do you want to buy a character (y/n)?\n");
    scanf("%c", &response);
    if(response == 'Y' || response == 'y'){
        buy_character(g);
    }
}

void buy_character(Game* g){
    int choice;
    char other;
    int table[12];

    table_diamonds(table, 12);

    printf("0 | HELIANUX\n");
    printf("1 | FOX\n");
    printf("2 | FAIRY\n");
    printf("3 | DINO\n");
    printf("4 | GENIUS\n");
    printf("5 | BUTTERFLY\n");
    printf("6 | GHOST\n");
    printf("7 | SANTA\n");
    printf("8 | PATRICK\n");
    printf("9 | RABBIT\n");
    printf("10 | FARMER\n");
    printf("11 | MARIO\n\n");

    printf("Choose a character to buy\n");
    scanf("%d",&choice);

    int d = 0;
    while((d = getchar() != '\n') && d != EOF){}
    
    if(g->player.characters_table[choice]){
        printf("You already have this character, do you want to choose another one ? (y/n)\n");
        scanf("%c",&other);

        int d = 0;
        while((d = getchar() != '\n') && d != EOF){}

        if(other == 'Y' || other == 'y'){
            buy_character(g);
        }
    }else if(g->player.diamonds < table[choice]){
        printf("\033[0;31;5;57mYou don't have enough diamonds\033[00m\n\n");
        ask_buy(g);
    }else{
        bool_table(g->player,choice);
        g->player.diamonds -= table[choice];
        printf("\033[0;32;5;57mThe bought of your character is successful ! \033[00m\n");
        printf("You have %d💎 diamonds left \n",g->player.diamonds);
        g->player.characters_table[choice] = 1;
        ask_buy(g);
    }
}

int ask(char text[],int min,int max){
    int a,test;
    do{
        printw("%s",text);
        refresh();
        test = scanw("%d",&a);
        clear();
        refresh();
    }while((test==0) || (a <= (min-1)) || (a >= (max+1)));
    return a;
}

char* ask_level(){
    printw("1 - Easy \n");
    printw("2 - Medium\n");
    printw("3 - Hard\n");
    printw("4 - Extra hard\n");
    printw("5 - Only for genius\n\n");

    int choice = ask("Choose your difficulty : ",1,5);

    switch(choice){
        case 1:
            return ask_level_easy();
        case 2:
            return ask_level_medium();
        case 3:
            return ask_level_hard();
        case 4:
            return ask_level_extra_hard();
        case 5:
            return ask_level_genius();
        default:
            exit(1);
    }
}

char* ask_level_easy(){
    printw("1 - Chloe\n");
    printw("2 - Célia\n");
    printw("3 - Dylan\n");
    printw("4 - Ugo\n");
    printw("5 - Loris\n");
    printw("6 - Yan\n");
    printw("7 - Antoine\n");
    printw("8 - Gabriel\n");
    printw("9 - Charlyne\n");
    printw("10 - Maylis\n\n");
    
    int choice = ask("Choose your maze : ",1,10);

    switch(choice){
        case 1:
            return "chloe";
        case 2:
            return "celia";
        case 3:
            return "dylan";
        case 4:
            return "ugo";
        case 5:
            return "loris";
        case 6:
            return "yan";
        case 7:
            return "antoine";
        case 8:
            return "gabriel";
        case 9:
            return "charlyne";
        case 10:
            return "maylis";
        default:
            exit(1);
    }
}

char* ask_level_medium(){
    printw("1 - Etienne\n");
    printw("2 - Carlos\n");
    printw("3 - Charles\n");
    printw("4 - Mariam\n");
    printw("5 - Matéo\n");
    printw("6 - Mathis\n");
    printw("7 - Nassef\n");
    printw("8 - Oïhana\n");
    printw("9 - Alaïa\n");
    printw("10 - Othilie\n\n");
    
    int choice = ask("Choose your maze : ",1,10);

    switch(choice){
        case 1:
            return "etienne";
        case 2:
            return "carlos";
        case 3:
            return "charles";
        case 4:
            return "mariam";
        case 5:
            return "mateo";
        case 6:
            return "mathis";
        case 7:
            return "nassef";
        case 8:
            return "oihana";
        case 9:
            return "alaia";
        case 10:
            return "othilie";
        default:
            exit(1);
    }
}

     
char* ask_level_hard(){
    printw("1 - Paul\n");
    printw("2 - Clémentine\n");
    printw("3 - Etienne Bis\n");
    printw("4 - Gabin\n");
    printw("5 - Nathan\n");
    printw("5 - Yannis\n");
    printw("7 - Nylan\n\n");
    
    int choice = ask("Choose your maze : ",1,7);

    switch(choice){
        case 1:
            return "paul";
        case 2:
            return "clementine";
        case 3:
            return "etienneBis";
        case 4:
            return "gabin";
        case 5:
            return "nathan";
        case 6:
            return "yannis";
        case 7:
            return "nylan";
        default:
            exit(1);
    }
}

char* ask_level_extra_hard(){
    printw("1 - Zoé\n");
    printw("2 - Inès\n");
    printw("3 - Hélian\n\n");
    
    int choice = ask("Choose your maze : ",1,3);

    switch(choice){
        case 1:
            return "zoe";
        case 2:
            return "ines";
        case 3:
            return "helian";
        default:
            exit(1);
    }
}

char* ask_level_genius(){
    printw("1 - Hugo\n");
    printw("2 - Gustave\n");
    printw("3 - Ayrton\n");
    printw("4 - Maxime\n");
    printw("5 - Clara\n");
    printw("6 - JB\n");
    printw("7 - Yves\n");
    printw("8 - Alban\n");
    printw("9 - Lina\n");
    printw("10 - Chris\n");
    printw("11 - Lucas\n");
    printw("12 - Eloi Demolis\n\n");
    
    int choice = ask("Choose your maze : ",1,12);

    switch(choice){
        case 1:
            return "hugo";
        case 2:
            return "gustave";
        case 3:
            return "ayrton";
        case 4:
            return "maxime";
        case 5:
            return "clara";
        case 6:
            return "jb";
        case 7:
            return "yves";
        case 8:
            return "alban";
        case 9:
            return "lina";
        case 10:
            return "chris";
        case 11:
            return "lucas";
        case 12:
            return "eloiDemolis";
        default:
            exit(1);

    }
}