/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../../include/my.h"

void icon_handling(rpg_t *rpg_tab)
{
    if (sfClock_getElapsedTime(rpg_tab->icons->icon_clock).microseconds
    / 1000000.0 > 0.5) {
        sfClock_restart(rpg_tab->icons->icon_clock);
        rpg_tab->icons->index++;
        if (rpg_tab->icons->index >= 11)
            rpg_tab->icons->index = 0;
        sfRenderWindow_setIcon(rpg_tab->window, 216, 216,
        sfImage_getPixelsPtr(rpg_tab->icons->icon[rpg_tab->icons->index]));
    }
}