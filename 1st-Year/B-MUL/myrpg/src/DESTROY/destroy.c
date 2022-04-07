/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../include/my.h"

void destroy_all(rpg_t *rpg_tab)
{
    sfMusic_destroy(rpg_tab->g->game_music);
    sfMusic_destroy(rpg_tab->m->menu_music);
    sfSoundBuffer_destroy(rpg_tab->u->link_start->sound_buffer);
    sfSound_destroy(rpg_tab->u->link_start->sound);
    sfSoundBuffer_destroy(rpg_tab->u->click_sound->sound_buffer);
    sfSound_destroy(rpg_tab->u->click_sound->sound);
    sfRenderWindow_destroy(rpg_tab->window);
}