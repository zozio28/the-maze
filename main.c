#define _XOPEN_SOURCE_EXTENDED
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <curses.h>
#include <locale.h>
#include <signal.h>
#include <stdbool.h>

#include "maze.h"
#include "game.h"
#include "tree.h"
#include "player.h"
#include "menu.h"

void int_handler(int _dummy) {
  erase();
  endwin();
  exit(1);
}

int main()
{
    Game g = game_new();

    setlocale(LC_ALL, "en_US.UTF-8");
    signal(SIGINT, int_handler);

    while(game_menu(&g)){};

    return 0;
}