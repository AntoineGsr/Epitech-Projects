/*
** EPITECH PROJECT, 2021
** bisection_method.c
** File description:
** 105torus
*/

#include "105torus.h"

int stop_loop(double *value, double a, double b, double m)
{
    if ((b - a) > 1 * pow(10, -value[5]) || f(value, m) == 0)
        return (0);
    return (1);
}

void print_func(double *value, double a, double b, double m)
{
    if (stop_loop(value, a, b, m) == 1) {
        printf("x = %.*f\n", (int)(value[5]), m);
    } else
        printf("x = %.*g\n", (int)(value[5]), m);
}

void bisection_method(double *value)
{
    double a = 0;
    double b = 1;
    double m = 0;
    double stock_m = 0;

    for (int i = 0; i < 250; i++) {
        if ((a + b) == 0)
            exit (84);
        m = (a + b) / 2;
        if (stop_loop(value, a, b, m) == 1)
            exit (0);
        if (f(value, a) * f(value, m) <= 0) {
            b = m;
        } else
            a = m;
        print_func(value, a, b, m);
        stock_m = m;
    }
    exit(84);
}
