#ifndef __player_H_
#define __player_H_

#define _XOPEN_SOURCE_EXTENDED

#include "location.h"
#include "maze.h"

/**
 * @fn struct Player
 * @author Alaïa
 * @brief Structure representing a player in the game.
 */
typedef struct Player
{
    char name[1002];
    char file[1002];
    int character;
    int hp;
    int diamonds;
    Location lo;
    int characters_table[12];
} Player;

/**
 * @fn struct Character
 * @author Oïhana
 * @brief Enumeration representing different characters in the game.
 */
typedef enum Character
{
    HELIANUX = 0,
    FOX = 1,
    FAIRY = 2,
    DINO = 3,
    GENIUS = 4,
    BUTTERFLY = 5,
    GHOST = 6,
    SANTA = 7,
    PATRICK = 8,
    RABBIT = 9,
    FARMER =10,
    MARIO = 11,
} Character;

/**
 * @fn char *character_to_string(Character ch)
 * @author Oïhana
 * @brief Converts a Character to a string representation.
 * @param ch The Character to convert.
 */
char *character_to_string(Character ch);

/**
 * @fn Player player_new(Location lo)
 * @author Oïhana
 * @brief Initialise a new player
 * @param lo location of the player
 */
Player player_new(Location lo);

/**
 * @fn void player_status_line(Player p)
 * @author Alaïa
 * @brief Display the player's status line.
 * @param p The player whose status is to be displayed.
 */
void player_status_line(Player p);

#endif
