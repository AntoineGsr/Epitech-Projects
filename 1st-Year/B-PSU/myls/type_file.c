/*
** EPITECH PROJECT, 2020
** type_file.c
** File description:
** my_ls
*/

#include "my_ls.h"

void *type_file(struct stat data)
{
    switch (data.st_mode & S_IFMT) {
    case S_IFBLK: my_putchar('b');
        break;
    case S_IFCHR: my_putchar('c');
        break;
    case S_IFDIR: my_putchar('d');
        break;
    case S_IFIFO: my_putchar('p');
        break;
    case S_IFLNK: my_putchar('l');
        break;
    case S_IFREG: my_putchar('-');
        break;
    case S_IFSOCK: my_putchar('s');
        break;
    default: my_putchar('?');
        break;
    }
}
