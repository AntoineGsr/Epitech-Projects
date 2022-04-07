/*
** EPITECH PROJECT, 2021
** handler of all error
** File description:
** sous fonction
*/

#include "../include/antman.h"

int find_sizefiles(char *str)
{
    struct stat info;

    stat(str, &info);
    return (info.st_size);
}

int error_handler(char **av, compression *antman)
{
    int opn = 0;
    int rd = 0;
    int size = find_sizefiles(av[1]);

    antman->file = malloc(sizeof(char) * size + 1);
    if (antman->file == NULL)
        return (84);
    if (my_strlen(av[2]) != 1 || my_getnbr(av[2]) < 1 || my_getnbr(av[2]) > 3)
        return (84);
    opn = open(av[1], O_RDONLY);
    if (opn == -1)
        return (84);
    rd = read(opn, antman->file, size);
    if (rd == -1)
        return (84);
    antman->file[size] = '\0';
    opn = open(av[1], O_TRUNC);
    close(opn);
    return (0);
}