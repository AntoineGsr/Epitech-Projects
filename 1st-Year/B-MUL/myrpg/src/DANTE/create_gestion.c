/*
** EPITECH PROJECT, 2021
** create_struct.c
** File description:
** generator
*/

#include "../../include/my.h"

void create_map_aux(generator *gen, char ***dante, int i)
{
    gen->zero_link = 0;
    gen->maze[11] = '\0';
    (*dante)[i] = my_strcpy((*dante)[i], gen->maze);
}

char **create_map(int x, int y, generator *gen)
{
    char **dante = malloc(sizeof(char *) * 12);
    for (int i = 0; i < 12; i++)
        dante[i] = malloc(sizeof(char) * 12);
    for (int j = 0; j < x; j++)
        first_line(j, gen);
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (i % 2 == 0 && i > 0)
                horizontal_links(j, gen);
            if (i % 2 == 1)
                vertical_links(i, j, gen);
            if (i > 0 && j % 2 == 1) {
                gen->cell[j] = WALL_DANTE;
                gen->maze[j] = 'X';
            } if (i + 1 >= y && j + 1 >= x) {
                last_line(j, gen);
                gen->print_last = 0;
            }
        } create_map_aux(gen, &dante, i);
    } return (dante);
}

generator *create_struct(int ac, char **av)
{
    generator *gen = malloc(sizeof(generator));

    if (gen == NULL)
        return NULL;
    gen->av1 = 11;
    gen->av2 = 11;
    gen->ac = 11;
    gen->zero_link = 0;
    gen->count = 0;
    gen->perfect_first = 0;
    gen->prev_val = 0;
    gen->verif_pos = 0;
    gen->verif_neg = 0;
    gen->last = 0;
    gen->print_last = 1;
    gen->maze = malloc(sizeof(char) * gen->av1 + 2);
    gen->maze[gen->av1] = '\n';
    gen->maze[gen->av1 + 1] = '\0';
    gen->cell = malloc(sizeof(int) * gen->av1);
    return (gen);
}