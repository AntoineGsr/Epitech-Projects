/*
** EPITECH PROJECT, 2020
** is_square_of_size.c
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

int is_square_of_size(int **map , int row , int col, Coord_max *cord)
{
    if (row > 0 && col > 0) {
        map[row][col] = map[row][col - 1] + 1;
        if (map[row][col] > map[row - 1][col])
            map[row][col] = map[row - 1][col] + 1;
        if (map[row][col] > map[row - 1][col - 1])
            map[row][col] = map[row - 1][col - 1] + 1;
    }
    if (map[row][col] > cord->max_square) {
        cord->max_square = map[row][col];
        cord->row = row;
        cord->col = col;
    }
    return (map[row][col]);
}
