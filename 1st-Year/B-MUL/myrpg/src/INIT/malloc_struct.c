/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void malloc_struct_three(rpg_t *rpg_tab)
{
    rpg_tab->g->inventory = malloc(sizeof(inventory_t));
    rpg_tab->g->inventory->case_inv = malloc(sizeof(case_t) * 9);
    rpg_tab->g->inventory->stats = malloc(sizeof(stat_t));
    rpg_tab->g->stats = malloc(sizeof(stat_t));
    rpg_tab->g->drop_list = malloc(sizeof(list_t));
    rpg_tab->g->player_info = malloc(sizeof(player_info_t));
    rpg_tab->g->card = malloc(sizeof(access_card_t));
    rpg_tab->g->card->digit_number = malloc(sizeof(sprite_t) * 9);
    rpg_tab->g->bidon = malloc(sizeof(water_bidon_t));
    rpg_tab->g->bidon->bidon_layer = malloc(sizeof(sprite_t) * 3);
    rpg_tab->g->start_msg = malloc(sizeof(text_t) * 9);
    rpg_tab->eg = malloc(sizeof(end_game_t));
    rpg_tab->particles = malloc(sizeof(particles_t));
    rpg_tab->particles->m_particule = malloc(sizeof(one_particle_t));
    rpg_tab->particles->g_particule = malloc(sizeof(one_particle_t));
    rpg_tab->icons = malloc(sizeof(icon_t));
    rpg_tab->g->end_hitbox = malloc(sizeof(sfFloatRect) * 2);
    rpg_tab->g->mehdik_txt = malloc(sizeof(text_t) * 4);
    rpg_tab->g->statistics = malloc(sizeof(text_t) * 3);
}

void malloc_struct_two(rpg_t *rpg_tab)
{
    rpg_tab->m->s_butt = malloc(sizeof(menu_button_skin_t));
    rpg_tab->m->s_butt->button = malloc(sizeof(sprite_t) * 7);
    rpg_tab->m->s_butt->s_wind = malloc(sizeof(sprite_t) * 2);
    rpg_tab->m->s_butt->skin_rotate = malloc(sizeof(sprite_t));
    rpg_tab->g = malloc(sizeof(game_t));
    rpg_tab->keys = malloc(sizeof(keys_t));
    rpg_tab->g->all_tiles = malloc(sizeof(all_tiles_t));
    rpg_tab->g->var = malloc(sizeof(game_variables_t));
    rpg_tab->g->perso = malloc(sizeof(perso_t));
    rpg_tab->g->enemy = malloc(sizeof(enemy_t) * 35);
    rpg_tab->g->spawn_area = malloc(sizeof(spawn_area_t) * 7);
    rpg_tab->g->spawn_area_large = malloc(sizeof(spawn_area_t) * 3);
    rpg_tab->g->spawn_area_solo = malloc(sizeof(spawn_area_t) * 4);
    rpg_tab->g->spawn_area_end = malloc(sizeof(spawn_area_t) * 1);
    rpg_tab->g->perso->shoot_area = malloc(sizeof(shooting_area_t));
    rpg_tab->g->perso->shoot_area->north = malloc(sizeof(sfFloatRect) * 5);
    rpg_tab->g->perso->shoot_area->east = malloc(sizeof(sfFloatRect) * 5);
    rpg_tab->g->perso->shoot_area->south = malloc(sizeof(sfFloatRect) * 5);
    rpg_tab->g->perso->shoot_area->west = malloc(sizeof(sfFloatRect) * 5);
    rpg_tab->g->gunshot_list = malloc(sizeof(list_t));
}

void malloc_struct(rpg_t *rpg_tab)
{
    rpg_tab->config = malloc(sizeof(config_t));
    rpg_tab->m = malloc(sizeof(menu_t));
    rpg_tab->u = malloc(sizeof(util_t));
    rpg_tab->h = malloc(sizeof(help_t));
    rpg_tab->h->help_sprite = malloc(sizeof(sprite_t) * 2);
    rpg_tab->m->m_wind = malloc(sizeof(sprite_t) * 2);
    rpg_tab->m->m_butt = malloc(sizeof(menu_button_t));
    rpg_tab->m->m_butt->button = malloc(sizeof(sprite_t) * 6);
    rpg_tab->m->p_butt = malloc(sizeof(menu_button_param_t));
    rpg_tab->m->p_butt->button = malloc(sizeof(sprite_t) * 14);
    rpg_tab->m->p_butt->key = malloc(sizeof(text_t) * 9);
    rpg_tab->m->p_butt->p_wind = malloc(sizeof(sprite_t) * 3);
    rpg_tab->m->l_butt = malloc(sizeof(menu_button_load_t));
    rpg_tab->m->l_butt->button = malloc(sizeof(sprite_t) * 4);
    rpg_tab->m->l_butt->list = malloc(sizeof(list_t));
    malloc_struct_two(rpg_tab);
    malloc_struct_three(rpg_tab);
}