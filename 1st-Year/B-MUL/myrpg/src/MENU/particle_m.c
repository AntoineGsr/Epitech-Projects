/*
** EPITECH PROJECT, 2021
** parse_save.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void rewind_particle_m(rpg_t *rpg_tab)
{
    for (; rpg_tab->particles->m_particule->previous != NULL;
    rpg_tab->particles->m_particule =
    rpg_tab->particles->m_particule->previous);
}

one_particle_t *add_particle_m(rpg_t *rpg_tab, one_particle_t *part)
{
    one_particle_t *tmp = malloc(sizeof(one_particle_t));

    tmp->obj = malloc(sizeof(particle_obj_t));
    int ratio = 5 + rand() % 5;
    tmp->obj->box = (sfFloatRect) {rpg_tab->u->c_pos.x - 10 + rand() % 20,
    rpg_tab->u->c_pos.y - 10 + rand() % 20, ratio, ratio};
    tmp->obj->particle_state = PARTICLE_ON;
    tmp->next = part;
    tmp->previous = NULL;
    tmp->next->previous = tmp;
    return (tmp);
}

void show_particle_m(rpg_t *rpg_tab, sfFloatRect rect)
{
    sfRectangleShape *to_show = sfRectangleShape_create();

    sfRectangleShape_setSize(to_show, (sfVector2f) {rect.width, rect.height});
    sfRectangleShape_setPosition(to_show, (sfVector2f) {rect.left, rect.top});
    sfRenderWindow_drawRectangleShape(rpg_tab->window, to_show, NULL);
}

void particle_handling_m(rpg_t *rpg_tab)
{
    rewind_particle_m(rpg_tab);
    if (sfClock_getElapsedTime(rpg_tab->particles->m_refresh_clock)
    .microseconds / 1000000.0 > 0.01) {
        sfClock_restart(rpg_tab->particles->m_refresh_clock);
        rpg_tab->particles->m_particule = add_particle_m(rpg_tab,
        rpg_tab->particles->m_particule);
    }
    for (; rpg_tab->particles->m_particule->next != NULL;
    rpg_tab->particles->m_particule = rpg_tab->particles->m_particule->next) {
        rpg_tab->particles->m_particule->obj->box.top = rpg_tab->particles->
        m_particule->obj->box.top + ((rand() % 3) * 2) * rpg_tab->coeff;
        rpg_tab->particles->m_particule->obj->box.left = rpg_tab->particles->
        m_particule->obj->box.left - 3 + ((rand() % 6)) * rpg_tab->coeff;
        if (rpg_tab->particles->m_particule->obj->box.top > 1099) {
            rpg_tab->particles->m_particule->obj->particle_state = PARTICLE_OFF;
        } if (rpg_tab->particles->m_particule->obj->particle_state ==
        PARTICLE_ON) {
            show_particle_m(rpg_tab, rpg_tab->particles->m_particule->obj->box);
        }
    } rewind_particle_m(rpg_tab);
}