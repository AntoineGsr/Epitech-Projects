/*
** EPITECH PROJECT, 2021
** gestion_zombies.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

game_object *create_object_zombie(list **gbl, int random)
{
    game_object *mob = malloc(sizeof(game_object));
    int rand_y = rand() % 5;
    float coord_y_zombie[5] = {17, 147, 281, 400, 523};

    if (random == 1) {
        mob = create_object("./images/zombie_classic.png",
        (sfVector2f){(rand() % (2000 + 1 - 1400)) + 1400,
        coord_y_zombie[rand_y]}, (sfIntRect){0, 0, 152, 196});
        mob->speed_x = 20;
        mob->speed_y = 20;
        mob->offset = 1064;
        mob->animation_time = 0.1;
        mob->can_action = 0.5;
        mob->range = 10;
        mob->life = 10;
    }
    mob->clock_action = sfClock_create();
    return (mob);
}

l_list *add_to_list_zombie(list **gbl, l_list **node, int random)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL) return NULL;
    new->mob = create_object_zombie(gbl, random);
    new->lvl_up = NULL;
    if (new->mob == NULL) return NULL;
    if ((*gbl)->first == NULL && (*gbl)->last == NULL) {
        (*gbl)->first = new;
        (*gbl)->last = new;
        new->previous = NULL;
        new->next = NULL;
    } else {
        (*gbl)->first = new;
        new->next = *node;
        new->previous = NULL;
        (*node)->previous = new;
    }
    (*gbl)->max_node += 1;
    return (new);
}