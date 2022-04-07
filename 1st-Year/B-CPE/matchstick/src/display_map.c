/*
** EPITECH PROJECT, 2021
** display_map.c
** File description:
** matchstick
*/

#include "../include/matchstick.h"

void display_map_calcul(global *data, int *j, int *i)
{
    my_putchar('*');
    for (*j = 0; *j < data->rows - 1 - *i; *j += 1)
        my_putchar(' ');
    for (int k = 0; k < data->sticks_line[*i]; k++) {
        my_putchar('|');
        *j += 1;
    }
    for (; *j < data->rows * 2 - 1; *j += 1)
        my_putchar(' ');
    my_putchar('*');
    my_putchar('\n');
}

void display_map(global *data)
{
    int j = 0;

    for (int i = 0; i < data->rows * 2 + 1; i++)
        my_putchar('*');
    my_putchar('\n');
    for (int i = 0; i < data->rows; i++)
        display_map_calcul(data, &j, &i);
    for (int i = 0; i < data->rows * 2 + 1; i++)
        my_putchar('*');
    my_putchar('\n');
    if (data->total_stick > 0)
        my_putchar('\n');
}