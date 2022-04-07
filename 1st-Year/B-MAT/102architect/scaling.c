/*
** EPITECH PROJECT, 2020
** scaling.c
** File description:
** 102architect
*/

#include "102architect.h"

double scaling(char **av, int i, int ac, double *base)
{
    if (i + 3 > ac)
        exit(84);
    double x1 = atof(av[1]);
    double y1 = atof(av[2]);
    double z1 = 1;
    double a2 = atof(av[i + 1]);
    double b2 = atof(av[i + 2]);
    double c2 = 1;
    double coord[3] = {x1, y1, z1};
    double matrix[3][3] = {{a2, 0, 0}, {0, b2, 0}, {0, 0, c2}};
    double r_coord[3];

    printf("Scaling by factors %d and %d\n", (int)a2, (int)b2);
    printf("%.2f\t%.2f\t%.2f\n", matrix[0][0], matrix[0][1], matrix[0][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrix[1][0], matrix[1][1], matrix[1][2]);
    printf("%.2f\t%.2f\t%.2f\n", matrix[2][0], matrix[2][1], matrix[2][2]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            base[i] += matrix[i][j] * coord[j];
    }
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x1, y1, base[0], base[1]);
}