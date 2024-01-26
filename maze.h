#ifndef __maze_H_
#define __maze_H_

#define _XOPEN_SOURCE_EXTENDED

#include "location.h"
#include "player.h"

/**
 * @fn struct TileKind
 * @author Zoé
 * @brief Enumeration representing the type of tile.
 */
typedef enum TileKind
{
    WALL = -1,
    EMPTY = 0,
    BEGIN = 1,
    END = 2,
    POTION = 10,
    DIAMOND = 12,
    STAR = 13,
    TELEPORTATION = 20,
    EXPLOSION = 21,
    TORNADO = 30,

} TileKind;

/**
 * @fn struct TileList
 * @author Zoé
 * @brief Structure representing a list of tiles.
 */
typedef struct TileList
{
    int len;
    int capacity;
    TileKind *array;
} TileList;

/**
 * @fn struct BuildMaze
 * @author Zoé
 * @brief Structure to build the maze.
 */
typedef struct BuildMaze
{
    int len;
    int capacity;
    TileList **array;
} BuildMaze;

/**
 * @fn struct Maze
 * @author Zoé
 * @brief Structure representing the maze.
 */
typedef struct Maze
{
    Location begin;
    Location end;
    TileKind **maze;
    int x_len;
    int y_len;
} Maze;

/**
 * @fn void tile_print(TileKind t)
 * @author Zoé
 * @brief Converts a TileKind to a string representation.
 * @param t The TileKind to convert.
 */
char *tile_to_string(TileKind t);

/**
 * @fn Maze *readCSV(char *fileMaze)
 * @author Zoé
 * @brief read a file in CSV format
 * @param fileMaze the file to read
 */
// Maze *readCSV(char *fileMaze);

/**
 * @fn TileList *tile_list_new()
 * @author Zoé
 * @brief Initializes a new tile list.
 */
TileList *tile_list_new();

/**
 * @fn void tile_list_destroy(TileList *l)
 * @author Zoé
 * @brief Destroys a tile list.
 * @param l The TileList to destroy.
 */
void tile_list_destroy(TileList *l);

/**
 * @fn void tile_list_push(TileList *l, TileKind t)
 * @author Zoé
 * @brief Extends the capacity of a tile list.
 * @param l The TileList to extend.
 * @param t The TileKind to add to the list.
 */
void tile_list_push(TileList *l, TileKind t);

/**
 * @fn void tile_list_push(TileList *l, TileKind t)
 * @author Zoé
 * @brief Prints the contents of a tile list.
 * @param l The TileList to print.
 */
void tile_list_print(TileList *l);

/**
 * @fn BuildMaze *build_maze_new()
 * @author Zoé
 * @brief Initializes a new maze.
 */
BuildMaze *build_maze_new();

void build_maze_destroy(BuildMaze *l);

void build_maze_add_tile(BuildMaze *l, TileKind t);

void build_maze_next_line(BuildMaze *l);

TileKind** build_maze_build(BuildMaze *l);

Location find_tile(TileKind** t, int x_len, int y_len, TileKind tile, char* err);

Location find_begin(TileKind** t, int x_len, int y_len);

Location find_end(TileKind** t, int x_len, int y_len);

Maze* maze_from_csv(char* path);

void maze_print_debug(TileKind** t, int x_len, int y_len);

Maze* maze_from_csv(char* path);

void maze_destroy(Maze* m);

/**
 * @fn void print_maze(Maze* m, Player p)
 * @author Oïhana
 * @brief Print the maze in the middle.
 * @param m The maze we want to print.
 * @param p The player.
 */
void print_maze(Maze* m, Player p );

void print_maze_resolved(Maze* m);

void maze_put_potions(Maze* m);

#endif