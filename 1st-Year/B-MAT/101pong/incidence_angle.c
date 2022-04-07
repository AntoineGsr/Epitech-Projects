/*
65;6003;1c** EPITECH PROJECT, 2020
** incidence_angle.c
** File description:
** 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "./lib/my/my.h"

double incidence_angle(double *B, double *v_v, double *ball_coord)
{
    double scal = 0.000000;
    double norm_v_z0 = 0.000000;
    double norm_v_v = 0.000000;
    double cos_angle = 0.000000;
    double arc_angle = 0.000000;

    scal = v_v[0] * v_v[0] + v_v[1] * v_v[1];
    norm_v_z0 = sqrt(v_v[0] * v_v[0] + v_v[1] * v_v[1] + v_v[2] * v_v[2]);
    norm_v_v = sqrt(v_v[0] * v_v[0] + v_v[1] * v_v[1]);
    cos_angle = scal / (norm_v_z0 * norm_v_v);
    arc_angle = acos(cos_angle) * (180 / M_PI);
    if ((B[2] >= 0 && ball_coord[2] < B[2]) || (B[2] <= 0 && ball_coord[2] > B[2])) {
        if (B[2] != 0 || ball_coord[2] != 0)
            printf("The incidence angle is:\n%.2f degrees\n", arc_angle);
    } else
        printf("The ball won't reach the paddle.\n");
    return (0);
}
