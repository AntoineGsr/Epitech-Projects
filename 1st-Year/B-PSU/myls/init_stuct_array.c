/*
** EPITECH PROJECT, 2020
** init_struct_array.c
** File description:
** my_ls
*/

#include "my_ls.h"

void init_stuct_array(S_array *S_arr)
{
    S_arr->i = 0;
    S_arr->total_name = 0;
    S_arr->dsk_blk = 0;
    S_arr->not_d = 0;
    S_arr->rows = 0;
    S_arr->name = malloc(sizeof(char) * 256);
    S_arr->sck_name = malloc(sizeof(char) * 256);
    S_arr->stock = malloc(sizeof(char) * 256);
    S_arr->mask = malloc(sizeof(char) * 7);
    S_arr->full_ls = malloc(sizeof(char *) * 256);
    for (int i = 0; i < 256; i++) {
        S_arr->full_ls[i] = malloc(sizeof(char) * 256);
        S_arr->full_ls[i][0] = '\0';
    }
}