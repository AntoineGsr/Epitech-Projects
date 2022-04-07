/*
** EPITECH PROJECT, 2020
** rotation.c
** File description:
** 102architect
*/

#include "102architect.h"

double rotation(char **av, int i, int ac, double *base)
{
    if (i + 2 > ac)
        exit(84);
    double x1 = atof(av[1]);
    double y1 = atof(av[2]);
    double z1 = 1;
    double a2 = cos(atof(av[i + 1]) / (180 / M_PI));
    double b2 = sin(atof(av[i + 1]) / (180 / M_PI));
    double c2 = 1;
    double coord[3] = {x1, y1, z1};
    double rotate_mx[3][3] = {{a2, -b2, 0}, {b2, a2, 0}, {0, 0, c2}};
    double r_coord[3];

    printf("Rotation by a %d degree angle\n", (int)atof(av[i + 1]));
    printf("%.2f\t%.2f\t%.2f\n", rotate_mx[0][0], rotate_mx[0][1], rotate_mx[0][2]);
    printf("%.2f\t%.2f\t%.2f\n", rotate_mx[1][0], rotate_mx[1][1], rotate_mx[1][2]);
    printf("%.2f\t%.2f\t%.2f\n", rotate_mx[2][0], rotate_mx[2][1], rotate_mx[2][2]);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            base[i] += rotate_mx[i][j] * coord[j];
    }
    printf("(%.2f, %.2f) => (%.2f, %.2f)\n", x1, y1, base[0], base[1]);
}