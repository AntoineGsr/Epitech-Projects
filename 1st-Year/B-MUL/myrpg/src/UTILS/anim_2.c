/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void animate_guy_ten(rpg_t *rpg_tab)
{
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    NORTH_LEFT)
        rpg_tab->g->gunshot_node->speed_bullet = (sfVector2f)
        {0, -650};
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    EAST_LEFT)
        rpg_tab->g->gunshot_node->speed_bullet = (sfVector2f)
        {650, 0};
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    SOUTH_LEFT)
        rpg_tab->g->gunshot_node->speed_bullet = (sfVector2f)
        {0, 650};
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    WEST_LEFT)
        rpg_tab->g->gunshot_node->speed_bullet = (sfVector2f)
        {-650, 0};
}

void animate_guy_nine(rpg_t *rpg_tab, sfIntRect *bullet)
{
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    NORTH_LEFT || rpg_tab->g->perso->shoot_area->orientation_left
    == SOUTH_LEFT) {
        (*bullet).width = 8;
        (*bullet).height = 20;
        (*bullet).top = 8;
    } rpg_tab->g->nb_bullet -= 1;
    rpg_tab->g->gunshot_node = add_node_firstpos
    (&rpg_tab->g->gunshot_list, &rpg_tab->g->gunshot_node);
    rpg_tab->g->gunshot_node->button = get_my_sprite
    (rpg_tab, "assets/png/util/firegun.png",
    (sfVector2f){rpg_tab->g->perso->guy->sprite_pos.x +
    rpg_tab->g->perso->shoot_area->orientation_left,
    rpg_tab->g->perso->guy->sprite_pos.y +
    rpg_tab->g->perso->shoot_area->orientation_top}, *bullet);
    rpg_tab->g->gunshot_node->hitbox_bullet = (sfFloatRect)
    {rpg_tab->g->gunshot_node->button->sprite_pos.x,
    rpg_tab->g->gunshot_node->button->sprite_pos.y,
    rpg_tab->g->perso->shoot_area->orientation_left,
    rpg_tab->g->perso->shoot_area->orientation_top};
}

void animate_guy_eight(rpg_t *rpg_tab, float seconds_weapon)
{
    if (rpg_tab->g->perso->shooting == true
    && rpg_tab->g->perso->target == true && rpg_tab->g->perso->weapon == 1
    && seconds_weapon > 0.04) {
        decal_rect_guy(&(rpg_tab->g->perso->guy->sprite_rect),
        rpg_tab->g->perso->guy->sprite_rect.width * rpg_tab->int_coeff,
        rpg_tab->g->perso->guy->sprite_rect.width * 5, 0);
        if (rpg_tab->g->perso->guy->sprite_rect.left == 300) {
            sfIntRect knife = (sfIntRect){0, 0, 10, 10};
            animate_guy_six(rpg_tab, knife);
            animate_guy_seven(rpg_tab, knife);
        }
        if (rpg_tab->g->perso->guy->sprite_rect.left >= 400) {
            rpg_tab->g->perso->shooting = false;
            rpg_tab->g->perso->guy->sprite_rect.left = 0;
        }
        sfClock_restart(rpg_tab->g->perso->weapon_clock);
    }
}

void animate_guy_seven(rpg_t *rpg_tab, sfIntRect knife)
{
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    NORTH_LEFT) {
        rpg_tab->g->gunshot_node->button = get_my_sprite
        (rpg_tab, "assets/png/util/knife.png",
        (sfVector2f){rpg_tab->g->perso->guy->sprite_pos.x + 73,
        rpg_tab->g->perso->guy->sprite_pos.y - 10}, knife);
    }
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    SOUTH_LEFT) {
        rpg_tab->g->gunshot_node->button = get_my_sprite
        (rpg_tab, "assets/png/util/knife.png",
        (sfVector2f){rpg_tab->g->perso->guy->sprite_pos.x + 23,
        rpg_tab->g->perso->guy->sprite_pos.y + 100}, knife);
    }
    rpg_tab->g->gunshot_node->hitbox_bullet = (sfFloatRect)
    {rpg_tab->g->gunshot_node->button->sprite_pos.x,
    rpg_tab->g->gunshot_node->button->sprite_pos.y,
    10, 10};
}

void animate_guy_six(rpg_t *rpg_tab, sfIntRect knife)
{
    rpg_tab->g->gunshot_node = add_node_firstpos
    (&rpg_tab->g->gunshot_list, &rpg_tab->g->gunshot_node);
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    EAST_LEFT) {
        rpg_tab->g->gunshot_node->button = get_my_sprite
        (rpg_tab, "assets/png/util/knife.png",
        (sfVector2f){rpg_tab->g->perso->guy->sprite_pos.x + 100,
        rpg_tab->g->perso->guy->sprite_pos.y + 50}, knife);
    }
    if (rpg_tab->g->perso->shoot_area->orientation_left ==
    WEST_LEFT) {
        rpg_tab->g->gunshot_node->button = get_my_sprite
        (rpg_tab, "assets/png/util/knife.png",
        (sfVector2f){rpg_tab->g->perso->guy->sprite_pos.x - 10,
        rpg_tab->g->perso->guy->sprite_pos.y + 50}, knife);
    }
}