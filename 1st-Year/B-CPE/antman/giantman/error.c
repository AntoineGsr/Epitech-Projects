/*
** EPITECH PROJECT, 2021
** error
** File description:
** sous fonction
*/

#include "function.h"

int find_sizefiles_giant(char *str)
{
    struct stat info;

    stat(str, &info);
    return (info.st_size);
}

int other_error(char **av, giantman *antman)
{
    int opn = 0;
    int rd = 0;
    int size = find_sizefiles_giant(av[1]);

    antman->files = malloc(sizeof(char) * size + 1);
    if (antman->files == NULL)
        return (84);
    if (my_strlen(av[2]) != 1 || my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 3)
        return (84);
    opn = open(av[1], O_RDONLY);
    if (opn == -1)
        return (84);
    rd = read(opn, antman->files, size);
    if (rd == -1)
        return (84);
    antman->files[size] = '\0';
    opn = open(av[1], O_TRUNC);
    close(opn);
    return (0);
}