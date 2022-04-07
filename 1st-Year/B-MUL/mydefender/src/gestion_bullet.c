/*
** EPITECH PROJECT, 2021
** gestion_bullet.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void bullet_plante_style(list **gbl, int type_plante, sfVector2f pos,
game_object **mob)
{
    if (type_plante == 2 || type_plante == 12) {
        *mob = create_object("./images/green_bullet.png",
        (sfVector2f){pos.x + 80, pos.y + 16}, (sfIntRect){0, 0, 30, 30});
        (*mob)->damage = type_plante % 7;
        (*mob)->speed_x = 300;
        (*mob)->type_plante = type_plante;
    }
    if (type_plante == 5) {
        *mob = create_object("./images/blue_bullet.png",
        (sfVector2f){pos.x + 95, pos.y + 14}, (sfIntRect){0, 0, 63, 33});
        (*mob)->damage = 3;
        (*mob)->speed_x = 350;
        (*mob)->type_plante = type_plante;
    }
}

game_object *create_object_bullet(list **gbl, int type_plante, sfVector2f pos)
{
    game_object *mob = malloc(sizeof(game_object));
    float second = 0;

    bullet_plante_style(gbl, type_plante, pos, &mob);
    if (type_plante == 3) {
        mob = create_object("./images/empty_bullet.png",
        (sfVector2f){pos.x + 160, pos.y + 11}, (sfIntRect){0, 0, 30, 30});
        mob->damage = 50;
        mob->speed_x = 0;
        mob->type_plante = type_plante;
    }
    if (type_plante == 4) {
        mob = create_object("./images/empty_bullet.png",
        (sfVector2f){pos.x + 80, pos.y - 64}, (sfIntRect){0, 0, 30, 30});
        mob->damage = 50;
        mob->speed_x = 0;
        mob->type_plante = type_plante;
    }
    return (mob);
}

void add_to_list_bullet_style(list **gbl, l_list ***node)
{
    (*gbl)->max_node += 1;
    (*node)[0]->mob->have_to_shoot = 0;
    sfClock_restart((*node)[0]->mob->clock_action);
}

l_list *add_to_list_bullet(list **gbl, l_list ***node)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL) return NULL;
    new->mob = create_object_bullet(gbl, (*node)[0]->mob->type_plante,
    (*node)[0]->mob->pos);
    if ((*node)[0]->mob->type_plante == 4)
        (*node)[0]->mob->rect = (sfIntRect){0,
        (*node)[0]->mob->rect.height, 98, 80};
    if (new->mob == NULL) return NULL;
    if ((*gbl)->first == NULL && (*gbl)->last == NULL) {
        (*gbl)->last = new;
        new->next = NULL;
    } else {
        new->next = (*node)[2];
        (*node)[2]->previous = new;
    }
    (*gbl)->first = new;
    new->previous = NULL;
    add_to_list_bullet_style(gbl, node);
    return (new);
}