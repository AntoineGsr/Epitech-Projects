/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include "../../include/my.h"

void check_guy_drop_two(rpg_t *rpg_tab)
{
    if (rpg_tab->g->drop_list->nb_node == 0)
        rpg_tab->g->can_grab = false;
}

void check_guy_drop(rpg_t *rpg_tab)
{
    check_guy_drop_two(rpg_tab);
    for (int i = 0; i < rpg_tab->g->drop_list->nb_node; i++,
    rpg_tab->g->drop_node = rpg_tab->g->drop_node->next) {
        if (sfFloatRect_intersects(&(rpg_tab->g->drop_node->hitbox_bullet),
        &(rpg_tab->g->perso->guy_hitbox), NULL) == sfTrue) {
            rpg_tab->g->can_grab = true;
            if (my_strcmp(SMALL_BIDON, rpg_tab->g->drop_node->type_drop) == 0
            && rpg_tab->g->water_done == false) {
                rpg_tab->g->can_grab_water = true;
                break;
            } if (rpg_tab->g->grab_drop == true
            && add_inventory(rpg_tab) == 1) {
                destroy_node_noloop(&rpg_tab->g->drop_list,
                &rpg_tab->g->drop_node, &i);
                rpg_tab->g->grab_drop = false;
                rpg_tab->g->can_grab = false;
            } break;
        } rpg_tab->g->can_grab = false;
        rpg_tab->g->can_grab_water = false;
    } rpg_tab->g->drop_node = rpg_tab->g->drop_list->first;
}

void check_guy_hit_wall(rpg_t *rpg_tab, sfVector2f previous_pos)
{
    game_stat_refresh(rpg_tab);
    for (int i = 0; rpg_tab->g->hitbox_tile[i] != NULL; i++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->perso->guy_hitbox),
        &(rpg_tab->g->hitbox_tile[i]->hitbox), NULL) == sfTrue) {
            rpg_tab->g->perso->guy->sprite_pos.x = previous_pos.x;
            rpg_tab->g->perso->guy->sprite_pos.y = previous_pos.y;
            sfSprite_setPosition(rpg_tab->g->perso->guy->sprite,
            rpg_tab->g->perso->guy->sprite_pos);
            rpg_tab->g->perso->hit = 1;
            break;
        }
        rpg_tab->g->perso->hit = 0;
    }
}

void show_hitbox(rpg_t *rpg_tab, sfFloatRect rect)
{
    sfRectangleShape *to_show = sfRectangleShape_create();

    sfRectangleShape_setSize(to_show, (sfVector2f) {rect.width, rect.height});
    sfRectangleShape_setPosition(to_show, (sfVector2f) {rect.left, rect.top});
    sfRenderWindow_drawRectangleShape(rpg_tab->window, to_show, NULL);
}