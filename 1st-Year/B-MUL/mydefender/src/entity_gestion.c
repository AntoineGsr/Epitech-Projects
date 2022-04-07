/*
** EPITECH PROJECT, 2021
** entity_gestion.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void entity_creation(list ***gbl, l_list ***node, game_object ***sprite,
enum pages *state)
{
    *state += 1;
    get_seed();
    for (int i = 0; i < (*gbl)[1]->nb_entity; i++)
        (*node)[1] = add_to_list_zombie(&(*gbl)[1], &(*node)[1], 1);
    if ((*gbl)[1]->nb_entity < 65)
        (*gbl)[1]->nb_entity += 5;
}

void plantes_board(list ***gbl, l_list ***node, game_object ***sprite,
enum pages *state)
{
    *state = GAME;
    (*gbl)[0]->new_node_pos = (*sprite)[20]->pos;
    if (build_plante(gbl, node, sprite) == 0) {
        (*node)[0] = add_to_list_plante(&(*gbl)[0], &(*node)[0],
        (*sprite)[0]->type_plante);
        if ((*sprite)[0]->type_plante == 6) {
            (*sprite)[19]->life = 0;
            (*sprite)[19]->pos = (*node)[0]->mob->pos;
        }
        (*node)[0]->pos_x_map = (*gbl)[0]->pos_x_map;
        (*node)[0]->pos_y_map = (*gbl)[0]->pos_y_map;
    }
}

void destroy_sound_back_menu(list ***gbl, l_list ***node, int i)
{
    if (i == 0) {
        sfSound_destroy((*node)[0]->mob->sound);
        sfSoundBuffer_destroy((*node)[0]->mob->soundbuffer);
    }
}

void destroy_entity_back_menu(list ***gbl, l_list ***node, enum pages *state)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < (*gbl)[i]->max_node; j++,
            (*node)[i] = (*node)[i]->next) {
            destroy_sound_back_menu(gbl, node, i);
            destroy_node_noloop(&(*gbl)[i], &(*node)[i], &j);
        }
        (*gbl)[i]->first = NULL;
        (*gbl)[i]->last = NULL;
        (*gbl)[i]->max_node = 0;
        (*gbl)[i]->load_save = 0;
        (*gbl)[i]->nb_entity = 5;
        (*gbl)[i]->nb_sun = 150;
        (*gbl)[i]->score = 0;
        (*gbl)[i]->first_creation = 0;
        (*gbl)[i]->life_house = 3;
        (*gbl)[i]->new_node_pos = (sfVector2f){0, 0};
        loop_map_game(&(*gbl)[i]);
    }
    *state = MOVE_BACK_MENU;
    (*gbl)[1]->nb_entity = 5;
}

void entity_gestion(list ***gbl, l_list ***node, game_object ***sprite,
enum pages *state)
{
    if (*state >= GAME_MENU_CLICK && *state < DESTROY_ENTITY) {
        pause_gestion(gbl, node);
        return;
    }
    if (*state == DESTROY_ENTITY) {
        destroy_entity_back_menu(gbl, node, state);
        return;
    }
    if (*state == ENTITY_CREATION)
        entity_creation(gbl, node, sprite, state);
    if (*state >= CARD_SUN_RELEASED && *state < CLICK_INGAME)
        plantes_board(gbl, node, sprite, state);
    if (*state == CLICK_INGAME)
        lvl_up_plante(gbl, node, sprite, state);
    if (*state >= GAME) {
        zombie_movement(gbl, node, sprite);
        animation_plante(gbl, node, sprite);
        projectils_movement(gbl, node, sprite);
    }
    game_lost(gbl, sprite, state);
}