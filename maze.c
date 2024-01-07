#include <stdlib.h>
#include <stdio.h>
#include "maze.h"
#include <unistd.h>
#include <termios.h>
#include <string.h>

#define N 1000

// Global variables
int playerRow, playerCol;
int maze[N][N];

// Function prototypes
Maze createMaze(int value);
int readCSV(char* fileMaze);
void emptyBuffer(void);
void printMaze(void);
int differentMove(void);

// createMaze function
Maze createMaze(int value) {
    Maze new = malloc(sizeof(Square));
    new->value = value;
    new->sLeft = NULL;
    new->sRight = NULL;
    new->sUp = NULL;
    new->sDown = NULL;
    return new;
}
// readCSV function
int readCSV(char* fileMaze) {
    char line[N];
    int row = 0, col = 0;

    FILE* mazeFile = fopen(fileMaze, "r");
    Maze medium = NULL;

    if (mazeFile != NULL) {
        while (fgets(line, N, mazeFile) != NULL) {
            char* token = strtok(line, ";");
            while (token != NULL) {
                int value = atoi(token);
                Maze new = createMaze(value);

                if (row > 0) {
                    Maze upper = medium;
                    for (int i = 0; i < row - 1; i++) {
                        upper = upper->sDown;
                    }
                    if (upper != NULL) {
                        new->sUp = upper->sRight;
                        upper->sRight = new;
                    }
                }

                if (col > 0) {
                    Maze leftNode = medium;
                    for (int i = 0; i < col - 1; i++) {
                        leftNode = leftNode->sRight;
                    }
                    leftNode->sLeft = new;
                }

                if (row == 0 && col == 0) {
                    medium = new;
                }

                token = strtok(NULL, ";");
                col++;
            }

            row++;
            col = 0;
        }

        fclose(mazeFile);
        return 1;
    } else {
        printf("Le fichier %s n'existe pas.\n", fileMaze);
        return 0;
    }
}

// printMaze function
void printMaze(void) {
    // Implement the logic to print the maze
    // You may use the global 'maze' array to access the maze data
}

// emptyBuffer function
void emptyBuffer(void) {
    char c;
    while (((c = getchar()) != '\n') && (c != EOF));
}

// differentMove function
int differentMove(void) {
    struct termios tty_opts_backup, tty_opts_raw;
    char c;
    int pastermine = 1;

    // Get the current position of the player
    int row = playerRow;
    int col = playerCol;

    // Back up current TTY settings
    tcgetattr(STDIN_FILENO, &tty_opts_backup);

    // Change TTY settings mode
    cfmakeraw(&tty_opts_raw);
    tcsetattr(STDIN_FILENO, TCSANOW, &tty_opts_raw);

    // Prompt the user to enter a move
    printf("Enter a letter to move (z: top, q: left, d: right, s: bottom, x: quit): ");
    while (pastermine) {
        // Read the user's input
        c = getchar();

        // Validate the user's input
        if (c != 'z' && c != 'q' && c != 'd' && c != 's' && c != 'x') {
            printf("Invalid move. Please enter a valid move.\n");
            continue;
        }

        // Move the player based on the user's input
        switch (c) {
            case 'z': // top
                if (row > 0) {
                    row--;
                }
                break;
            case 'q': // left
                if (col > 0) {
                    col--;
                }
                break;
            case 'd': // right
                if (col < N - 1) {
                    col++;
                }
                break;
            case 's': // bottom
                if (row < N - 1) {
                    row++;
                }
                break;
            case 'x': // quit
                pastermine = 0;
                break;
        }
    }

    // Update the global playerRow and playerCol variables
    playerRow = row;
    playerCol = col;

    // Restore the original TTY settings
    tcsetattr(STDIN_FILENO, TCSANOW, &tty_opts_backup);

    printf("\n");

    return 0;
}

int main() {
    // Example usage
    char mazeFile[] = "your_maze_file.csv";
    if (readCSV(mazeFile)) {
        // Set initial player position (assuming it's valid)
        playerRow = 0;
        playerCol = 0;

        // Game loop
        while (1) {
            // Print the current state of the maze
            printMaze();

            // Get user input and move the player
            differentMove();

            // Check game-over conditions, e.g., exit the loop if needed
            // Add your logic here

            // Optional: Add a delay or clear screen to make it visually appealing
            // Example:
            // usleep(50000); // 50 milliseconds
            // system("clear"); // For Unix-like systems
        }
    }

    return 0;
}
