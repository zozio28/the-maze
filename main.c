#include <stdlib.h>
#include <stdio.h>
#include "maze.h"
#include "arrow.c"

int main() {

    char* mazeFile;
    printf("Choose your difficulty: \n");
    printf("1. Easy\n");
    printf("2. Medium\n");
    printf("3. Hard\n");

    int difficulty;
    scanf("%d", &difficulty);

    switch (difficulty) {
        case 1:
            mazeFile = "./levels/easyMaze.csv";
            break;
        case 2:
            mazeFile = "./levels/mediumMaze.csv";
            break;
        case 3:
            mazeFile = "./levels/hardMaze.csv";
            break;
        default:
            printf("Invalid difficulty. Please enter a valid difficulty.\n");
            return 1;
    }
    if (readCSV(mazeFile)) {
        printf("Maze loaded successfully!\n");

        // Add more logic based on your requirements

    } else {
        printf("Failed to load maze from file %s\n", mazeFile);
    }

    int move = differentMove();
    printf("Arrow function result: %d\n", move);

    return 0;
}