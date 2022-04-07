/*
** EPITECH PROJECT, 2020
** l_flag.c
** File description:
** my_ls
*/

#include "my_ls.h"

int l_flag(S_array *S_arr, struct dirent *file, struct stat data)
{
    if (S_arr->not_d != 1) {
        total_block(*&S_arr);
        my_putstr_fast("total ");
        my_put_nbr(S_arr->dsk_blk);
        my_putchar('\n');
    }
    return (0);
}