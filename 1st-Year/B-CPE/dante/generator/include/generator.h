/*
** EPITECH PROJECT, 2020
** generator.h
** File description:
** dante
*/

#ifndef GEN_H_
#define GEN_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include "../lib/my/my.h"

#define WALL -1
#define WAY -4
#define RIGHT -10
#define WRONG -11

typedef struct cellule cellule;
struct cellule
{
    int type;
    int value;
};

typedef struct generator generator;
struct generator
{
    int av1;
    int av2;
    int ac;
    int count;
    int zero_link;
    int prev_val;
    int perfect_first;
    int *cell;
    char *maze;
    int verif_pos;
    int verif_neg;
    int last;
    int print_last;
};

generator *create_struct(int ac, char **av);
void destroy_struct(generator *gen);
int error_input(int ac, char **av);
void create_map(int x, int y, generator *gen);
void first_line(int j, generator *gen);
void horizontal_links(int j, generator *gen);
void vertical_links(int i, int j, generator *gen);
void last_line(int j, generator *gen);

#endif /* GEN_H_ */