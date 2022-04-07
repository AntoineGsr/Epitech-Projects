/*
** EPITECH PROJECT, 2021
** create_sapwn_area.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void create_spawn_area(rpg_t *rpg_tab)
{
    for (int i = 0; i < 7; i++)
        rpg_tab->g->spawn_area[i] = malloc(sizeof(spawn_area_t));
    rpg_tab->g->spawn_area[0]->area_pos_top = (sfVector2f) {1391, 1247};
    rpg_tab->g->spawn_area[0]->area_pos_bottom = (sfVector2f) {1616, 1402};
    rpg_tab->g->spawn_area[1]->area_pos_top = (sfVector2f) {3083, 1259};
    rpg_tab->g->spawn_area[1]->area_pos_bottom = (sfVector2f) {3338, 1505};
    rpg_tab->g->spawn_area[2]->area_pos_top = (sfVector2f) {1389, 172};
    rpg_tab->g->spawn_area[2]->area_pos_bottom = (sfVector2f) {1708, 493};
    rpg_tab->g->spawn_area[3]->area_pos_top = (sfVector2f) {2477, 154};
    rpg_tab->g->spawn_area[3]->area_pos_bottom = (sfVector2f) {2829, 431};
    rpg_tab->g->spawn_area[4]->area_pos_top = (sfVector2f) {1383, 767};
    rpg_tab->g->spawn_area[4]->area_pos_bottom = (sfVector2f) {1615, 934};
    rpg_tab->g->spawn_area[5]->area_pos_top = (sfVector2f) {1882, 1161};
    rpg_tab->g->spawn_area[5]->area_pos_bottom = (sfVector2f) {2021, 1498};
    rpg_tab->g->spawn_area[6]->area_pos_top = (sfVector2f) {2907, 345};
    rpg_tab->g->spawn_area[6]->area_pos_bottom = (sfVector2f) {3095, 603};
}

void create_spawn_area_large(rpg_t *rpg_tab)
{
    for (int i = 0; i < 3; i++)
        rpg_tab->g->spawn_area_large[i] = malloc(sizeof(spawn_area_t));
    rpg_tab->g->spawn_area_large[0]->area_pos_top = (sfVector2f)
    {5256, 1208};
    rpg_tab->g->spawn_area_large[0]->area_pos_bottom = (sfVector2f)
    {5751, 1647};
    rpg_tab->g->spawn_area_large[1]->area_pos_top = (sfVector2f)
    {12212, 1029};
    rpg_tab->g->spawn_area_large[1]->area_pos_bottom = (sfVector2f)
    {13091, 1188};
    rpg_tab->g->spawn_area_large[2]->area_pos_top = (sfVector2f)
    {12126, 1656};
    rpg_tab->g->spawn_area_large[2]->area_pos_bottom = (sfVector2f)
    {13093, 1794};
}

void create_spawn_area_solo(rpg_t *rpg_tab)
{
    for (int i = 0; i < 4; i++)
        rpg_tab->g->spawn_area_solo[i] = malloc(sizeof(spawn_area_t));
    rpg_tab->g->spawn_area_solo[0]->area_pos_top =
    (sfVector2f) {6659, 1965};
    rpg_tab->g->spawn_area_solo[0]->area_pos_bottom =
    (sfVector2f) {6788, 2053};
    rpg_tab->g->spawn_area_solo[1]->area_pos_top =
    (sfVector2f) {6242, 2358};
    rpg_tab->g->spawn_area_solo[1]->area_pos_bottom =
    (sfVector2f) {6387, 2427};
    rpg_tab->g->spawn_area_solo[2]->area_pos_top =
    (sfVector2f) {6237, 335};
    rpg_tab->g->spawn_area_solo[2]->area_pos_bottom =
    (sfVector2f) {6397, 485};
    rpg_tab->g->spawn_area_solo[3]->area_pos_top =
    (sfVector2f) {6616, 718};
    rpg_tab->g->spawn_area_solo[3]->area_pos_bottom =
    (sfVector2f) {6786, 900};
}

void create_spawn_area_end(rpg_t *rpg_tab)
{
    for (int i = 0; i < 1; i++)
        rpg_tab->g->spawn_area_end[i] = malloc(sizeof(spawn_area_t));
    rpg_tab->g->spawn_area_end[0]->area_pos_top = (sfVector2f) {14441, 1040};
    rpg_tab->g->spawn_area_end[0]->area_pos_bottom = (sfVector2f) {14972, 1778};
}

sfVector2f spawn_blop(rpg_t *rpg_tab, int i, spawn_area_t **spawn_area,
int mod)
{
    sfVector2f pos_area = (sfVector2f) {0, 0};
    int coeff_x = spawn_area[i % mod]->area_pos_bottom.x
    - spawn_area[i % mod]->area_pos_top.x;
    int coeff_y = spawn_area[i % mod]->area_pos_bottom.y
    - spawn_area[i % mod]->area_pos_top.y;

    pos_area.x = (float) (rand() % coeff_x)
    + spawn_area[i % mod]->area_pos_top.x;
    pos_area.y = (float) (rand() % coeff_y)
    + spawn_area[i % mod]->area_pos_top.y;
    return (pos_area);
}