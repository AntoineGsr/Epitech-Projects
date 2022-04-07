/*
** EPITECH PROJECT, 2021
** my_random.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

static int randomize_from_read(FILE *fd)
{
    unsigned int  seed;

    if (!fd)
        return -1;

    if (fread(&seed, sizeof(seed), 1, fd) == 1) {
        fclose(fd);
        srand(seed);
        return 0;
    }
    fclose(fd);
    return -1;
}

void get_seed(void)
{
    if (!randomize_from_read(fopen("/dev/urandom", "r")))
        return;
    if (!randomize_from_read(fopen("/dev/arandom", "r")))
        return;
    if (!randomize_from_read(fopen("/dev/random", "r")))
        return;
}

void pause_restart_clock(list ***gbl, l_list ***node, int i)
{
    for (int j = 0; j < (*gbl)[i]->max_node; j++,
        (*node)[i] = (*node)[i]->next) {
        sfClock_restart((*node)[i]->mob->clock);
        if (i < 2)
            sfClock_restart((*node)[i]->mob->clock_action);
    }
}

void pause_gestion(list ***gbl, l_list ***node)
{
    for (int i = 0; i < 3; i++) {
        pause_restart_clock(gbl, node, i);
    }
    (*node)[0] = (*gbl)[0]->first;
    (*node)[1] = (*gbl)[1]->first;
    (*node)[2] = (*gbl)[2]->first;
}