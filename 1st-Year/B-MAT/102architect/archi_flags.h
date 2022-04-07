/*
** EPITECH PROJECT, 2020
** flags.h
** File description:
** my_ls
*/

#include "102architect.h"

#ifndef LSFLAGS_H_
#define LSFLAGS_H_

double translation(char **av, int i, int ac, double *base);

double scaling(char **av, int i, int ac, double *base);

double rotation(char **av, int i, int ac, double *base);

double reflexion(char **av, int i, int ac, double *base);

struct archi_flags {
    char a_flag;
    double (*type_aflag)(char **av, int i, int ac, double *base);
};

static const struct archi_flags AFLAG_FUNCS[] = {
    {'t', &translation},
    {'z', &scaling},
    {'r', &rotation},
    {'s', &reflexion}
};

#endif /* LSFLAGS_H_ */
