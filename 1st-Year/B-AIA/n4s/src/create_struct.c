/*
** EPITECH PROJECT, 2021
** create_struct.c
** File description:
** ²n4s
*/

#include "../include/n4s.h"

need_for_speed_t *create_struct(void)
{
    need_for_speed_t *gbl = malloc(sizeof(need_for_speed_t));

    if (gbl == NULL)
        return NULL;
    gbl->parse_capt = malloc(sizeof(char *) * 33);
    if (gbl->parse_capt == NULL)
        return NULL;
    gbl->buff = NULL;
    gbl->speed = 1;
    gbl->wheel_dir = 0;
    gbl->is_backing = 0;
    gbl->elapsed_time = 0;
    gbl->exit = 0;
    return (gbl);
}