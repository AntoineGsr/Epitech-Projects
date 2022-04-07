/*
** EPITECH PROJECT, 2020
** velocity.c
** File description:
** 
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include "./lib/my/my.h"

float *incidence_angle(double *B, double *result, double *ball_coord);

float *at_time(double *B, double *result, char *n)
{
    int time = my_getnbr(n);
    double ball_coord[3];

    printf("At time t + %d, ball coordinates will be:\n(", time);
    for (int i = 0; i < 3; i++) {
        result[i] = result[i] * time;
        ball_coord[i] = result[i] + B[i];
        if (i + 1 < 3) {
            printf("%.2f, ", ball_coord[i]);
        } else
            printf("%.2f)\n", ball_coord[i]);
    }
    incidence_angle(B, result, ball_coord);
    return (0);
}

float *velocity(char *x1, char *y1, char *z1, char *x2, char *y2,
char *z2, char *n)
{
    double A[3] = {atof(x1), atof(y1), atof(z1)};
    double B[3] = {atof(x2), atof(y2), atof(z2)};
    double result[3];

    printf("The velocity vector of the ball is:\n(");
    for (int i = 0; i < 3; i++) {
        result[i] = B[i] - A[i];
        if (i + 1 < 3) {
            printf("%.2f, ", result[i]);
        } else
            printf("%.2f)\n", result[i]);
    }
    at_time(B, result, n);
    return (0);
}
