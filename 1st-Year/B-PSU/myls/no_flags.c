/*
** EPITECH PROJECT, 2020
** no_flags.c
** File description:
** my_ls
*/

#include "my_ls.h"

int no_flags(struct dirent *file)
{
    DIR *dir = opendir(".");

    if (dir == NULL) {
        my_putstr_fast("ls: cannot access '.': No such file or directory\n");
        exit(84);
    }
    while ((file = readdir(dir)) != NULL) {
        if (file->d_name[0] != '.') {
            my_putstr_fast(file->d_name);
            my_putchar('\n');
        }
    }
    closedir(dir);
    return (0);
}
