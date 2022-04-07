/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** n4s
*/

#include "../include/n4s.h"

int main(void)
{
    need_for_speed_t *gbl = create_struct();

    start_car(gbl);
    if (gbl->exit == 1)
        return (0);
    while (gbl->exit == 0) {
        parse_lidar(gbl);
        if (gbl->exit == 1) break;
        parse_speed(gbl);
        if (gbl->exit == 1) break;
        backward(gbl);
        if (gbl->exit == 1) break;
        forward(gbl);
        if (gbl->exit == 1) break;
        rotate(gbl);
    }
    stop_car(gbl);
    return (0);
}