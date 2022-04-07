/*
** EPITECH PROJECT, 2021
** menu_help.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void display_help(rpg_t *rpg_tab)
{
    if (rpg_tab->h->page == 0) {
        animate_text(rpg_tab, rpg_tab->h->animate_txt, 15,
        (int [3]){127, 26, 63});
        sfText_setString(rpg_tab->h->animate_txt->text,
        rpg_tab->h->animate_txt->ctrl);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->h->help_sprite[0]->sprite, NULL);
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->h->animate_txt->text, NULL);
    }
    if (rpg_tab->h->page == 1) {
        animate_text(rpg_tab, rpg_tab->h->animate_txt, 15,
        (int [3]){127, 26, 63});
        sfText_setString(rpg_tab->h->animate_txt->text,
        rpg_tab->h->animate_txt->ctrl);
        sfRenderWindow_drawSprite(rpg_tab->window,
        rpg_tab->h->help_sprite[1]->sprite, NULL);
        sfRenderWindow_drawText(rpg_tab->window,
        rpg_tab->h->animate_txt->text, NULL);
    }
}

void menu_help(rpg_t *rpg_tab)
{
    background_defil(rpg_tab);
    display_help(rpg_tab);
    while (sfRenderWindow_pollEvent(rpg_tab->window, &(rpg_tab->event))) {
        if (rpg_tab->event.type == sfEvtClosed)
            sfRenderWindow_close(rpg_tab->window);
        if (rpg_tab->event.type == sfEvtKeyPressed
        && rpg_tab->event.key.code == sfKeyEnter)
            rpg_tab->h->page += 1;
    }
    if (rpg_tab->h->page >= 2) {
        rpg_tab->h->page = 0;
        rpg_tab->step = MENU;
    }
}