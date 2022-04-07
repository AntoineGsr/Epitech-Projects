/*
** EPITECH PROJECT, 2020
** r_flag.c
** File description:
** my_ls
*/

#include "my_ls.h"

int r_flag(S_array *S_arr, struct dirent *file, struct stat data)
{
    int max_row = S_arr->rows;
    int min_row = 0;

    for (min_row = 0; min_row < max_row; min_row++, max_row--) {
        S_arr->stock = S_arr->full_ls[min_row];
        S_arr->full_ls[min_row] = S_arr->full_ls[max_row];
        S_arr->full_ls[max_row] = S_arr->stock;
    }
    return (0);
}
