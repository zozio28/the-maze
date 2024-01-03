#ifndef __maze_H_
#define __maze_H_

/**
 * @fn struct player
 * @author Alaïa
 * @brief structure for a player
 */
typedef struct player{
    char* name;
    int character;
    int hp;
}player;

/**
 * @fn struct square
 * @author Alaïa
 * @brief structure for a square
 */
typedef struct square{
    int value;
    struct square* sLeft;
    struct square* sRight;
    struct square* sUp;
    struct square* sDown;
}square;

typedef struct square* Maze;

typedef struct {
    square* beginning;
}square;

/**
 * @fn Maze createMaze(int value,Maze sLeft,Maze sRight,Maze sUp,Maze sDown)
 * @author Zoé
 * @brief create the maze
 * @param value the value of the node
 * @param sLeft the left son
 * @param sRight the right son
 * @param sUp the son above
 * @param sDown the bottom son
 */
Maze createMaze(int value); //,Maze sLeft,Maze sRight,Maze sUp,Maze sDown);

#endif