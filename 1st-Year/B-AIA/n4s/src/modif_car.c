/*
** EPITECH PROJECT, 2021
** modif_car.c
** File description:
** n4s
*/

#include "../include/n4s.h"

void forward(need_for_speed_t *gbl)
{
    size_t len = 0;

    if (gbl->is_backing == 1) return;
    if (atof(gbl->parse_capt[16]) > 900 && gbl->wheel_dir == 0) {
        my_putstr("CAR_FORWARD:1\n");
        gbl->speed = 1;
    } else {
        if (gbl->wheel_dir > 0.2) {
            my_putstr("CAR_FORWARD:0.25\n");
            gbl->speed = 0.25;
        } else {
            my_putstr("CAR_FORWARD:0.6\n");
            gbl->speed = 0.6;
        }
    }
    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 5) {
        gbl->exit = 1;
        return;
    }
    check_end(gbl, 3);
}

int verif_backward(need_for_speed_t *gbl)
{
    size_t len = 0;

    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 5) {
        gbl->exit = 1;
        return (1);
    }
    check_end(gbl, 3);
    return (0);
}

void backward(need_for_speed_t *gbl)
{
    size_t len = 0;

    for (int i = 0; i < 32; i++) {
        if (atof(gbl->parse_capt[i]) == 0) {
            my_putstr("WHEELS_DIR:0\n");
            gbl->wheel_dir = 0;
            if (verif_backward(gbl) == 1) return;
            my_putstr("CAR_BACKWARDS:1\n");
            gbl->speed = -1;
            gbl->is_backing = 1;
            if (verif_backward(gbl) == 1) return;
            my_putstr("CYCLE_WAIT:10\n");
            getline(&gbl->buff, &len, stdin);
            return;
        }
        gbl->is_backing = 0;
    }
    if (my_strlen(gbl->buff) < 5)
        gbl->exit = 1;
}