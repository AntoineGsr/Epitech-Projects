/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** my_ls
*/

#include "my_ls.h"

void total_file(S_array *S_arr, int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-')
            S_arr->total_name += 1;
    }
}

int main(int ac, char **av)
{
    struct dirent *file;
    struct stat data;
    S_array S_arr;
    int i = 1;

    if (ac == 1) {
        no_flags(file);
    } else {
        init_stuct_array(&S_arr);
        create_mask_array(ac, av, &S_arr);
        total_file(&S_arr, ac, av);
        name_file(ac, av, &S_arr);
        full_array_create(&S_arr, file, data, av);
        flag_to_exe(data, file, &S_arr, av);
    }
    return (0);
}