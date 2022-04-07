/*
** EPITECH PROJECT, 2021
** display_funcs.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void display_lvl_up(list ***gbl, l_list ***node, sfRenderWindow *window,
int **val)
{
    sfSprite_setTexture((*node)[(*val)[1]]->lvl_up->sprite,
    (*node)[(*val)[1]]->lvl_up->texture, sfTrue);
    sfSprite_setTextureRect((*node)[(*val)[1]]->lvl_up->sprite,
    (*node)[(*val)[1]]->lvl_up->rect);
    sfSprite_setPosition((*node)[(*val)[1]]->lvl_up->sprite,
    (*node)[(*val)[1]]->lvl_up->pos);
    sfRenderWindow_drawSprite(window, (*node)[(*val)[1]]->lvl_up->sprite,
    NULL);
}

void display_node(list ***gbl, l_list ***node, sfRenderWindow *window,
int **val)
{
    sfSprite_setTexture((*node)[(*val)[1]]->mob->sprite,
    (*node)[(*val)[1]]->mob->texture, sfTrue);
    sfSprite_setTextureRect((*node)[(*val)[1]]->mob->sprite,
    (*node)[(*val)[1]]->mob->rect);
    sfSprite_setPosition((*node)[(*val)[1]]->mob->sprite,
    (*node)[(*val)[1]]->mob->pos);
    sfRenderWindow_drawSprite(window, (*node)[(*val)[1]]->mob->sprite,
    NULL);
}

void recursive_display(list ***gbl, l_list ***node, sfRenderWindow *window,
int **val)
{
    if ((*val)[0] < (*val)[2]) {
        display_node(gbl, node, window, val);
        if ((*val)[1] == 0 && (*node)[0]->mob->cost_lvl_up
            <= (*gbl)[(*val)[1]]->nb_sun
            && (*node)[(*val)[1]]->mob->type_plante == 2) {
            display_lvl_up(gbl, node, window, val);
        }
        (*node)[(*val)[1]] = (*node)[(*val)[1]]->next;
        (*val)[0] += 1;
        recursive_display(gbl, node, window, val);
    } else if ((*val)[1] < 2) {
        (*val)[0] = 0;
        (*val)[1] += 1;
        (*val)[2] = (*gbl)[(*val)[1]]->max_node;
        recursive_display(gbl, node, window, val);
    }
    return;
}

int display_game(list ***gbl, l_list ***node, enum pages *state,
sfRenderWindow *window)
{
    int *val = malloc(sizeof(int) * 3);

    if (*state >= GAME && *state < GAME_MENU_CLICK) {
        val[0] = 0;
        val[1] = 0;
        val[2] = (*gbl)[0]->max_node;
        recursive_display(gbl, node, window, &val);
        display_text(gbl, node, window, state);
        (*node)[0] = (*gbl)[0]->first;
        (*node)[1] = (*gbl)[1]->first;
        (*node)[2] = (*gbl)[2]->first;
    }
    free(val);
    return ((*gbl)[0]->nb_sun);
}