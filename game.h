#ifndef __game_H_
#define __game_H_

#define _XOPEN_SOURCE_EXTENDED

#include "maze.h"
#include "player.h"
#include "location.h"


/**
 * @fn struct Mode
 * @author Zoé
 * @brief Enumeration representing different modes of the game.
 */
typedef enum Mode
{
    NORMAL = 50,
    OBJECT = 51,
    CHEAT = 52, 
} Mode;

/**
 * @fn struct Setting
 * @author Zoé
 * @brief Structure for the settings of the game.
 */
struct Setting
{
    int language; // 1=anglais 2=français
    int mode;
};
typedef struct Setting Setting;

/**
 * @fn struct Game
 * @author Zoé
 * @brief Structure representing the game table.
 */
typedef struct Game
{
    Maze *maze;
    Player player;
    Setting settings;
    int game_over;
} Game;

/**
 * @fn Game game_new();
 * @author Zoé
 * @brief Initialize the settings game.
 */
Game game_new();

/**
 * @fn void save_game(Game g)
 * @author Zoé
 * @brief Save the current game state to a file.
 * @param g Game elements.
 */
void save_game(Game g);

/**
 * @fn void save_game(Game g)
 * @author Zoé
 * @brief Check if reading from the save file is successful.
 */
int succeed_read();

/**
 * @fn void read_save(Game* g)
 * @author Zoé
 * @brief Read the saved game state from a file and initialize the game.
 * @param g Game elements.
 */
void read_save(Game* g);

/**
 * @fn void ask_save(Game g)
 * @author Zoé
 * @brief Ask the player if they want to save the game.
 * @param g Game elements.
 */
void ask_save(Game g);

/**
 * @fn void game_run(Game* g, int new_game)
 * @author Zoé & Alaïa & Oïhana
 * @brief Run the game loop.
 * @param g Game elements.
 * @param new_game Flag indicating whether it's a new game.
 */
void game_run(Game* g, int new_game);

/**
 * @fn int game_input(Game* g, WINDOW *w, int reverse_keys)
 * @author Alaïa
 * @brief Handle player input during the game.
 * @param g Game elements.
 * @param w Game window
 * @param reverse_keys Flag indicating whether keys should be reversed.
 */
int game_input(Game* g, WINDOW *w, int reverse_keys);

/**
 * @fn int pause_menu(Game* g)
 * @author Oïhana
 * @brief Display and handle the pause menu
 * @param g Game elements.
 */
int pause_menu(Game* g);

/**
 * @fn void game_handle_potions(Game* g, int* reverse_keys)
 * @author Alaïa
 * @brief Handle potion effects in the game.
 * @param g Game elements.
 * @param reverse_keys Flag indicating whether keys should be reversed.
 */
void game_handle_potions(Game* g, int* reverse_keys);

/**
 * @fn void select_character(Game* g);
 * @author Zoé
 * @brief Allows you to select a character
 * @param g Game elements.
 */
void select_character(Game* g);

#endif