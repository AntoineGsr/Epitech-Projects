/*
** EPITECH PROJECT, 2020
** get_my_period.c
** File description:
** my_ls
*/

#include "my_ls.h"

char *get_my_period(char *period)
{
    for (int j = 4; j < 16; j++)
        my_putchar(period[j]);
    return NULL;
}
