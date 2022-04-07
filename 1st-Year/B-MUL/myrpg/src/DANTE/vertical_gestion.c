/*
** EPITECH PROJECT, 2021
** vertical_gestion.c
** File description:
** dante
*/

#include "../../include/my.h"

static void check_rand_link(int j, generator *gen)
{
    if (rand() % 2 == 0 && !(gen->cell[j] == 0 && j == 0)) {
        gen->cell[j] = WALL_DANTE;
        gen->maze[j] = 'X';
    } else {
        gen->maze[j] = '*';
        gen->zero_link = 1;
        if (gen->ac == 4)
            gen->perfect_first = 1;
    }
}

static int check_norand_link(int i, int j, generator *gen)
{
    if (gen->perfect_first == 1 && i == 1) {
        gen->cell[j] = WALL_DANTE;
        gen->zero_link = 0;
        gen->maze[j] = 'X';
        return (1);
    }
    if (gen->zero_link == 0 &&
        ((gen->cell[j] != gen->cell[j + gen->verif_pos]
        && gen->cell[j] != gen->cell[j - gen->verif_neg])
        || (gen->cell[j] == gen->cell[j + gen->verif_pos]
        && gen->verif_pos == 0))) {
        gen->zero_link = 1;
        gen->maze[j] = '*';
        return (1);
    }
    return (0);
}

void vertical_links(int i, int j, generator *gen)
{
    gen->verif_neg = 0;
    gen->verif_pos = 0;
    if (j > 1 && gen->cell[j - 2] != gen->cell[j])
        gen->zero_link = 0;
    if (gen->av2 % 2 == 1)
        gen->last = gen->cell[j];
    if (gen->prev_val != gen->cell[j]) {
        gen->prev_val = gen->cell[j];
        gen->perfect_first = 0;
    }
    if (j % 2 == 0) {
        if (j > 0)
            gen->verif_neg = 1;
        if (j + 1 < gen->av1)
            gen->verif_pos = 1;
        gen->count = gen->cell[j];
        if (check_norand_link(i, j, gen) == 1) return;
        check_rand_link(j, gen);
    }
}