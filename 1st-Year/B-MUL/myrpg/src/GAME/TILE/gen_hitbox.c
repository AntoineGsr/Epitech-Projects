/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../../include/my.h"

sfFloatRect create_hitbox_single_tile(rpg_t *rpg_tab, tile_t *tiles)
{
    sfFloatRect rect = (sfFloatRect)
    {tiles->tile->sprite_pos.x, tiles->tile->sprite_pos.y, 100, 100};
    if (tiles->x_tile == 0 && tiles->y_tile == 600) {
        rect.width = 30;
        rect.left += 35;
    } if (tiles->x_tile == 0 && tiles->y_tile == 700) {
        rect.height = 70;
        rect.top += 17;
    } return (rect);
}

void gen_hitbox_tile_two(rpg_t *rpg_tab, int *count)
{
    for (int i = 0; rpg_tab->g->all_tiles->wall_tiles[i] != NULL; i++) {
        for (int j = 0; rpg_tab->g->all_tiles->wall_tiles[i][j] != NULL; j++) {
            if (rpg_tab->g->all_tiles->wall_tiles[i][j]->tile_type != VOID) {
                rpg_tab->g->hitbox_tile[*count] = malloc(sizeof(hitbox_tile_t));
                rpg_tab->g->hitbox_tile[*count]->hitbox =
                create_hitbox_single_tile(rpg_tab, rpg_tab->g->
                all_tiles->wall_tiles[i][j]);
                rpg_tab->g->hitbox_tile[*count]->hitbox_saved = rpg_tab->g->
                hitbox_tile[*count]->hitbox;
                rpg_tab->g->hitbox_tile[*count]->x_tile = rpg_tab->g->all_tiles
                ->wall_tiles[i][j]->x_tile;
                rpg_tab->g->hitbox_tile[*count]->y_tile = rpg_tab->g->all_tiles
                ->wall_tiles[i][j]->y_tile;
                rpg_tab->g->hitbox_tile[*count]->id = rpg_tab->g->all_tiles->
                wall_tiles[i][j]->id;
                (*count)++;
            }
        }
    } rpg_tab->g->hitbox_tile[*count] = NULL;
}

void gen_hitbox_tile_three(rpg_t *rpg_tab, int count, int i, int j)
{
    rpg_tab->g->hitbox_tile[count] = malloc(sizeof(hitbox_tile_t));
    rpg_tab->g->hitbox_tile[count]->hitbox =
    create_hitbox_single_tile(rpg_tab, rpg_tab->g->
    all_tiles->upper_tiles[i][j]);
    rpg_tab->g->hitbox_tile[count]->hitbox_saved = rpg_tab->g->
    hitbox_tile[count]->hitbox;
    rpg_tab->g->hitbox_tile[count]->x_tile = rpg_tab->g->all_tiles->
    upper_tiles[i][j]->x_tile;
    rpg_tab->g->hitbox_tile[count]->y_tile = rpg_tab->g->all_tiles->
    upper_tiles[i][j]->y_tile;
    rpg_tab->g->hitbox_tile[count]->id = rpg_tab->g->all_tiles->
    upper_tiles[i][j]->id;
}

void gen_hitbox_tile(rpg_t *rpg_tab)
{
    int count = 0;
    rpg_tab->g->hitbox_tile = malloc(sizeof(hitbox_tile_t *) * (rpg_tab->g->
    all_tiles->map_width * rpg_tab->g->all_tiles->map_height * 3 + 1));
    for (int i = 0; rpg_tab->g->all_tiles->upper_tiles[i] != NULL; i++) {
        for (int j = 0; rpg_tab->g->all_tiles->upper_tiles[i][j] != NULL; j++) {
            if (rpg_tab->g->all_tiles->upper_tiles[i][j]->tile_type != VOID &&
            rpg_tab->g->all_tiles->upper_tiles[i][j]->tile_type == DOOR) {
                gen_hitbox_tile_three(rpg_tab, count, i, j);
                count++;
            }
        }
    } gen_hitbox_tile_two(rpg_tab, &count);
}