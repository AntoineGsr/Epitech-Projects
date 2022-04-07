/*
** EPITECH PROJECT, 2020
** flag_to_exe.c
** File description:
** my_ls
*/

#include "my_ls.h"

int flag_to_exe(struct stat data, struct dirent *file, S_array *S_arr,
char **av)
{
    if (S_arr->mask[3] == '1' && S_arr->mask[5] == '0') {
        r_flag(*&S_arr, file, data);
    }
    if (S_arr->mask[0] == '1' && S_arr->mask[5] == '0') {
        l_flag(*&S_arr, file, data);
    }
    for (int i = 0; i <= S_arr->rows; i++) {
        data = create_struct(S_arr->full_ls[i]);
        print_ls(S_arr->full_ls[i], data, file, S_arr);
    }
    return (0);
}