/*
** EPITECH PROJECT, 2021
** gestion_plantes.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void plante_six(list **gbl, game_object **mob)
{
    (*gbl)->nb_sun -= 0;
    (*gbl)->new_node_pos = (sfVector2f){(*gbl)->new_node_pos.x - 65,
    (*gbl)->new_node_pos.y - 60};
    *mob = create_object("./images/obstacle.png",
    (*gbl)->new_node_pos, (sfIntRect){0, 0, 33, 114});
    (*mob)->offset = 0;
    (*mob)->offset_origin = 0;
    (*mob)->offset_shoot = 0;
    (*mob)->animation_time = 0.01;
    (*mob)->can_action = 0.01;
    (*mob)->range = 50;
}

game_object *create_object_plante(list **gbl, int type_plante)
{
    game_object *mob = NULL;

    if (type_plante == 1)
        plante_one(gbl, &mob);
    if (type_plante == 2)
        plante_two(gbl, &mob);
    if (type_plante == 3)
        plante_three(gbl, &mob);
    if (type_plante == 4)
        plante_foor(gbl, &mob);
    if (type_plante == 5)
        plante_five(gbl, &mob);
    if (type_plante == 6)
        plante_six(gbl, &mob);
    mob->type_plante = type_plante;
    mob->clock_action = sfClock_create();
    return (mob);
}

l_list *add_to_list_plante(list **gbl, l_list **node, int type_plante)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL) return NULL;
    new->mob = create_object_plante(gbl, type_plante);
    new->lvl_up = create_object("./images/lvl_up.png",
    (sfVector2f){new->mob->pos.x + new->mob->rect.width / 2 + 10,
    new->mob->pos.y + new->mob->rect.height / 2}, (sfIntRect){0, 0, 22, 26});
    if (new->mob == NULL) return NULL;
    if ((*gbl)->first == NULL && (*gbl)->last == NULL) {
        (*gbl)->first = new;
        (*gbl)->last = new;
        new->next = NULL;
    } else {
        (*gbl)->first = new;
        new->next = *node;
        (*node)->previous = new;
    }
    new->previous = NULL;
    (*gbl)->max_node += 1;
    return (new);
}