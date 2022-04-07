/*
** EPITECH PROJECT, 2020
** detect_cross.c
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

void detect_cross(char **cross, int row, int col, int sq_size)
{
    int i = 0;
    int j = 1;

    for (j; j < sq_size; j++) {
        for (int i = 0; i < sq_size ; i++) {
            cross[row][col - i] = 'x';
            cross[row - j][col - i] = 'x';
        }
    }
    if (sq_size == 1)
        cross[row][col] = 'x';
}