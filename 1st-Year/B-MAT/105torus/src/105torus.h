/*
** EPITECH PROJECT, 2020
** 104intersection.h
** File description:
** 105torus
*/

#ifndef TORUS_H_
#define TORUS_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/my/my.h"

int helper(int ac, char **av);
int error_gestion(int ac, char **av);
double f(double *value, double x);
double f_deriv(double *value, double x);
void bisection_method(double *value);
void newtons_method(double *value);
void secant_method(double *value);

#endif /* TORUS_H_ */
