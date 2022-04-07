/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void display_menu_buttons(rpg_t *rpg_tab)
{
    for (int i = 0; i < 2; i++) {
        sfSprite_setTextureRect(rpg_tab->m->m_wind[i]->sprite,
        rpg_tab->m->m_wind[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->m->m_wind[i]->sprite, NULL);
    }
    for (int i = 0; i < 6; i++) {
        sfSprite_setTextureRect(rpg_tab->m->m_butt->button[i]->sprite,
        rpg_tab->m->m_butt->button[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->m->m_butt->button[i]->sprite, NULL);
    }
}

int handle_menu_event(rpg_t *rpg_tab)
{
    if (rpg_tab->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg_tab->window);
    if (rpg_tab->m->m_butt->button_state >= CB_PLAY)
        return (1);
    if (rpg_tab->event.type == sfEvtMouseMoved)
        menu_move(rpg_tab);
    if (rpg_tab->event.mouseButton.button == sfMouseLeft
    && !(sfKeyboard_isKeyPressed(sfKeyA)
    || rpg_tab->event.type == sfEvtKeyReleased
    || rpg_tab->event.type == sfEvtMouseWheelScrolled))
        menu_buttons_click(rpg_tab);
    if (rpg_tab->event.type == sfEvtMouseButtonReleased
    && rpg_tab->mouse_left_click == 1) {
        sfSound_play(rpg_tab->u->click_sound->sound);
        menu_buttons_released(rpg_tab);
    } return (0);
}

void handle_menu_sound(rpg_t *rpg_tab)
{
    sfMusic_setVolume(rpg_tab->m->menu_music,
    rpg_tab->m->p_butt->button[1]->sprite_rect.width);
    sfSound_setVolume(rpg_tab->u->link_start->sound,
    rpg_tab->m->p_butt->button[1]->sprite_rect.width);
    sfSound_setVolume(rpg_tab->u->click_sound->sound,
    rpg_tab->m->p_butt->button[0]->sprite_rect.width);
    sfMusic_setVolume(rpg_tab->g->game_music,
    rpg_tab->m->p_butt->button[1]->sprite_rect.width);
    rpg_tab->config->sound_vol =
    rpg_tab->m->p_butt->button[0]->sprite_rect.width;
    rpg_tab->config->music_vol =
    rpg_tab->m->p_butt->button[1]->sprite_rect.width;
}

void handle_menu(rpg_t *rpg_tab)
{
    sfView_setSize(rpg_tab->view, (sfVector2f) {1920, 1080});
    sfView_setCenter(rpg_tab->view, (sfVector2f) {960, 540});
    sfRenderWindow_setView(rpg_tab->window, rpg_tab->view);
    background_defil(rpg_tab);
    particle_handling_m(rpg_tab);
    display_menu_buttons(rpg_tab);
    update_skin_button_color(rpg_tab);
    if (rpg_tab->m->m_butt->button_state >= CB_PLAY)
        call_back_buttons(rpg_tab);
    while (sfRenderWindow_pollEvent(rpg_tab->window, &(rpg_tab->event))) {
        if (handle_menu_event(rpg_tab) == 1)
            return;
    }
    handle_menu_sound(rpg_tab);
}