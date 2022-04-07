/*
** EPITECH PROJECT, 2021
** extrem_lines.c
** File description:
** dante
*/

#include "../../include/my.h"

void first_line(int j, generator *gen)
{
    if (j % 2 == 0) {
        gen->count += 1;
        if (j >= 2 && rand() % 2 == 1) {
            gen->cell[j] = gen->cell[j - 2];
            gen->cell[j - 1] = gen->cell[j - 2];
            gen->maze[j] = '*';
            gen->maze[j - 1] = '*';
            return;
        }
        gen->maze[j] = '*';
        gen->cell[j] = gen->count - 1;
    } else {
        gen->cell[j] = -1;
        gen->maze[j] = 'X';
    }
}

void last_line(int j, generator *gen)
{
    if (j > 0 && gen->cell[j] == WALL_DANTE && gen->last == -1) {
        gen->cell[j - 1] = 0;
        gen->maze[j - 1] = '*';
    }
    gen->cell[j] = 0;
    gen->maze[j] = '*';
}