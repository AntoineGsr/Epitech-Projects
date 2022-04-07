/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_particle(rpg_t *rpg_tab)
{
    rpg_tab->particles->m_refresh_clock = sfClock_create();
    rpg_tab->particles->m_particule->obj = malloc(sizeof(particle_obj_t));
    rpg_tab->particles->m_particule->previous = NULL;
    rpg_tab->particles->m_particule->next = NULL;

    rpg_tab->particles->g_refresh_clock = sfClock_create();
    rpg_tab->particles->g_particule->obj = malloc(sizeof(particle_obj_t));
    rpg_tab->particles->g_particule->previous = NULL;
    rpg_tab->particles->g_particule->next = NULL;
}