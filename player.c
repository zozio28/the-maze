#define _XOPEN_SOURCE_EXTENDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>

#include "location.h"
#include "maze.h"
#include "menu.h"

Player player_new(Location lo){
    Player p;
    printf("Enter your username : \n");
    scanf("%s", p.name);
    p.hp=5;
    p.lo=lo;
    p.character=0;
    p.diamonds=0;
    init_bool_table(p.characters_table);

    return p;
}

char *character_to_string(Character ch)
{
    switch (ch)
    {
    case HELIANUX:
        return "🤖";
        break;
    case FOX:
        return "🦊";
        break;
    case FAIRY:
        return "🧚‍";
        break;
    case DINO:
        return "🦕";
        break;
    case GENIUS:
        return "🧞";
        break;
    case BUTTERFLY:
        return "🦋";
        break;
    case GHOST:
        return "👻";
        break;
    case SANTA:
        return "🎅";
        break;
    case PATRICK:
        return "👨‍";
        break;
    case RABBIT:
        return "🐇";
        break;
    case FARMER:
        return "🚜";
        break;
    case MARIO:
        return "👲";
        break;
    default:
        return "X";
    }
}

void player_status_line(Player p){
    mvprintw(LINES-2,0,"🌟 %d",p.hp);
    mvprintw(LINES-1,0,"💎 %d",p.diamonds);
    refresh();
}