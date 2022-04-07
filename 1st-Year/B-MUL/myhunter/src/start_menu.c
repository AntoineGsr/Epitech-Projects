/*
** EPITECH PROJECT, 2020
** start_menu.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void init_struct_menu(S_base *menu, char const *filepath)
{
    menu->texture = sfTexture_createFromFile(filepath, NULL);
    menu->sprite = sfSprite_create();
    menu->rect.top = 0;
    menu->rect.left = 0;
    menu->rect.width = 300;
    menu->rect.height = 250;
    menu->play = 0;
    menu->pos.x = 810;
    menu->pos.y = 415;
    if (menu->start_stop != 1)
        menu->start_stop = 0;
}

void exec_struct_menu(S_base *menu)
{
    sfSprite_setTexture(menu->sprite, menu->texture, sfTrue);
    sfSprite_setTextureRect(menu->sprite, menu->rect);
    sfSprite_setPosition(menu->sprite, menu->pos);
}

void manage_mouse_click_menu(sfEvent event, S_base *menu)
{
    if (sfMouse_isButtonPressed(sfMouseLeft)) {
        if ((event.mouseButton.x >= menu->pos.x && event.mouseButton.x
        <= (menu->pos.x + menu->rect.width)) && (event.mouseButton.y
        >= menu->pos.y && event.mouseButton.y <= ((menu->pos.y) + 50))) {
                menu->play = 1;
        }
        if ((event.mouseButton.x >= menu->pos.x && event.mouseButton.x
        <= (menu->pos.x + menu->rect.width)) && (event.mouseButton.y
        >= (menu->pos.y + 200) && event.mouseButton.y
        <= ((menu->pos.y) + 250))) {
                menu->play = 2;
        }
    }
}

void analyse_events_menu(B_base *bck, S_base *menu, sfRenderWindow *window,
sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            close_window(window, event);
        if (event.type == sfEvtMouseButtonPressed)
            manage_mouse_click_menu(event, *&menu);
    }
    if (menu->start_stop == 0) {
        sfRenderWindow_drawSprite(window, bck->sprite, NULL);
        sfSprite_setTextureRect(menu->sprite, menu->rect);
    }
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
    sfRenderWindow_display(window);
}

int display_menu(sfRenderWindow *window, B_base *bck, sfEvent event,
S_base *menu)
{
    menu->start_stop = 0;
    init_struct_menu(*&menu, "./src/start_menu.png");
    exec_struct_menu(*&menu);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events_menu(bck, menu, window, event);
        if (menu->play == 1) {
            sfSprite_destroy(menu->sprite);
            sfTexture_destroy(menu->texture);
            return (0);
        }
        if (menu->play == 2) {
            sfSprite_destroy(menu->sprite);
            sfTexture_destroy(menu->texture);
            return (1);
        }
    }
    return (0);
}