/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

float speed_coeff(float seconds, int speed)
{
    float coeff = speed * seconds;

    return (coeff);
}

void handle_coeff(rpg_t *rpg_tab)
{
    sfTime coeff_time = sfClock_getElapsedTime(rpg_tab->u->clock_coeff);

    rpg_tab->coeff = coeff_time.microseconds / 16730.0;
    rpg_tab->int_coeff = (int) rpg_tab->coeff;
    if (rpg_tab->int_coeff == 0)
        rpg_tab->int_coeff = 1;
    rpg_tab->window_size = sfRenderWindow_getSize(rpg_tab->window);
    sfClock_restart(rpg_tab->u->clock_coeff);
}

static int randomize_from_read(FILE *fd)
{
    unsigned int  seed;

    if (!fd)
        return (-1);
    if (fread(&seed, sizeof(seed), 1, fd) == 1) {
        fclose(fd);
        srand(seed);
        return (0);
    }
    fclose(fd);
    return (-1);
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