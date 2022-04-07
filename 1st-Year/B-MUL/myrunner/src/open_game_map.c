/*
** EPITECH PROJECT, 2020
** open_game_map.c
** File description:
** my_runner
*/

#include "my_runner.h"

char *open_game_map(int ac, char **av)
{
    char *map = NULL;
    char buff[500];
    int opn = open(av[1], O_RDONLY);
    int i = 0;

    if (av[1][0] == '-' && av[1][0] == 'i')
        return NULL;
    if (opn == -1)
        return NULL;
    read(opn, buff, 499);
    for (i = 0; buff[i] != '\n' && buff[i] != '\0'; i++);
    buff[i] = '\0';
    map = malloc(sizeof(char) * my_strlen(buff) + 1);
    map[0] = '\0';
    map = my_strcpy(map, buff);
    return (map);
}