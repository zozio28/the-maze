#define _XOPEN_SOURCE_EXTENDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "location.h"

Location location_new(int x, int y)
{
    Location lo;
    lo.x = x;
    lo.y = y;

    return lo;
}

int location_eq(Location lo, Location other){
    return (lo.x==other.x && lo.y==other.y);
}

void location_print_debug(Location lo)
{
    printf("[%d, %d]", lo.x, lo.y);
}

LocationList *location_list_new()
{
    LocationList *new = malloc(sizeof(LocationList));
    new->len = 0;
    new->capacity = 4;
    new->array = malloc(sizeof(Location) * new->capacity);

    return new;
}

void location_list_destroy(LocationList *l)
{
    free(l->array);
    free(l);
}

void location_list_push(LocationList *l, Location lo)
{
    if (l->capacity == l->len)
    {
        l->capacity = l->capacity * 2;
        l->array = realloc(l->array, l->capacity*sizeof(Location));
    }

    l->array[l->len] = lo;
    l->len++;
}

void location_list_print(LocationList *l)
{
    for (int i = 0; i < l->len; i++)
        printf("[%d, %d] ", l->array[i].x, l->array[i].y);

    printf("\n");
}

int location_list_contains(LocationList *l, Location lo)
{
    for (int i = 0; i < l->len; i++)
    {
        if (lo.x == l->array[i].x && lo.y == l->array[i].y)
            return 1;
    }

    return 0;
}

LocationList *near_locations(Location lo, int bound_x, int bound_y)
{
    LocationList *list = location_list_new();

    if (lo.x != 0)
    {
        location_list_push(list, location_new(lo.x - 1, lo.y));
    }

    if (lo.y != 0)
    {
        location_list_push(list, location_new(lo.x, lo.y - 1));
    }

    if (lo.x != bound_x - 1)
    {
        location_list_push(list, location_new(lo.x + 1, lo.y));
    }

    if (lo.y != bound_y - 1)
    {
        location_list_push(list, location_new(lo.x, lo.y + 1));
    }

    return list;
}

Location location_list_pop(LocationList *l)
{
    Location lo;
    lo = l->array[l->len - 1];
    l->len--;

    return lo;
}

LocationList* location_list_reverse(LocationList* l){
    LocationList* res = location_list_new();
    int len = l->len;

    for(int i=0; i<len; i++)
        location_list_push(res,location_list_pop(l));

    free(l);
    return res;
}

Location location_list_random(LocationList* l) {
    srand(time(NULL));

    return l->array[rand() % l->len];
}