/*
** EPITECH PROJECT, 2020
** loop_char_to_matrix.c
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

void init_struct(Coord_max *cord)
{
    cord->max_square = 0;
    cord->row = 0;
    cord->col = 0;
}

int start_to_line2(char *buff)
{
    int i = 0;

    for (i; buff[i] != '\n'; i++);
    i += 1;
    return (i);
}

int error_inside_map(char *buff, int size)
{
    if (buff[size] == 'o') {
        return (0);
    }
    if (buff[size] != 'o')
        return (-1);
}

int loop_char_to_matrix(char *buff, int **stock, int nb_rows, int nb_cols)
{
    int size = start_to_line2(buff);
    Coord_max cord;

    init_struct(&cord);
    for (int i = 0; i < nb_rows; i++, size++) {
        for (int j = 0; j < nb_cols; j++, size++) {
            if (buff[size] == '.') {
                stock[i][j] = 1;
                is_square_of_size(stock, i, j, &cord);
            } else
                stock[i][j] = error_inside_map(buff, size);
            if (stock[i][j] == -1)
                return (-1);
        }
    }
    cross_on_map(nb_rows, nb_cols, stock, cord);
    return (0);
}
