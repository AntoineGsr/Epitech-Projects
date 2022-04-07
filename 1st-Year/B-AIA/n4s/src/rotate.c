/*
** EPITECH PROJECT, 2021
** rotate.c
** File description:
** n4s
*/

#include "../include/n4s.h"

static float calc_rotation(float forward_capt, float side_capt)
{
    float first_calc = side_capt * side_capt + forward_capt * forward_capt;
    float snd_calc = 2 * forward_capt * side_capt * 0.8829;
    float last_side = first_calc - snd_calc;
    float num_angle = 0;
    float denum_angle = 0;
    float rotation = 0;

    last_side = sqrtf(last_side);
    num_angle = last_side * last_side + forward_capt * forward_capt
    - side_capt * side_capt;
    denum_angle = 2 * last_side * forward_capt;
    rotation = num_angle / denum_angle;
    rotation = acosf(rotation);
    rotation = rotation / 8;
    if (rotation > 1)
        rotation = 1;
    if (rotation < -1)
        rotation = -1;
    return (rotation);
}

void verif_turn(need_for_speed_t *gbl)
{
    size_t len = 0;

    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 5) {
        gbl->exit = 1;
        return;
    }
    check_end(gbl, 3);
}

static void turn_right(need_for_speed_t *gbl)
{
    float left_capt = atof(gbl->parse_capt[0]);
    float right_capt = atof(gbl->parse_capt[31]);
    float forward_capt = atof(gbl->parse_capt[16]);
    float rotation = 0;

    if (left_capt > 300 && forward_capt > 1000) {
        my_putstr("WHEELS_DIR:0\n");
        gbl->wheel_dir = 0;
    } else {
        rotation = calc_rotation(forward_capt, right_capt);
        printf("WHEELS_DIR:-%f\n", rotation);
        fflush(stdout);
        gbl->wheel_dir = rotation;
    }
    verif_turn(gbl);
}

static void turn_left(need_for_speed_t *gbl)
{
    float left_capt = atof(gbl->parse_capt[0]);
    float right_capt = atof(gbl->parse_capt[31]);
    float forward_capt = atof(gbl->parse_capt[16]);
    float rotation = 0;

    if (right_capt > 300 && forward_capt > 1000) {
        my_putstr("WHEELS_DIR:0\n");
        gbl->wheel_dir = 0;
    } else {
        rotation = calc_rotation(forward_capt, left_capt);
        printf("WHEELS_DIR:%f\n", rotation);
        fflush(stdout);
        gbl->wheel_dir = rotation;
    }
    verif_turn(gbl);
}

void rotate(need_for_speed_t *gbl)
{
    float left_capt = atof(gbl->parse_capt[0]);
    float right_capt = atof(gbl->parse_capt[31]);

    if (gbl->is_backing == 1)
        return;
    if (left_capt < right_capt) {
        turn_right(gbl);
        return;
    }
    if (right_capt < left_capt) {
        turn_left(gbl);
        return;
    }
    my_putstr("WHEELS_DIR:0\n");
    verif_turn(gbl);
    gbl->wheel_dir = 0;
}
