/*
** EPITECH PROJECT, 2020
** create_list.c
** File description:
** lib_antoine_gasser
*/

#include "../include/../include/my_defender.h"

void loop_map_game(list **gbl)
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 5; j++) {
            (*gbl)->map[i][j] = 0;
        }
    }
}

list *create_global_list(game_object **sprite)
{
    list *gbl = malloc(sizeof(list));

    if (gbl == NULL) return NULL;
    gbl->first = NULL;
    gbl->last = NULL;
    gbl->max_node = 0;
    gbl->load_save = 0;
    gbl->nb_entity = 5;
    gbl->nb_sun = 150;
    gbl->score = 0;
    gbl->first_creation = 0;
    gbl->life_house = 3;
    gbl->new_node_pos = (sfVector2f){0, 0};
    gbl->map = malloc(sizeof(int *) * 9);
    for (int i = 0; i < 9; i++)
        gbl->map[i] = malloc(sizeof(int) * 5);
    loop_map_game(&gbl);
    return (gbl);
}