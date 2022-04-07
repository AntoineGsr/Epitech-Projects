/*
** EPITECH PROJECT, 2020
** mask_array.c
** File description:
** my_ls
*/

#include "my_ls.h"

void create_mask_array(int ac, char **av, S_array *S_arr)
{
    for (int i = 0; i < 6; i++)
        S_arr->mask[i] = '0';
    S_arr->mask[6] = '\0';
    for (int i = 1; i < ac; i++) {
        for (int j = 0; av[i][0] == '-' && av[i][j] != '\0'; j++) {
            if (av[i][j] == 'l')
                S_arr->mask[0] = '1';
            if (av[i][j] == 'a')
                S_arr->mask[1] = '1';
            if (av[i][j] == 't')
                S_arr->mask[2] = '1';
            if (av[i][j] == 'r')
                S_arr->mask[3] = '1';
            if (av[i][j] == 'R')
                S_arr->mask[4] = '1';
            if (av[i][j] == 'd')
                S_arr->mask[5] = '1';
        }
    }
}