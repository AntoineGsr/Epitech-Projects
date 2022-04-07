/*
** EPITECH PROJECT, 2020
** translation.c
** File description:
** 102architect
*/

#include "102architect.h"

double translation(char **av, int i, int ac, double *base)
{
    double x1 = atof(av[1]);
    double y1 = atof(av[2]);
    double z1 = 1.000000;
    double a2 = atof(av[i + 1]);
    double b2 = atof(av[i + 2]);
    double c2 = 1.000000;
    double matrix[9] = {c2, 0.000000, a2, 0.000000, c2, b2, 0.000000, 0.000000, c2};

    printf("Translation along vector (%d, %d)\n", (int)a2, (int)b2);
    printf("%.2f\t%.2f\t%.2f\n", matrix[0], matrix[1], matrix[2]);
    printf("%.2f\t%.2f\t%.2f\n", matrix[3], matrix[4], matrix[5]);
    printf("%.2f\t%.2f\t%.2f\n", matrix[6], matrix[7], matrix[8]);

    base[0] = matrix[2] + x1;
    base[1] = matrix[5] + y1;
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x1, y1, base[0], base[1]);
    return (0);
}