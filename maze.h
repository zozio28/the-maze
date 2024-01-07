#ifndef MAZE_H
#define MAZE_H

/**
 * @file maze.h
 * @brief Header file defining structures and functions for a maze.
 */

/**
 * @struct Player
 * @brief Structure representing a player.
 */
typedef struct Player {
    char* name;
    int character;
    int hp;
} Player;

/**
 * @struct Square
 * @brief Structure representing a square in the maze.
 */
typedef struct Square {
    int value;
    struct Square* sLeft;
    struct Square* sRight;
    struct Square* sUp;
    struct Square* sDown;
} Square;

/**
 * @typedef Maze
 * @brief Typedefinition for a pointer to Square, representing a Maze.
 */
typedef struct Square* Maze;

/**
 * @fn Maze createMaze(int value);
 * @brief Create a maze node with the given value.
 * @param value The value of the node.
 * @return A pointer to the newly created maze node.
 */
Maze createMaze(int value);

/**
 * @fn void emptyBuffer(void);
 * @brief Empty the buffer by consuming any remaining characters.
 */
void emptyBuffer(void);

#endif // MAZE_H
