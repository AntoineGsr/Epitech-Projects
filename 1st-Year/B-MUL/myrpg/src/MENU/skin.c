/*
** EPITECH PROJECT, 2021
** skin.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void display_skin_buttons(rpg_t *rpg_tab)
{
    for (int i = 0; i < 2; i++) {
        sfSprite_setTextureRect(rpg_tab->m->s_butt->s_wind[i]->sprite,
        rpg_tab->m->s_butt->s_wind[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->m->s_butt->s_wind[i]->sprite, NULL);
    }
    sfSprite_setTextureRect(rpg_tab->m->s_butt->skin_rotate->sprite,
    rpg_tab->m->s_butt->skin_rotate->sprite_rect);
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->m->s_butt->skin_rotate->sprite, NULL);
    for (int i = 0; i < 7; i++) {
        sfSprite_setTextureRect(rpg_tab->m->s_butt->button[i]->sprite,
        rpg_tab->m->s_butt->button[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->m->s_butt->button[i]->sprite, NULL);
    }
}

void call_back_buttons_skin(rpg_t *rpg_tab)
{
    int state = (int)rpg_tab->m->s_butt->button_state - 8;
    sfTime time = sfClock_getElapsedTime(
    rpg_tab->m->s_butt->button[state]->anim_clock);
    float seconds = time.microseconds / 1000000.0;

    if (rpg_tab->m->s_butt->button_state >= CB_BLUE
        && rpg_tab->m->s_butt->button_state <= CB_BIN)
        rpg_tab->m->s_butt->button_state -= 7;
    if (seconds > 0.75) {
        if (rpg_tab->m->s_butt->button_state == CB_SKIN_BACK) {
            rpg_tab->step = MENU;
            rpg_tab->m->s_butt->button[6]->sprite_rect.left = 0;
        }
        rpg_tab->m->s_butt->button_state = SKIN_BASE;
    }
}

void animate_skin(rpg_t *rpg_tab)
{
    sfTime time = sfClock_getElapsedTime(
    rpg_tab->m->s_butt->skin_rotate->anim_clock);
    float seconds = time.microseconds / 1000000.0;

    if (seconds > 0.032) {
        rpg_tab->m->s_butt->skin_rotate->sprite_rect.left +=
        rpg_tab->m->s_butt->skin_rotate->sprite_rect.width;
        if (rpg_tab->m->s_butt->skin_rotate->sprite_rect.left
            > rpg_tab->m->s_butt->skin_rotate->sprite_rect.width * 11)
            rpg_tab->m->s_butt->skin_rotate->sprite_rect.left = 0;
        sfClock_restart(rpg_tab->m->s_butt->skin_rotate->anim_clock);
    }
}

void menu_skin(rpg_t *rpg_tab)
{
    background_defil(rpg_tab);
    display_skin_buttons(rpg_tab);
    animate_skin(rpg_tab);
    if (rpg_tab->m->s_butt->button_state >= CB_BLUE)
        call_back_buttons_skin(rpg_tab);
    while (sfRenderWindow_pollEvent(rpg_tab->window, &(rpg_tab->event))) {
        if (rpg_tab->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg_tab->window);
        if (rpg_tab->m->s_butt->button_state >= CB_BLUE) return;
        if (rpg_tab->event.type == sfEvtMouseMoved)
            skin_move(rpg_tab);
        if (rpg_tab->event.mouseButton.button == sfMouseLeft
            && !(sfKeyboard_isKeyPressed(sfKeyA)
            || rpg_tab->event.type == sfEvtKeyReleased
            || rpg_tab->event.type == sfEvtMouseWheelScrolled))
            skin_buttons_click(rpg_tab);
        if (rpg_tab->event.type == sfEvtMouseButtonReleased
            && rpg_tab->mouse_left_click == 1)
            skin_buttons_released(rpg_tab);
    }
}