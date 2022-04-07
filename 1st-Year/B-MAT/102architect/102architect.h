/*
** EPITECH PROJECT, 2020
** 102architect.h
** File description:
** 102architect
*/

#ifndef ARCHI_H_
#define ARCHI_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "./lib/my/my.h"
#include "archi_flags.h"

int error_gestion(int ac, char **av);

double translation(char **av, int i, int ac, double *base);

double scaling(char **av, int i, int ac, double *base);

double rotation(char **av, int i, int ac, double *base);

double reflexion(char **av, int i, int ac, double *base);

#endif /* ARCHI_H_ */
