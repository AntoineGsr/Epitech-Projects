/*
** EPITECH PROJECT, 2021
** read_map.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

void display_map(global *game)
{
    for (int i = 0; game->map[i] != NULL; i++)
        mvprintw(i, 0, game->map[i]);
}

int calcul_row(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            count++;
    }
    count -= 2;
    return (count);
}

int calcul_col(char *str)
{
    int i = 0;

    for (; str[i] != '\0' && str[i] != '\n'; i++);
    i -= 2;
    return (i);
}

int malloc_buff_size(char const *filepath)
{
    struct stat *buff;
    int size = 0;

    buff = malloc(sizeof(struct stat));
    stat(filepath, buff);
    size = buff->st_size;
    free(buff);
    return (size);
}

char *read_map(int ac, char **av)
{
    int opn = 0;
    int rd = 0;
    int size = 0;
    char *buff = NULL;

    if (ac != 2)
        return NULL;
    opn = open(av[1], O_RDONLY);
    if (opn == -1)
        return NULL;
    size = malloc_buff_size(av[1]) + 1;
    buff = my_memset_char(size);
    if (buff == NULL)
        return NULL;
    rd = read(opn, buff, size);
    if (rd == -1)
        return NULL;
    return (buff);
}