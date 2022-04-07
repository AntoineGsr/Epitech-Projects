/*
** EPITECH PROJECT, 2021
** menu_load.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void display_load_buttons_two(rpg_t *rpg_tab, int i)
{
    for (; i < rpg_tab->m->l_butt->save_max; i++,
    rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->node->next);
    for (int j = 0; j < 5 && i < rpg_tab->m->l_butt->list->nb_node; i++, j++) {
        sfSprite_setTextureRect(rpg_tab->m->l_butt->node->button->sprite,
        rpg_tab->m->l_butt->node->button->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->m->l_butt->node->button->sprite, NULL);
        sfRenderWindow_drawText(rpg_tab->window, rpg_tab->m->l_butt->node
        ->save_name->text, NULL);
        rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->node->next;
    } rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->list->first;
}

void display_load_buttons(rpg_t *rpg_tab)
{
    int i = 0;
    sfSprite_setTextureRect(rpg_tab->m->l_butt->l_wind->sprite,
    rpg_tab->m->l_butt->l_wind->sprite_rect);
    sfRenderWindow_drawSprite(rpg_tab->window,
    rpg_tab->m->l_butt->l_wind->sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfSprite_setTextureRect(rpg_tab->m->l_butt->button[i]->sprite,
        rpg_tab->m->l_butt->button[i]->sprite_rect);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->m->l_butt->button[i]->sprite, NULL);
    } display_load_buttons_two(rpg_tab, i);
}

void call_back_buttons_load_two(rpg_t *rpg_tab)
{
    if (rpg_tab->m->l_butt->button_state == CB_LOAD_BACK) {
            rpg_tab->m->l_butt->button[1]->sprite_rect.left = 0;
            rpg_tab->step = MENU;
    } if (rpg_tab->m->l_butt->button_state == CB_LOAD_CHARGE
        && rpg_tab->m->l_butt->save_click != -1) {
        rpg_tab->step = GAME;
        rpg_tab->g->play = LOAD_EXISTENT_GAME;
        clean_log_text(rpg_tab);
        sfMusic_stop(rpg_tab->m->menu_music);
        sfSound_play(rpg_tab->u->link_start->sound);
        for (int i = 0; i < rpg_tab->m->l_butt->save_click; i++,
        rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->node->next) {
            rpg_tab->m->l_butt->node->button->sprite_rect.left = 0;
        } parse_save(rpg_tab);
    } rpg_tab->m->l_butt->button_state = LOAD_BASE;
}

void call_back_buttons_load(rpg_t *rpg_tab)
{
    int state = (int)rpg_tab->m->l_butt->button_state - 6;
    sfTime time = sfClock_getElapsedTime(
    rpg_tab->m->l_butt->button[state]->anim_clock);
    float seconds = time.microseconds / 1000000.0;
    if (rpg_tab->m->l_butt->button_state >= CB_PREV)
        rpg_tab->m->l_butt->button_state -= 5;
    if (seconds > 0.75) {
        call_back_buttons_load_two(rpg_tab);
    }
}

void menu_load(rpg_t *rpg_tab)
{
    background_defil(rpg_tab);
    display_load_buttons(rpg_tab);
    if (rpg_tab->m->l_butt->button_state >= CB_LOAD_CHARGE)
        call_back_buttons_load(rpg_tab);
    while (sfRenderWindow_pollEvent(rpg_tab->window, &(rpg_tab->event))) {
        if (rpg_tab->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg_tab->window);
        if (rpg_tab->m->l_butt->button_state >= CB_LOAD_CHARGE) return;
        if (rpg_tab->event.type == sfEvtMouseMoved)
            load_move(rpg_tab);
        if (rpg_tab->event.mouseButton.button == sfMouseLeft
            && !(sfKeyboard_isKeyPressed(sfKeyA)
            || rpg_tab->event.type == sfEvtKeyReleased
            || rpg_tab->event.type == sfEvtMouseWheelScrolled
            || rpg_tab->event.type == sfEvtMouseButtonReleased))
            load_buttons_click(rpg_tab);
        if (rpg_tab->event.type == sfEvtMouseButtonReleased
            && rpg_tab->mouse_left_click == 1)
            load_buttons_released(rpg_tab);
    }
}