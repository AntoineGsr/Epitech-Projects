/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void zoom_maze_handling(rpg_t *rpg_tab)
{
    if (sfFloatRect_intersects(&(rpg_tab->g->perso->guy_hitbox),
    &(rpg_tab->g->zoom_reach), NULL) == sfTrue) {
        sfView_setSize(rpg_tab->view, (sfVector2f) {1920 * 0.5, 1080 * 0.5});
    } else {
        sfView_setSize(rpg_tab->view, (sfVector2f) {1920, 1080});
    }
}