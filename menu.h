#ifndef __menu_H_
#define __menu_H_

#include "game.h"

/**
 * @fn void printf_center(const char *text[], int text_lines)
 * @author Zoé
 * @brief Print a message at the center of the screen.
 * @param text Array of strings to print.
 * @param text_lines Number of lines in the array.
 */
void printf_center(const char *text[], int text_lines);

/**
 * @fn void home_page()
 * @author Zoé
 * @brief Print the name of the game at the start of the program.
 */
void home_page();

/**
 * @fn void end_page(int language)
 * @author Zoé
 * @brief Print the end of the game at the end of the program.
 * @param language The language selected for the game.
 */
void end_page(int language);

/**
 * @fn void shop_page(int language)
 * @author Zoé
 * @brief Print the shop page.
 * @param language The language selected for the game.
 */
void shop_page(int language);

/**
 * @fn int game_menu(Game* g)
 * @author Zoé
 * @brief Print the modes at the start.
 * @param g Game elements.
 */
int game_menu(Game* g);

/**
 * @fn char* check_box(int i)
 * @author Zoé
 * @brief Get the checkbox symbol based on the given condition.
 * @param i The condition to determine the checkbox symbol.
 */
char* check_box(int i);

/**
 * @fn void check_box_print(int i, char* car)
 * @author Zoé
 * @brief Print a line with a checkbox symbol and additional text.
 * @param i The condition to determine the checkbox symbol.
 * @param car Additional text to be printed.
 */
void check_box_print(int i, char* car);

/**
 * @fn * @fn void settings_page(Game g)
 * @author Zoé
 * @brief Print the settings modes to select.
 * @param g Game elements.
 */
void settings_page(Game* g);

/**
 * @fn * @fn void table_character(char *table, int size)
 * @author Zoé
 * @brief Fill an array with consecutive ASCII character codes.
 * @param table The array to be filled with character codes.
 * @param size The size of the array.
 */
void table_character(char *table, int size);

/**
 * @fn void print_shop(Setting settings)
 * @author Zoé
 * @brief Print the shop interface.
 * @param settings Settings elements.
 */
void print_shop(Game* g);

/**
 * @fn void init_bool_table(int* table)
 * @author Zoé
 * @brief Initialize a boolean array with the first element set to true and the rest to false.
 * @param table The boolean array to be initialized.
 */
void init_bool_table(int* table);

/**
 * @fn int bool_table(Player player,int i)
 * @author Zoé
 * @brief Set a specific element of the boolean array to true.
 * @param player The Player structure containing the boolean array.
 * @param i The index of the element to be set to true.
 */
int bool_table(Player player,int i);

/**
 * @fn void table_diamonds(int *table, int size)
 * @author Zoé
 * @brief Fill an array with a sequence of values (2 * index + 10).
 * @param table The array to be filled with values.
 * @param size The size of the array.
 */
void table_diamonds(int *table, int size);

/**
 * @fn void ask_buy(Game* g)
 * @author Zoé
 * @brief Ask the player if they want to buy a character.
 * @param g The Game structure containing player information.
 */
void ask_buy(Game* g);

/**
 * @fn void buy_character(Game* g)
 * @author Zoé
 * @brief Allow the player to buy a character.
 * @param g The Game structure containing player information.
 */
void buy_character(Game* g);

/**
 * @fn int ask(char text[],int min,int max)
 * @author Oïhana
 * @brief Prompt the player to input a value within a specified range.
 * @param text The message to display to the player.
 * @param min The minimum allowed value.
 * @param max The maximum allowed value.
 */
int ask(char text[],int min,int max);

/**
 * @fn char* ask_level()
 * @author Oïhana
 * @brief Ask the player to choose a difficulty level.
 */
char* ask_level();

/**
 * @fn char* ask_level_easy()
 * @author Oïhana
 * @brief Ask the player to choose a maze from the "Easy" difficulty level.
 */
char* ask_level_easy();

/**
 * @fn char* ask_level_easy()
 * @author Oïhana
 * @brief Ask the player to choose a maze from the "Medium" difficulty level.
 */
char* ask_level_medium();

/**
 * @fn char* ask_level_easy()
 * @author Oïhana
 * @brief Ask the player to choose a maze from the "Hard" difficulty level.
 */
char* ask_level_hard();

/**
 * @fn char* ask_level_easy()
 * @author Oïhana
 * @brief Ask the player to choose a maze from the "Extra Hard" difficulty level.
 */
char* ask_level_extra_hard();

/**
 * @fn char* ask_level_easy()
 * @author Oïhana
 * @brief Ask the player to choose a maze from the "Only for Genius" difficulty level.
 */
char* ask_level_genius();

#endif