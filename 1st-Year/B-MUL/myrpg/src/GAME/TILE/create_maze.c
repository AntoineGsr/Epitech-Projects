/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../../include/my.h"

tile_t *create_tile_sprite_maze(rpg_t *rpg_tab, int xpos, int ypos,
sfVector2i tab_pos)
{
    tile_t *tmp = malloc(sizeof(tile_t));

    if (xpos == 42 && ypos == 42) {
        tmp->tile_type = VOID;
        tmp->tile = NULL;
    } else {
        tmp->tile = get_my_tile(rpg_tab, rpg_tab->g->all_tiles->tile_texture,
        (sfVector2f) {tab_pos.y * 100, tab_pos.x * 100}, (sfIntRect)
        {xpos, ypos, 100, 100});
        tmp->tile_type = rpg_tab->g->all_tiles->enum_save;
        tmp->x_tile = xpos;
        tmp->y_tile = ypos;
        differ_tile(rpg_tab, &tmp, xpos, ypos);
    } tmp->id = rpg_tab->g->entity_count;
    rpg_tab->g->entity_count++;
    return (tmp);
}

void create_tile_from_map_maze(rpg_t *rpg_tab,
sfVector2i tab_pos, char maze_char,
tile_t ****tiles)
{
    int xpos = 0;
    int ypos = 0;
    if (maze_char == '*') {
        xpos = 42;
        ypos = 42;
    } else if (maze_char == 'X') {
        ypos = 0;
        xpos = 500;
    }
    (*tiles)[tab_pos.x][tab_pos.y] =
    create_tile_sprite_maze(rpg_tab, xpos, ypos, tab_pos);
}

void create_maze(rpg_t *rpg_tab)
{
    int maze_x = 0;
    int maze_y = 0;
    for (int i = 9; i < 9 + 11; i++, maze_y++) {
        maze_x = 0;
        for (int j = 78; j < 78 + 11; j++, maze_x++) {
            create_tile_from_map_maze(rpg_tab, (sfVector2i) {i, j},
            rpg_tab->maze_dante[maze_y][maze_x], &(rpg_tab->g->all_tiles->
            wall_tiles));
        }
    }
}