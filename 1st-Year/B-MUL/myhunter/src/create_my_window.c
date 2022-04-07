/*
** EPITECH PROJECT, 2020
** createMyWindow.c
** File description:
** my_hunter
*/

#include "my_hunter.h"

sfRenderWindow *createMyWindow(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "MyHunter", sfDefaultStyle,
    NULL);
    sfRenderWindow_setFramerateLimit(window, 15);
    return (window);
}
