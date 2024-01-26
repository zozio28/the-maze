#ifndef __tree_H_
#define __tree_H_
#include "maze.h"

#define _XOPEN_SOURCE_EXTENDED

/**
 * @fn struct Node
 * @author Alaïa
 * @brief Struct representing a node in a maze.
 */
typedef struct Node
{
    Location value;
    struct Node *sLeft;
    struct Node *sRight;
    struct Node *sUp;
    struct Node *sDown;
} Node;

typedef Node* Tree;

/**
 * @fn Node* node_new(Location lo)
 * @author Alaïa
 * @brief Creates new node.
 * @param lo The location to search for.
 */
Node* node_new(Location lo);

/**
 * @fn Tree* tree_from_maze(Maze* m)
 * @author Alaïa
 * @brief Creates a tree from a maze.
 * @param m the maze.
 */
Tree* tree_from_maze(Maze* m);

/**
 * @fn void tree_explore_maze(Node* node, Maze* m, LocationList* sawed)
 * @author Alaïa
 * @brief Explores the four locations near our location
 * @param node the node of our tree.
 * @param m the maze.
 * @param sawed the locations we've sawed.
 */
void tree_explore_maze(Node* node, Maze* m, LocationList* sawed);

/**
 * @fn Node* tree_explore_maze_expand(Location lo, Maze* m, LocationList* sawed)
 * @author Alaïa
 * @brief Is it a wall ? Do we sawed ?
 * @param lo the location
 * @param m the maze
 * @param sawed the locations we've sawed.
 */
Node* tree_explore_maze_expand(Location lo, Maze* m, LocationList* sawed);

/**
 * @fn void tree_destroy(Tree* t)
 * @author Alaïa
 * @brief Destroy our tree 
 * @param t the tree
 */
void tree_destroy(Tree* t);

/**
 * @fn void tree_destroy_expand(Node* n)
 * @author Alaïa
 * @brief Destroy each node of our tree
 * @param n the nodes
 */
void tree_destroy_expand(Node* n);

/**
 * @fn int node_number(Node* n)
 * @author Alaïa
 * @brief Return the number of nodes
 * @param n the nodes.
 */
int node_number(Node* n);

/**
 * @fn void tree_reduce(Tree* t)
 * @author Alaïa
 * @brief Reduce our tree
 * @param t the three.
 */
void tree_reduce(Tree* t);

/**
 * @fn Node* tree_reduce_expand(Node* n)
 * @author Alaïa
 * @brief Destroy tree node
 * @param n the nodes
 */
Node* tree_reduce_expand(Node* n);

/**
 * @fn LocationList* tree_best_path(Tree* t, Location end)
 * @author Alaïa
 * @brief Return the location list of locations for the best path
 * @param t the tree
 * @param end the end of the maze
 */
LocationList* tree_best_path(Tree* t, Location end);

/**
 * @fn int tree_best_path_expand(Node* n, LocationList* l, Location end)
 * @author Alaïa
 * @brief Find de best path from a node
 * @param n the nodes
 * @param l the location list
 * @param end the end of the maze 
 */
int tree_best_path_expand(Node* n, LocationList* l, Location end);

/**
 * @fn LocationList* tree_collect_locations(Tree* t)
 * @author Alaïa
 * @brief Collect all locations from the given tree.
 * @param t The tree to collect locations from.
 */
LocationList* tree_collect_locations(Tree* t);

/**
 * @fn LocationList* tree_collect_locations(Tree* t)
 * @author Alaïa
 * @brief Helper function to recursively expand and collect locations from a tree node.
 * @param n The node to expand and collect locations from.
 * @param l The LocationList to collect locations into.
 */
void tree_collect_locations_expand(Node* n, LocationList* l);

/**
 * @fn void tree_print_debug(Node* n)
 * @author Alaïa
 * @brief print a tree
 * @param n the nodes
 */
void tree_print_debug(Node* n);


#endif