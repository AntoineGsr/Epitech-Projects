/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** 105torus
*/

#include "105torus.h"

double f(double *value, double x)
{
    double result = 0;
    
    result = value[4] * pow(x, 4) + value[3] * pow(x, 3) + value[2] * pow(x, 2) + value[1] * x + value[0];
    return (result);
}

double f_deriv(double *value, double x)
{
    double result = 0;

    result = 4 * value[4] * pow(x, 3) + 3 * value[3] * pow(x, 2) + 2 * value[2] * x + value[1];
    return (result);
}

int main(int ac, char **av)
{
    double result = 0;
    double *value = malloc(sizeof(double) * 6);

    helper(ac, av);
    error_gestion(ac, av);
    for (int i = 2; i < 8; i++) {
        value[i - 2] = atof(av[i]);
    }
    if (av[1][0] == '1')
        bisection_method(value);
    if (av[1][0] == '2')
        newtons_method(value);
    if (av[1][0] == '3')
        secant_method(value);
    free(value);
    return (0);
}