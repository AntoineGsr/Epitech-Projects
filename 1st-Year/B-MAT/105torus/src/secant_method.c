/*
** EPITECH PROJECT, 2021
** secant_method.c
** File description:
** 105torus
*/

#include "105torus.h"

int stop_loop_secant(double *value, double classic, double derivate)
{
    if (abs(classic) < 1 * pow(10, -value[5]))
        return (0);
    return (1);
}

void print_func_secant(double *value, double classic, double derivate, double x)
{
    if (stop_loop_secant(value, classic, derivate) == 1) {
        printf("x = %.*f\n", (int)(value[5]), x);
    } else
        printf("x = %.*g\n", (int)(value[5]), x);
}

void secant_method(double *value)
{
    double x_less = 0;
    double x = 1;
    double f_classic = f(value, x);
    double f_less = f(value, x_less);
    double numerator = x - (f_classic * (x - x_less));
    double denominator = f_classic - f_less;
    double x_more = numerator / denominator;

    if ((f_classic * (x - x_less)) == 0 || (f_classic - f_less) == 0)
        exit(84);
    for (int i = 0; i < 50; i++) {
        if (f_classic - f_less == 0)
            exit(84);
        f_classic = f(value, x);
        f_less = f(value, x_less);
        numerator = x - (f_classic * (x - x_less));
        denominator = f_classic - f_less;
        x_more = x - ((f_classic * (x - x_less) / (f_classic - f_less)));
        if (stop_loop_secant(value, f(value, x_more), f_less) == 1)
            exit(0);
        print_func_secant(value, f(value, x_more), f_less, x_more);
        x_less = x;
        x = x_more;
    }
    exit(84);
}