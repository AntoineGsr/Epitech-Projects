/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/specifer.h"
#include "global.h"
#include "bsq.h"

int col_size(char *buff)
{
    int i = 0;
    int col = 0;

    for (i; buff[i] != '\n'; i++) {
        if (buff[i] == '\0')
            return (-1);
    }
    i += 1;
    for (i; buff[i] != '\n'; i++, col++) {
        if (buff[i] != 'o' && buff[i] != '.')
            return (-1);
    }
    return (col);
}

int row_size(char *buff)
{
    int row = my_getnbr(buff);

    if (buff[0] < '0' || buff[0] > '9')
        return (-1);
    return (row);
}

int main(int ac, char const **av)
{
    int size = malloc_buff_size(av[1]);
    int opn = 0;
    int rd_fl = 0;
    char *buff = malloc(sizeof(char) * size + 1);
    int row = 0;
    int col = 0;

    opn = open(av[1], O_RDONLY);
    if (opn == -1)
        return (84);
    rd_fl = read(opn, buff, size);
    buff[size] = '\0';
    row = row_size(buff);
    col = col_size(buff);
    if (col == -1 || row == -1)
        return (84);
    if (load_2d_arr_from_file(row, col, buff) == -1)
        return (84);
    free(buff);
    return (0);
}
