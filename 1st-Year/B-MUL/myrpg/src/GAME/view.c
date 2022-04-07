/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void view_stat_handling(rpg_t *rpg_tab)
{
    rpg_tab->main_cam_pos = sfview_my_getpos(rpg_tab, rpg_tab->view);
    sfView_setCenter(rpg_tab->view, rpg_tab->g->perso->guy_center);
    sfRenderWindow_setView(rpg_tab->window, rpg_tab->view);
}