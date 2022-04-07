/*
** EPITECH PROJECT, 2021
** parsing.c
** File description:
** n4s
*/

#include "../include/n4s.h"

void parse_lidar(need_for_speed_t *gbl)
{
    size_t len = 0;

    my_putstr("GET_INFO_LIDAR\n");
    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 35) {
        gbl->exit = 1;
        return;
    }
    check_end(gbl, 35);
    for (int i = 0; i < 32; i++) {
        free(gbl->parse_capt[i]);
    }
    gbl->parse_capt = my_str_to_word_array_separator(gbl->buff + 22, ':');
}

void parse_speed(need_for_speed_t *gbl)
{
    size_t len = 0;

    my_putstr("GET_CURRENT_SPEED\n");
    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 22) {
        gbl->exit = 1;
        return;
    }
    check_end(gbl, 4);
    gbl->speed = my_getnbr(gbl->buff + 22);
}