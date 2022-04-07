/*
** EPITECH PROJECT, 2021
** horizontal_gestion.c
** File description:
** dante
*/

#include "../../include/my.h"

static void check_link_horizontal(int j, generator *gen, int rd_imperfect)
{
    if (rand() % 2 == 1 || (gen->cell[j - 2] == 0
        && gen->cell[j - 1] == -1)) {
        if (gen->cell[j] == gen->cell[j - 2]
            && rd_imperfect < 2) {
            gen->cell[j - 1] = WALL_DANTE;
            gen->maze[j - 1] = 'X';
            return;
        } else {
            gen->cell[j] = gen->cell[j - 2];
            gen->cell[j - 1] = gen->cell[j - 2];
            gen->maze[j] = '*';
            gen->maze[j - 1] = '*';
            return;
        }
    }
}

void horizontal_links(int j, generator *gen)
{
    int rd_imperfect = 0;

    if (gen->av2 % 2 == 0)
        gen->last = gen->cell[j];
    if (gen->ac == 3)
        rd_imperfect = rand() % 5;
    if (j % 2 == 0) {
        gen->count += 1;
        if (j >= 2) {
            check_link_horizontal(j, gen, rd_imperfect);
            return;
        }
    }
}