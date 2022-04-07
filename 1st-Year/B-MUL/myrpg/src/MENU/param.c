/*
** EPITECH PROJECT, 2021
** param.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void call_back_buttons_param_three(rpg_t *rpg_tab)
{
    rpg_tab->g->door_msg->ctrl = my_strcat(rpg_tab->g->door_msg->ctrl,
    " to interact");
    free(rpg_tab->g->reload_msg->ctrl);
    rpg_tab->g->reload_msg->ctrl = my_memset_char(25);
    rpg_tab->g->reload_msg->ctrl = my_strcpy(rpg_tab->g->reload_msg->
    ctrl, "Press ");
    if (my_strlen(rpg_tab->m->p_butt->key[4]->ctrl) == 1 && rpg_tab->
    m->p_butt->key[4]->ctrl[0] >= 'a' && rpg_tab->m->p_butt->key[4]->
    ctrl[0] <= 'z')
        rpg_tab->m->p_butt->key[4]->ctrl[0] = rpg_tab->m->p_butt->
        key[4]->ctrl[0] % 'a' + 'A';
    rpg_tab->g->reload_msg->ctrl = my_strcat(rpg_tab->g->reload_msg
    ->ctrl, rpg_tab->m->p_butt->key[4]->ctrl);
    rpg_tab->g->reload_msg->ctrl = my_strcat(rpg_tab->g->reload_msg
    ->ctrl, " to reload");
    rpg_tab->step = MENU;
    rpg_tab->m->p_butt->button[5]->sprite_rect.left = 0;
}

void call_back_buttons_param_two(rpg_t *rpg_tab)
{
    free(rpg_tab->g->drop_msg->ctrl);
    rpg_tab->g->drop_msg->ctrl = my_memset_char(30);
    rpg_tab->g->drop_msg->ctrl = my_strcpy(rpg_tab->g->drop_msg->ctrl
    , "Press ");
    free(rpg_tab->g->door_msg->ctrl);
    rpg_tab->g->door_msg->ctrl = my_memset_char(30);
    rpg_tab->g->door_msg->ctrl = my_strcpy(rpg_tab->g->door_msg->ctrl,
    "Press ");
    if (my_strlen(rpg_tab->m->p_butt->key[2]->ctrl) == 1 && rpg_tab->m
    ->p_butt->key[2]->ctrl[0] >= 'a' && rpg_tab->m->p_butt->key[2]->
    ctrl[0] <= 'z')
        rpg_tab->m->p_butt->key[2]->ctrl[0] = rpg_tab->m->p_butt->
        key[2]->ctrl[0] % 'a' + 'A';
    rpg_tab->g->drop_msg->ctrl = my_strcat(rpg_tab->g->drop_msg->ctrl,
    rpg_tab->m->p_butt->key[2]->ctrl);
    rpg_tab->g->drop_msg->ctrl = my_strcat(rpg_tab->g->drop_msg->ctrl,
    " to grab item");
    rpg_tab->g->door_msg->ctrl = my_strcat(rpg_tab->g->door_msg->ctrl,
    rpg_tab->m->p_butt->key[2]->ctrl);
    call_back_buttons_param_three(rpg_tab);
}

void call_back_buttons_param(rpg_t *rpg_tab)
{
    int state = (int)rpg_tab->m->p_butt->button_state - 16;
    sfTime time = sfClock_getElapsedTime(
    rpg_tab->m->p_butt->button[state]->anim_clock);
    float seconds = time.microseconds / 1000000.0;

    if (rpg_tab->m->p_butt->button_state >= CB_PARAM_30FPS
        && rpg_tab->m->p_butt->button_state != CB_PARAM_BACK)
        rpg_tab->m->p_butt->button_state = PARAM_BASE;
    if (seconds > 0.75) {
        if (rpg_tab->m->p_butt->button_state == CB_PARAM_BACK) {
            call_back_buttons_param_two(rpg_tab);
        }
        rpg_tab->m->p_butt->button_state = PARAM_BASE;
    }
}

int menu_param_event(rpg_t *rpg_tab)
{
    if (rpg_tab->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg_tab->window);
    if (rpg_tab->m->p_butt->button_state >= CB_PARAM_SOUND)
        return (1);
    if (rpg_tab->event.type == sfEvtMouseMoved)
        param_move(rpg_tab);
    if (rpg_tab->event.mouseButton.button == sfMouseLeft
    && !(sfKeyboard_isKeyPressed(sfKeyA)
    || rpg_tab->event.type == sfEvtKeyReleased
    || rpg_tab->event.type == sfEvtMouseWheelScrolled))
        param_buttons_click(rpg_tab);
    if (rpg_tab->event.type == sfEvtMouseButtonReleased
    && rpg_tab->mouse_left_click == 1) {
        param_buttons_released(rpg_tab);
        sfSound_play(rpg_tab->u->click_sound->sound);
    } if (rpg_tab->event.type == sfEvtKeyPressed)
        check_controls_mod(rpg_tab);
    if (rpg_tab->event.type == sfEvtTextEntered)
        check_controls_txt(rpg_tab);
    return (0);
}

void menu_param(rpg_t *rpg_tab)
{
    background_defil(rpg_tab);
    display_param_buttons(rpg_tab);
    if (rpg_tab->m->p_butt->button_state >= CB_PARAM_SOUND)
        call_back_buttons_param(rpg_tab);
    while (sfRenderWindow_pollEvent(rpg_tab->window, &(rpg_tab->event))) {
        if (menu_param_event(rpg_tab) == 1)
            return;
    }
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