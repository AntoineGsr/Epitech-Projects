/*
** EPITECH PROJECT, 2021
** init_shoot_area.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_shoot_area_two(rpg_t *rpg_tab)
{
    rpg_tab->g->perso->shoot_area->south[0] = (sfFloatRect){0, 954, 357, 126};
    rpg_tab->g->perso->shoot_area->south[1] =
    (sfFloatRect){1563, 954, 357, 126};
    rpg_tab->g->perso->shoot_area->south[2] =
    (sfFloatRect){357, 637, 553, 443};
    rpg_tab->g->perso->shoot_area->south[3] =
    (sfFloatRect){1010, 637, 553, 443};
    rpg_tab->g->perso->shoot_area->south[4] =
    (sfFloatRect){910, 590, 100, 490};
    rpg_tab->g->perso->shoot_area->west[0] = (sfFloatRect){0, 126, 357, 317};
    rpg_tab->g->perso->shoot_area->west[1] = (sfFloatRect){0, 637, 357, 317};
    rpg_tab->g->perso->shoot_area->west[2] = (sfFloatRect){0, 443, 910, 47};
    rpg_tab->g->perso->shoot_area->west[3] = (sfFloatRect){0, 590, 910, 47};
    rpg_tab->g->perso->shoot_area->west[4] = (sfFloatRect){0, 490, 960, 100};
    rpg_tab->g->perso->shoot_area->east[0] = (sfFloatRect){1563, 126, 357, 317};
    rpg_tab->g->perso->shoot_area->east[1] = (sfFloatRect){1563, 637, 357, 317};
    rpg_tab->g->perso->shoot_area->east[2] = (sfFloatRect){1010, 443, 910, 47};
    rpg_tab->g->perso->shoot_area->east[3] = (sfFloatRect){1010, 590, 910, 47};
    rpg_tab->g->perso->shoot_area->east[4] = (sfFloatRect){960, 490, 960, 100};
}

void init_shoot_area(rpg_t *rpg_tab)
{
    rpg_tab->g->perso->shoot_area->north[0] = (sfFloatRect){0, 0, 357, 126};
    rpg_tab->g->perso->shoot_area->north[1] = (sfFloatRect){1563, 0, 357, 126};
    rpg_tab->g->perso->shoot_area->north[2] = (sfFloatRect){357, 0, 553, 443};
    rpg_tab->g->perso->shoot_area->north[3] = (sfFloatRect){1010, 0, 553, 443};
    rpg_tab->g->perso->shoot_area->north[4] = (sfFloatRect){910, 0, 100, 490};
    init_shoot_area_two(rpg_tab);
    rpg_tab->g->gunshot_list->first = NULL;
    rpg_tab->g->gunshot_list->nb_node = 0;
    rpg_tab->g->gunshot_list->previous_clock = 0;
    rpg_tab->g->perso->shoot_area->orientation_left = EAST_LEFT;
    rpg_tab->g->perso->shoot_area->orientation_top = EAST_TOP;
    rpg_tab->g->inventory->inventory = false;
    rpg_tab->g->can_grab = false;
    rpg_tab->g->grab_drop = false;
}