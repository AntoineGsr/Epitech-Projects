/*
** EPITECH PROJECT, 2020
** error_right.c
** File description:
** my_ls
*/

#include "my_ls.h"

int error_right(S_array *S_arr)
{
    my_putstr_fast("ls: cannot access '");
    my_putstr_fast(S_arr->stock);
    my_putstr_fast("': No such file or directory\n");
    exit(84);
}