/*
** EPITECH PROJECT, 2020
** createMyWindow.c
** File description:
** my_runner
*/

#include "my_runner.h"

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "MyRunner", sfDefaultStyle,
    NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}
