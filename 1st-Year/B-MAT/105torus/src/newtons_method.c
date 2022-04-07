/*
** EPITECH PROJECT, 2021
** newtons_method.c
** File description:
** 105torus
*/

#include "105torus.h"

int stop_loop_newton(double *value, double classic, double derivate)
{
    if ((classic / derivate) < 1 * pow(10, -value[5]))
        return (0);
    return (1);
}

void print_func_newton(double *value, double classic, double derivate, double x)
{
    if (stop_loop_newton(value, classic, derivate) == 1) {
        printf("x = %.*f\n", (int)(value[5]), x);
    } else
        printf("x = %.*g\n", (int)(value[5]), x);
}

void newtons_method(double *value)
{
    double x = 0.5;
    double classic = f(value, x);
    double derivate = f_deriv(value, x);
    double x_stock = x;

    if (f(value, x) == 0 || f_deriv(value, x) == 0)
        exit(84);
    printf("x = %.1f\n", x);
    for (int i = 0; i < 250; i++) {
        if (f(value, x) == 0 || f_deriv(value, x) == 0)
            exit(84);
        if (stop_loop_newton(value, classic, derivate) == 1)
            exit(0);
        derivate = f_deriv(value, x);
        classic = f(value, x);
        x = x - (classic / derivate);
        if (x - x_stock < 0)
            exit(0);
        x_stock = x; 
        print_func_newton(value, classic, derivate, x);
    }
    exit(84);
}
