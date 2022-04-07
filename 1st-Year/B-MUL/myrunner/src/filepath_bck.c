/*
** EPITECH PROJECT, 2020
** filepath_bck.c
** File description:
** my_runner
*/

#include "my_runner.h"

char *filepath_bck(int i)
{
    char *fl_path = malloc(sizeof(char) * 17);

    fl_path[0] = '\0';
    fl_path = my_strcat(fl_path, "./image/bck");
    fl_path = my_strcat(fl_path, my_getstr(i + 1));
    fl_path = my_strcat(fl_path, ".png");
    return (fl_path);
}