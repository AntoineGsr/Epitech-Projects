/*
** EPITECH PROJECT, 2020
** close_window.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

void close_window(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
