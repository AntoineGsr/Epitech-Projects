/*
** EPITECH PROJECT, 2021
** gestion_bullet_game_nd.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

int weapon_two_mob(rpg_t *rpg_tab, int j)
{
    for (int i = 0; i < rpg_tab->g->nb_mob; i++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->gunshot_node->hitbox_bullet),
        &((sfFloatRect)
        {rpg_tab->g->enemy[i]->blop_hitbox.left,
        rpg_tab->g->enemy[i]->blop_hitbox.top - 50,
        rpg_tab->g->enemy[i]->blop_hitbox.width,
        rpg_tab->g->enemy[i]->blop_hitbox.height + 50}),
        NULL) == sfTrue && rpg_tab->g->enemy[i]->hp > 0) {
            destroy_node_noloop(&rpg_tab->g->gunshot_list,
            &rpg_tab->g->gunshot_node, &j);
            rpg_tab->g->enemy[i]->hp -= rpg_tab->g->var->gun_dmg;
            if (rpg_tab->g->enemy[i]->hp <= 0) {
                rpg_tab->g->var->xp += 15;
                drop_item_mob_kill(rpg_tab, i);
                kill_mob_del(rpg_tab, i);
            }
            break;
        }
    }
    return (j);
}

int weapon_two_wall(rpg_t *rpg_tab, int j, int *destroyed)
{
    for (int i = 0; rpg_tab->g->hitbox_tile[i] != NULL; i++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->gunshot_node->hitbox_bullet),
        &(rpg_tab->g->hitbox_tile[i]->hitbox), NULL) == sfTrue) {
            destroy_node_noloop(&rpg_tab->g->gunshot_list,
            &rpg_tab->g->gunshot_node, &j);
            *destroyed = 1;
            break;
        }
    }
    return (j);
}