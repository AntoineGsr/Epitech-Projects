/*
** EPITECH PROJECT, 2020
** cross_on_map.c
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

int my_putstr_fast(char const *str, int nb)
{
    write(1, str, nb);
    return (0);
}

void cross_on_map(int nb_rows, int nb_cols, int **stock, Coord_max cord)
{
    int max_square = 0;
    int last_size = 0;
    char **cross = malloc(sizeof(char *) * (nb_rows + 1));

    for (int j = 0; j < nb_rows; j++)
        cross[j] = malloc(sizeof(char) * (nb_cols + 1));
    for (int i = 0; i < nb_rows; i++) {
        for (int j = 0; j < nb_cols; j++) {
            if (stock[i][j] == 0) {
                cross[i][j] = 'o';
            } else
                cross[i][j] = '.';
        }
        detect_cross(cross, cord.row, cord.col, stock[cord.row][cord.col]);
        cross[i][nb_cols] = '\0';
        my_putstr_fast(cross[i], nb_cols);
        my_putchar('\n');
    }
    free(cross);
}
