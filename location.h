#ifndef __LOCATION_H_
#define __LOCATION_H_

#define _XOPEN_SOURCE_EXTENDED

/**
 * @fn struct Location
 * @author Oïhana
 * @brief Structure representing a location with x and y coordinates.
 */
typedef struct Location
{
    int x;
    int y;
} Location;

/**
 * @fn struct LocationList
 * @author Oïhana
 * @brief Structure representing a list of locations.
 */
typedef struct LocationList
{
    int len;
    int capacity;
    Location *array;
} LocationList;

/**
 * @fn Location location_new(int x, int y)
 * @author Oïhana
 * @brief Initializes a new location with specified coordinates.
 * @param x The x-coordinate of the new location.
 * @param y The y-coordinate of the new location.
 */
Location location_new(int x, int y);

/**
 * @fn int location_eq(Location lo, Location other)
 * @author Alaïa
 * @brief Compare two Location structures for equality.
 * @param lo First Location to compare.
 * @param other Second Location to compare.
 */
int location_eq(Location lo, Location other);

/**
 * @fn void location_print_debug(Location lo)
 * @author Zoé
 * @brief Print the coordinates of a Location structure for debugging purposes.
 * @param lo Location to print.
 */
void location_print_debug(Location lo);

/**
 * @fn LocationList *location_list_new()
 * @author Oïhana
 * @brief Initializes a new location list.
 */
LocationList *location_list_new();

/**
 * @fn void location_list_destroy(LocationList *l)
 * @author Oïhana
 * @brief Destroys a location list.
 * @param l The location list to destroy.
 */
void location_list_destroy(LocationList *l);

/**
 * @fn void location_list_push(LocationList *l, Location lo)
 * @author Oïhana
 * @brief Extends the capacity of a location list.
 * @param l The location list to extend.
 * @param lo The location to add to the list.
 */
void location_list_push(LocationList *l, Location lo);

/**
 * @fn void location_list_print(LocationList *l)
 * @author Oïhana
 * @brief Prints the contents of a location list.
 * @param l The location list to print.
 */
void location_list_print(LocationList *l);

/**
 * @fn int location_list_contains(LocationList *l, Location lo)
 * @author Oïhana
 * @brief Searches if a location is contained in the list.
 * @param l The location list to search.
 * @param lo The location to search for.
 */
int location_list_contains(LocationList *l, Location lo);

/**
 * @fn LocationList *near_locations(Location lo, int bound_x, int bound_y)
 * @author Oïhana
 * @brief Finds neighboring locations within specified bounds.
 * @param lo The lair location .
 * @param bound_x The x-coordinate boundary of the maze.
 * @param bound_y The y-coordinate boundary of the maze.
 */
LocationList *near_locations(Location lo, int bound_x, int bound_y);

/**
 * @fn Location location_list_pop(LocationList *l)
 * @author Oïhana
 * @brief Removes and returns the last location from the list.
 * @param l The location list to pop from.
 */
Location location_list_pop(LocationList *l);

/**
 * @fn LocationList* location_list_reverse(LocationList* l)
 * @author Alaïa
 * @brief Reverse the order of elements in a LocationList.
 * @param l The original LocationList to be reversed.
 */
LocationList* location_list_reverse(LocationList* l);

/**
 * @fn Location location_list_random(LocationList* l)
 * @author Alaïa
 * @brief Get a random location from the given list.
 */
Location location_list_random(LocationList* l);

#endif