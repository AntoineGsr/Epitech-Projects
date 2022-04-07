/*
** EPITECH PROJECT, 2020
** intersection_point.c
** File description:
** 104intersection
*/

#include "104intersection.h"

void solution_x1_x2(char **av, double a, double b, double c, double delta)
{
    double x1 = 0;
    double x2 = 0;
    double x = 0;
    double y = 0;
    double z = 0;

    if (delta < 0) {
        printf("No intersection point\n");
    }
    if (delta == 0) {
        printf("1 intersection point:\n");
        x1 = (-b) / (2 * a);
        x = atof(av[2]) + x1 * atof(av[5]);
        y = atof(av[3]) + x1 * atof(av[6]);
        z = atof(av[4]) + x1 * atof(av[7]);
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    }
    if (delta > 0) {
        printf("2 intersection points:\n");
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        x = atof(av[2]) + x1 * atof(av[5]);
        y = atof(av[3]) + x1 * atof(av[6]);
        z = atof(av[4]) + x1 * atof(av[7]);
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
        x = atof(av[2]) + x2 * atof(av[5]);
        y = atof(av[3]) + x2 * atof(av[6]);
        z = atof(av[4]) + x2 * atof(av[7]);
        printf("(%.3f, %.3f, %.3f)\n", x, y, z);
    }
}

int intersection_point(int ac, char **av)
{
    double a = 0;
    double b = 0;
    double c = 0;
    double R_R = pow(atof(av[8]), 2);
    double angle = (90.0 - atof(av[8])) / (180.0 / M_PI);
    double delta = 0;
    double x1 = 0;
    double x2 = 0;

    if (av[1][0] == '1') {
        a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2) + pow(atof(av[7]), 2);
        b = 2 * ((atof(av[2]) * atof(av[5])) + (atof(av[3]) * atof(av[6])) + (atof(av[4]) * atof(av[7])));
        c = pow(atof(av[2]), 2) + pow(atof(av[3]), 2) + pow(atof(av[4]), 2) - R_R;
        if (a == 0) {
            printf("There is an infinite number of intersection points.\n");
            return (0);
        }
        delta = (b * b) - 4 * (a * c);
        solution_x1_x2(av, a, b, c,delta);
    }
    if (av[1][0] == '2') {
        a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2);
        b = 2 * ((atof(av[2]) * atof(av[5])) + (atof(av[3]) * atof(av[6])));
        c = pow(atof(av[2]), 2) + pow(atof(av[3]), 2) - R_R;
        if (a == 0) {
            printf("There is an infinite number of intersection points.\n");
            return (0);
        }
        delta = (b * b) - 4 * (a * c);
        solution_x1_x2(av, a, b, c, delta);
    }
    if (av[1][0] == '3') {
        a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2) - (pow(atof(av[7]), 2) / pow(tan(angle), 2));
        b = 2 * ((atof(av[2]) * atof(av[5])) + (atof(av[3]) * atof(av[6])) - ((atof(av[4]) * atof(av[7])) / (tan(angle) * tan(angle))));
        c = pow(atof(av[2]), 2) + pow(atof(av[3]), 2) - (pow(atof(av[4]), 2) / pow(tan(angle), 2));
        if (a == 0) {
            printf("There is an infinite number of intersection points.\n");
            return (0);
        }
        delta = (b * b) - 4 * (a * c);
        solution_x1_x2(av, a, b, c, delta);
    }
}