/*
** EPITECH PROJECT, 2021
** move_entity.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void rewind_particle_g(rpg_t *rpg_tab)
{
    for (; rpg_tab->particles->g_particule->previous != NULL;
    rpg_tab->particles->g_particule =
    rpg_tab->particles->g_particule->previous);
}

one_particle_t *add_particle_g(rpg_t *rpg_tab, one_particle_t *part)
{
    one_particle_t *tmp = malloc(sizeof(one_particle_t));

    tmp->obj = malloc(sizeof(particle_obj_t));
    int ratio = 5 + rand() % 5;
    tmp->obj->box = (sfFloatRect) {5980 + rand() % 140, 1060, ratio, ratio};
    int rando = rand() % 3;
    if (rando == 0) {
        tmp->obj->color = sfCyan;
    } else if (rando == 1) {
        tmp->obj->color = sfBlue;
    } else {
        tmp->obj->color = sfMagenta;
    }
    tmp->obj->particle_state = PARTICLE_ON;
    tmp->next = part;
    tmp->previous = NULL;
    tmp->next->previous = tmp;
    return (tmp);
}

void show_particle_g(rpg_t *rpg_tab, sfFloatRect rect, sfColor color)
{
    sfRectangleShape *to_show = sfRectangleShape_create();

    sfRectangleShape_setSize(to_show, (sfVector2f) {rect.width, rect.height});
    sfRectangleShape_setPosition(to_show, (sfVector2f) {rect.left, rect.top});
    sfRectangleShape_setFillColor(to_show, color);
    sfRenderWindow_drawRectangleShape(rpg_tab->window, to_show, NULL);
}

void particle_hand_g_loop(rpg_t *rpg_tab)
{
    for (; rpg_tab->particles->g_particule->next != NULL;
    rpg_tab->particles->g_particule = rpg_tab->particles->g_particule->next) {
        rpg_tab->particles->g_particule->obj->box.top = rpg_tab->particles->
        g_particule->obj->box.top + ((rand() % 3) * 2) * rpg_tab->coeff;
        if (rpg_tab->particles->g_particule->obj->box.top > 1797) {
            rpg_tab->particles->g_particule->obj->
            particle_state = PARTICLE_OFF;
        } if (rpg_tab->particles->g_particule->obj->
        particle_state == PARTICLE_ON) {
            show_particle_g(rpg_tab, rpg_tab->particles->g_particule->
            obj->box, rpg_tab->particles->g_particule->obj->color);
        }
    }
}

void particle_handling_g(rpg_t *rpg_tab)
{
    rewind_particle_g(rpg_tab);
    if (sfClock_getElapsedTime
    (rpg_tab->particles->g_refresh_clock).microseconds / 1000000.0 > 0.01) {
        sfClock_restart(rpg_tab->particles->g_refresh_clock);
        rpg_tab->particles->g_particule = add_particle_g(rpg_tab,
        rpg_tab->particles->g_particule);
        rpg_tab->particles->g_particule = add_particle_g(rpg_tab,
        rpg_tab->particles->g_particule);
    }
    particle_hand_g_loop(rpg_tab);
    rewind_particle_g(rpg_tab);
}