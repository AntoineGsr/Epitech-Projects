/*
** EPITECH PROJECT, 2021
** entity_gestion.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

int check_acces_door(rpg_t *rpg_tab, tile_t *tile)
{
    if (rpg_tab->g->card->door_two == true && tile->id == 6990)
        return (0);
    if (rpg_tab->g->card->door_two == false && tile->id == 6990) {
        rpg_tab->g->can_open_door = tile->id;
        return (1);
    }
    if (rpg_tab->g->card->door_one == true && tile->id == 8081)
        return (0);
    if (rpg_tab->g->var->access_card == false && tile->id == 8081)
        return (1);
    if (rpg_tab->g->var->access_card == true && tile->id == 8081
    && rpg_tab->g->card->door_one == false) {
        rpg_tab->g->can_open_door = tile->id;
        return (1);
    }
    return (0);
}

void door_entity_close(rpg_t *rpg_tab, tile_t *tile)
{
    sfClock_restart(tile->tile->anim_clock);
    animate_door_close(&(tile->tile->sprite_rect), (sfVector3f)
    {-100 * rpg_tab->int_coeff, 0, -100}, rpg_tab);
    sfSprite_setTextureRect(tile->tile->sprite, tile->tile->
    sprite_rect);
}

void door_entity(rpg_t *rpg_tab, tile_t *tile)
{
    sfFloatRect action_range = (sfFloatRect)
    {tile->tile->sprite_pos.x - 100, tile->tile->sprite_pos.y - 100, 300, 300};

    if (sfFloatRect_intersects(&action_range, &(rpg_tab->g->perso->guy_hitbox),
    NULL) == sfTrue && check_acces_door(rpg_tab, tile) == 0) {
        tile->tile->anim_time = sfClock_getElapsedTime(tile->tile->anim_clock);
        if (tile->tile->anim_time.microseconds / 1000000.0 > 0.1) {
            sfClock_restart(tile->tile->anim_clock);
            animate_door_open(&(tile->tile->sprite_rect), (sfVector3f)
            {100 * rpg_tab->int_coeff, 600, 100}, rpg_tab);
            sfSprite_setTextureRect(tile->tile->sprite, tile->tile->
            sprite_rect);
        }
    } else {
        tile->tile->anim_time = sfClock_getElapsedTime(tile->tile->anim_clock);
        if (tile->tile->anim_time.microseconds / 1000000.0 > 0.1)
            door_entity_close(rpg_tab, tile);
    }
    change_door_hitbox(rpg_tab, tile);
}

void gestion_door(rpg_t *rpg_tab)
{
    rpg_tab->g->can_open_door = false;
    for (int i = 0; rpg_tab->g->all_tiles->upper_tiles[i] != NULL; i++) {
        for (int j = 0; rpg_tab->g->all_tiles->upper_tiles[i][j] != NULL; j++) {
            if (rpg_tab->g->all_tiles->upper_tiles[i][j]->tile_type == DOOR)
                door_entity(rpg_tab, rpg_tab->g->all_tiles->upper_tiles[i][j]);
        }
    }
}