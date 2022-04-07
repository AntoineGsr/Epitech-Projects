/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../../include/my.h"

int get_x_pos_for_tile(rpg_t *rpg_tab, sfVector2i tab_pos, char ***tab_char)
{
    int to_return = 0;
    char *str = tab_char[tab_pos.x][tab_pos.y];

    str = my_strcpy(str, str+1);
    to_return = my_getnbr(str);
    return (to_return);
}

sprite_t *get_my_tile(rpg_t *rpg_tab, sfTexture *texture,
sfVector2f sprite_pos, sfIntRect sprite_rect)
{
    sprite_t *obj = malloc(sizeof(sprite_t));

    obj->sprite = sfSprite_create();
    obj->texture = texture;
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->sprite_pos = sprite_pos;
    sfSprite_setPosition(obj->sprite, obj->sprite_pos);
    obj->sprite_rect = sprite_rect;
    sfSprite_setTextureRect(obj->sprite, obj->sprite_rect);
    obj->anim_clock = sfClock_create();
    return (obj);
}

void differ_tile(rpg_t *rpg_tab, tile_t **tmp, int xpos, int ypos)
{
    if (xpos == 0 && ypos == 600) {
        (*tmp)->tile_type = DOOR;
    } if (xpos == 0 && ypos == 700) {
        (*tmp)->tile_type = DOOR;
    }
}

tile_t *create_tile_sprite(rpg_t *rpg_tab, int xpos, int ypos,
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

void create_tile_from_map(rpg_t *rpg_tab, sfVector2i tab_pos, char ***tab_char,
tile_t ****tiles)
{
    int xpos = 0;
    int ypos = 0;

    if (tab_char[tab_pos.x][tab_pos.y][0] == '.') {
        xpos = 42;
        ypos = 42;
    } else {
        ypos = (tab_char[tab_pos.x][tab_pos.y][0] - 'A') * 100;
        xpos = (get_x_pos_for_tile(rpg_tab, tab_pos, tab_char) - 1) * 100;
    }
    (*tiles)[tab_pos.x][tab_pos.y] = create_tile_sprite
    (rpg_tab, xpos, ypos, tab_pos);
}