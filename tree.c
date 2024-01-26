#define _XOPEN_SOURCE_EXTENDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "location.h"
#include "tree.h"


Node* node_new(Location lo)
{
    Node* new = malloc(sizeof(Node));

    new->value = lo;
    new->sLeft = NULL;
    new->sRight = NULL;
    new->sUp = NULL;
    new->sDown = NULL;
    return new;
}

Tree* tree_from_maze(Maze* m){
    Tree* res = malloc(sizeof(Node*));
    LocationList* sawed=location_list_new();
    *res=node_new(m->begin);
    location_list_push(sawed,m->begin);

    tree_explore_maze(*res,m,sawed);

    location_list_destroy(sawed);

    return res;
}

void tree_explore_maze(Node* node, Maze* m, LocationList* sawed){

    if (node->value.x != 0)
    {
        node->sLeft = tree_explore_maze_expand(location_new(node->value.x - 1, node->value.y), m, sawed);
    }

    if (node->value.y != 0)
    {
        node->sUp=tree_explore_maze_expand(location_new(node->value.x, node->value.y - 1),m, sawed);
    }

    if (node->value.x != m->x_len - 1)
    {
        node->sRight=tree_explore_maze_expand(location_new(node->value.x + 1, node->value.y),m,sawed);
    }

    if (node->value.y != m->y_len - 1)
    {
        node->sDown=tree_explore_maze_expand(location_new(node->value.x, node->value.y + 1),m,sawed);
    }
}

Node* tree_explore_maze_expand(Location lo, Maze* m, LocationList* sawed) {
    Node* res;

    if(location_list_contains(sawed,lo)){
        return NULL;
    }
    
    location_list_push(sawed, lo);

    if(m->maze[lo.y][lo.x]==WALL){
        return NULL;
    }

    res=node_new(lo);
    if(m->maze[lo.y][lo.x]!=END){
        tree_explore_maze(res,m,sawed);
    }

    return res;
}

void tree_destroy(Tree* t){
    tree_destroy_expand(*t);
    free(t);
}

void tree_destroy_expand(Node* n){
    if(n->sLeft != NULL)
        tree_destroy_expand(n->sLeft);

    if(n->sRight != NULL)
        tree_destroy_expand(n->sRight);

    if(n->sUp != NULL)
        tree_destroy_expand(n->sUp);

    if(n->sDown != NULL)
        tree_destroy_expand(n->sDown);

    free(n);
}

int node_number(Node* n){
    int res=0;

    if(n->sLeft != NULL)
        res++;

    if(n->sRight != NULL)
        res++;

    if(n->sUp != NULL)
        res++;

    if(n->sDown != NULL)
        res++;

    return res;
}

void tree_reduce(Tree* t){
    *t=tree_reduce_expand(*t);
}

Node* tree_reduce_expand(Node* n){
    Node* res;

    if(n->sLeft != NULL){
        n->sLeft=tree_reduce_expand(n->sLeft);
        res=n->sLeft;
    }    

    if(n->sRight != NULL){
        n->sRight=tree_reduce_expand(n->sRight);
        res=n->sRight;
    }

    if(n->sUp != NULL){
        n->sUp=tree_reduce_expand(n->sUp);
        res=n->sUp;
    }
        
    if(n->sDown != NULL){
        n->sDown=tree_reduce_expand(n->sDown);
        res=n->sDown;
    }
        
    if(node_number(n) != 1)
        return n;

    free(n);
    return res;
}

LocationList* tree_best_path(Tree* t, Location end){
    LocationList* res = location_list_new();
    
    tree_best_path_expand(*t,res,end);

    return location_list_reverse(res);
}

int tree_best_path_expand(Node* n, LocationList* l, Location end){
    int res = 0;

    if (location_eq(n->value, end)){
        location_list_push(l,end);
        return 1;
    }

    if(n->sLeft != NULL && tree_best_path_expand(n->sLeft,l,end)) 
        res = 1;

    if(n->sRight != NULL && tree_best_path_expand(n->sRight,l,end))
        res = 1;

    if(n->sUp != NULL && tree_best_path_expand(n->sUp,l,end))
        res = 1;

    if(n->sDown != NULL && tree_best_path_expand(n->sDown,l,end)) 
        res = 1;

    if(res)
        location_list_push(l,n->value);

    return res;
}

LocationList* tree_collect_locations(Tree* t) {
    LocationList* res = location_list_new();

    tree_collect_locations_expand(*t,res);

    return res;
}

void tree_collect_locations_expand(Node* n, LocationList* l) {
    location_list_push(l,n->value);

    if(n->sLeft != NULL)
        tree_collect_locations_expand(n->sLeft,l);

    if(n->sRight != NULL)
        tree_collect_locations_expand(n->sRight,l);

    if(n->sUp != NULL)
        tree_collect_locations_expand(n->sUp,l);

    if(n->sDown != NULL)
        tree_collect_locations_expand(n->sDown,l);
}


void tree_print_debug(Node* n){
    location_print_debug(n->value);
    printf("\n");

    if(n->sLeft != NULL)
        tree_print_debug(n->sLeft);

    if(n->sRight != NULL)
        tree_print_debug(n->sRight);

    if(n->sUp != NULL)
        tree_print_debug(n->sUp);

    if(n->sDown != NULL)
        tree_print_debug(n->sDown);
}

