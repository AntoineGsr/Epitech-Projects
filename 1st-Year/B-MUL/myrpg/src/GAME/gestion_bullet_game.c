/*
** EPITECH PROJECT, 2021
** gestion_bullet_game.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void kill_mob_del(rpg_t *rpg_tab, int i)
{
    if (rpg_tab->g->enemy[i]->hp <= 0) {
        rpg_tab->g->var->xp += 15;
        drop_item_mob_kill(rpg_tab, i);
        rpg_tab->g->enemy[i]->blop->sprite_pos =
        (sfVector2f){-1000, -1000};
        rpg_tab->g->enemy[i]->blop_hitbox =
        (sfFloatRect){-1000, -1000, 0, 0};
        rpg_tab->g->enemy[i]->blop->sprite_frect =
        (sfFloatRect){-1000, -1000, 0, 0};
        rpg_tab->g->enemy[i]->explosion =
        (sfFloatRect){-1000, -1000, 0, 0};
    }
}

void loop_weapon_one(rpg_t *rpg_tab)
{
    for (int i = 0; i < rpg_tab->g->nb_mob; i++) {
        if (sfFloatRect_intersects(&(rpg_tab->g->gunshot_node->hitbox_bullet),
        &((sfFloatRect)
        {rpg_tab->g->enemy[i]->blop_hitbox.left,
        rpg_tab->g->enemy[i]->blop_hitbox.top - 50,
        rpg_tab->g->enemy[i]->blop_hitbox.width,
        rpg_tab->g->enemy[i]->blop_hitbox.height + 50}),
        NULL) == sfTrue && rpg_tab->g->enemy[i]->hp > 0) {
            rpg_tab->g->enemy[i]->hp -= rpg_tab->g->var->cut_dmg;
            kill_mob_del(rpg_tab, i);
            break;
        }
    }
}

void weapon_one(rpg_t *rpg_tab)
{
    int destroyed = 0;

    if (rpg_tab->g->gunshot_list->nb_node > 0) {
        loop_weapon_one(rpg_tab);
        destroy_node_noloop(&rpg_tab->g->gunshot_list,
        &rpg_tab->g->gunshot_node, &destroyed);
    }
}

void weapon_two(rpg_t *rpg_tab)
{
    int destroyed = 0;

    for (int j = 0; j < rpg_tab->g->gunshot_list->nb_node; j++,
    rpg_tab->g->gunshot_node = rpg_tab->g->gunshot_node->next) {
        j = weapon_two_wall(rpg_tab, j, &destroyed);
        if (destroyed == 1)
            continue;
        weapon_two_mob(rpg_tab, j);
    }
    rpg_tab->g->gunshot_node = rpg_tab->g->gunshot_list->first;
}

void gestion_bullet(rpg_t *rpg_tab)
{
    if (rpg_tab->g->perso->weapon == 1) {
        weapon_one(rpg_tab);
        return;
    }
    move_bullet(rpg_tab);
    weapon_two(rpg_tab);
}