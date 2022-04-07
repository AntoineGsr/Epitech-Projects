/*
** EPITECH PROJECT, 2020
** create_buff.c
** File description:
** navy
*/

#include "navy.h"

char **create_buff(int ac, char **av, char **buff)
{
    int opn = 0;
    int rd_fl = 0;
    char copy_txt[31];

    buff = malloc(sizeof(char *) * 4);
    for (int i = 0; i < 4; i++)
        buff[i] = malloc(sizeof(char) * 8);
    if (ac == 2)
        opn = open(av[1], O_RDONLY);
    if (ac == 3)
        opn = open(av[2], O_RDONLY);
    rd_fl = read(opn, copy_txt, 31);
    copy_txt[31] = '\0';
    for (int i = 0, k = 0; i < 4; i++, k++) {
        for (int j = 0; j < 7; j++, k++) {
            buff[i][j] = copy_txt[k];
        }
        buff[i][7] = '\0';
    }
    return (buff);
}