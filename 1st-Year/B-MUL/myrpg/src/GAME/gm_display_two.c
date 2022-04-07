/*
** EPITECH PROJECT, 2021
** gm_display_two.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void gm_six(rpg_t *rpg_tab)
{
    game_stat_refresh(rpg_tab);
    game_stat_refresh_inventory(rpg_tab);
    game_stat_refresh_mob(rpg_tab);
    game_stat_refresh_shoot_area(rpg_tab);
    game_stat_refresh_door(rpg_tab);
    game_stat_refresh_water(rpg_tab);
    sfSprite_setPosition(rpg_tab->g->perso->guy->sprite,
    rpg_tab->g->perso->guy->sprite_pos);
    sfSprite_setTextureRect(rpg_tab->g->perso->guy->sprite,
    rpg_tab->g->perso->guy->sprite_rect);
    sfSprite_setPosition(rpg_tab->g->space_sprite->sprite,
    (sfVector2f){sfView_getCenter(rpg_tab->view).x -
    sfView_getSize(rpg_tab->view).x / 2, sfView_getCenter(rpg_tab->view).y
    - sfView_getSize(rpg_tab->view).y / 2});
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->g->space_sprite->sprite, NULL);
    display_tiles(rpg_tab);
    particle_handling_g(rpg_tab);
    zoom_maze_handling(rpg_tab);
}

void gm_sv(rpg_t *rpg_tab)
{
    for (int i = 0; i < rpg_tab->g->drop_list->nb_node; i++,
    rpg_tab->g->drop_node = rpg_tab->g->drop_node->next) {
        sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->
        drop_node->button->sprite, NULL);
    }
    rpg_tab->g->drop_node = rpg_tab->g->drop_list->first;
    for (int i = 0; i < rpg_tab->g->nb_mob; i++) {
        if (rpg_tab->g->enemy[i]->hp > 0) {
            sfSprite_setTextureRect(rpg_tab->g->enemy[i]->blop->sprite,
            rpg_tab->g->enemy[i]->blop->sprite_rect);
            sfSprite_setPosition(rpg_tab->g->enemy[i]->blop->sprite,
            rpg_tab->g->enemy[i]->blop->sprite_pos);
            sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->
            enemy[i]->blop->sprite, NULL);
        }
    }
    sfSprite_setPosition(rpg_tab->g->captain->sprite,
    (sfVector2f){363, 1322});
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->
    captain->sprite, NULL);
}

void gm_eg(rpg_t *rpg_tab)
{
    gm_six(rpg_tab);
    gm_sv(rpg_tab);
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->g->perso->guy->sprite, NULL);
    sfSprite_setPosition(rpg_tab->g->mehdik->sprite,
    (sfVector2f){2272, 1408});
    sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->mehdik->sprite,
    NULL);
    for (int i = 0; i < rpg_tab->g->gunshot_list->nb_node; i++,
    rpg_tab->g->gunshot_node = rpg_tab->g->gunshot_node->next) {
        sfSprite_setTextureRect(rpg_tab->g->gunshot_node->button->sprite,
        rpg_tab->g->gunshot_node->button->sprite_rect);
        sfSprite_setPosition(rpg_tab->g->gunshot_node->button->sprite,
        rpg_tab->g->gunshot_node->button->sprite_pos);
        sfRenderWindow_drawSprite(rpg_tab->window, rpg_tab->g->
        gunshot_node->button->sprite, NULL);
    }
    rpg_tab->g->gunshot_node = rpg_tab->g->gunshot_list->first;
}

void gm_nince(rpg_t *rpg_tab)
{
    if (rpg_tab->g->can_grab == true) {
        animate_text(rpg_tab, rpg_tab->g->drop_msg, 15,
        (int [3]){25, 127, 35});
        sfText_setPosition(rpg_tab->g->drop_msg->text,
        sfRenderWindow_mapPixelToCoords
        (rpg_tab->window, (sfVector2i)
        {coeff_window(rpg_tab->window_size.x, 830, 1920),
        coeff_window(rpg_tab->window_size.y, 950, 1080)}, rpg_tab->view));
        sfText_setString(rpg_tab->g->drop_msg->text,
        rpg_tab->g->drop_msg->ctrl);
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->g->drop_msg->text, NULL);
    }
}

void gm_ten(rpg_t *rpg_tab)
{
    if ((rpg_tab->g->can_open_door != false
    || (rpg_tab->g->can_talk_mehdik == true
    && rpg_tab->g->talk_mehdik == false)
    || rpg_tab->g->can_end_game == true) && rpg_tab->g->can_grab == false) {
        animate_text(rpg_tab, rpg_tab->g->door_msg, 15, (int [3]){25, 127, 35});
        sfText_setPosition(rpg_tab->g->door_msg->text,
        sfRenderWindow_mapPixelToCoords
        (rpg_tab->window, (sfVector2i)
        {coeff_window(rpg_tab->window_size.x, 805, 1920),
        coeff_window(rpg_tab->window_size.y, 950, 1080)}, rpg_tab->view));
        sfText_setString(rpg_tab->g->door_msg->text,
        rpg_tab->g->door_msg->ctrl);
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->g->door_msg->text, NULL);
    }
}