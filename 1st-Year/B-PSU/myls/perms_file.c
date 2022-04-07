/*
** EPITECH PROJECT, 2020
** perms_file.c
** File description:
** my_ls
*/

#include "my_ls.h"

char *perms_file(struct stat data)
{
    (data.st_mode & S_IRUSR) ? (my_putchar('r')) : (my_putchar('-'));
    (data.st_mode & S_IWUSR) ? (my_putchar('w')) : (my_putchar('-'));
    (data.st_mode & S_IXUSR) ? (my_putchar('x')) : (my_putchar('-'));
    (data.st_mode & S_IRGRP) ? (my_putchar('r')) : (my_putchar('-'));
    (data.st_mode & S_IWGRP) ? (my_putchar('w')) : (my_putchar('-'));
    (data.st_mode & S_IXGRP) ? (my_putchar('x')) : (my_putchar('-'));
    (data.st_mode & S_IROTH) ? (my_putchar('r')) : (my_putchar('-'));
    (data.st_mode & S_IWOTH) ? (my_putchar('w')) : (my_putchar('-'));
    (data.st_mode & S_IXOTH) ? (my_putchar('x')) : (my_putchar('-'));
    my_putchar('.');
    my_putchar(' ');
    return NULL;
}
