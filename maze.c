#include <stdlib.h>
#include <stdio.h>
#include "maze.h"
#include <unistd.h>
#include <termios.h>
#define N 1000

//create the maze
Maze createMaze(int value/*,Maze sLeft,Maze sRight,Maze sUp,Maze sDown*/){
    Maze new = malloc(sizeof(square));

    new->value = value;
    new->sLeft = NULL /*sLeft*/;
    new->sRight = NULL /*sRight*/;
    new->sUp = NULL /*sUp*/;
    new->sDown = NULL /*sDown*/;
    return new;
}

// Maze insertionArbre(int value, Maze m){
//     if(m == NULL){
//         return m = creerArbreBinaire(value,NULL,NULL);
//     }else if(value < m->value){
//         m->sLeft = insertionArbre(value,m->sLeft);
//     }else{
//         m->sRight = insertionArbre(value,m->sRight);
//     }else{
//         m->sDown = insertionArbre(value,m->sDown);
//     }else{
//         m->sUp = insertionArbre(value,m->sUp);
//     }
//     return m;
// }

int readCSV(char* fileMaze){
    char line[N];
    int row = 0;

    FILE* maze = NULL;
    maze = fopen(fileMaze, "r");
    Maze medium;

    if(maze != NULL){
        while (fgets(line, N, maze) != NULL) {
            char* token = strtok(line, ";");
            while (token != NULL) {
                int value = atoi(token);
                Maze* new = createMaze(value);

                if (row > 0) {
                    Maze* upper = maze->beginning;
                    for (int i = 0; i < row - 1; i++) {
                        upper = upper->sDown;
                }
                if (upper != NULL) {
                    new->sUp = upper->sRight;
                    upper->sRight = new;
                }
            }

            if (col > 0) {
                Node* leftNode = newNode;
                for (int i = 0; i < col - 1; i++) {
                    leftNode = leftNode->right;
                }
                leftNode->left = newNode;
            }

            if (row == 0 && col == 0) {
                maze->root = newNode;
            }

            token = strtok(NULL, ";");
            col++;
        }

        row++;
    }

    fclose(file);
    return 1;
}
            }    
        }
    }else{
        printf("Le fichier %s n'existe pas.\n",fileMaze);
        return 0;
    }
    return;
    fclose(maze);
}

void emptyBuffer() {
  char c;
  while (((c = getchar()) != '\n') && (c != EOF));
}

int differentMove(){
    struct termios tty_opts_backup, tty_opts_raw;
    char c;
    int pastermine=1;//par défaut on le met à vrai

    /* on est obligé d'appuyer sur la touche entrée */
    c =getchar();
    printf("on est obligé d'appuyer sur entrée : vous avez écrit %d \n", c);

    /* ON VIDE LE BUFFER*/
    emptyBuffer();

    // Back up current TTY settings
    tcgetattr(STDIN_FILENO, &tty_opts_backup);


    // Change TTY settings mode
    cfmakeraw(&tty_opts_raw);
    tcsetattr(STDIN_FILENO, TCSANOW, &tty_opts_raw);

    while (pastermine){
        // ZQSD
        c =getchar();
        switch(c){
            case 122: //haut

                printf("vous avez écrit %d => %c haut !",c,c);

                break;
            case 113: //gauche
                printf("vous avez écrit %d => %c gauche !",c,c);
                break;
            case 100: //droite
                printf("vous avez écrit %d => %c droite !",c,c);
                break;
            case 115: //bas
                printf("vous avez écrit %d => %c bas !",c,c);
                break;
            case 97:
                printf("vous avez tapé la lettre %c pour quitter le programme!",c);
                pastermine=0;
                break;
            default:
                printf("touche clavier %d => %c NON prise en compte ",c,c);
        }
    }


    /* NE PAS OUBLIER : sinon on ne peut plus écrire dans le terminal */
    // Restore previous TTY settings
    tcsetattr(STDIN_FILENO, TCSANOW, &tty_opts_backup);

    printf("\n");

    return 0;
}