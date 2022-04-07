/*
** EPITECH PROJECT, 2021
** start_stop.c
** File description:
** n4s
*/

#include "../include/n4s.h"

static int compare_track_cleared(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (my_strlen(s1) < n || my_strlen(s2) < n)
        return (1);
    while (i < n && s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i])
            return (1);
        i++;
    }
    if (i < n)
        return (1);
    return (0);
}

void check_end(need_for_speed_t *gbl, int nb_sep)
{
    char *parse = parse_end_game(gbl->buff, ':', nb_sep);

    if (compare_track_cleared(parse, "Track Cleared", 13) == 0)
        gbl->exit = 1;
}

void start_car(need_for_speed_t *gbl)
{
    size_t len = 0;

    my_putstr("START_SIMULATION\n");
    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 5) {
        gbl->exit = 1;
        return;
    }
    my_putstr("GET_INFO_LIDAR\n");
    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 5) {
        gbl->exit = 1;
        return;
    }
    gbl->parse_capt = my_str_to_word_array_separator(gbl->buff + 22, ':');
}

int stop_end(need_for_speed_t *gbl)
{
    size_t len = 0;

    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 5) {
        gbl->exit = 1;
        return (1);
    }
    my_putstr("CYCLE_WAIT:15\n");
    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 5) {
        gbl->exit = 1;
        return (1);
    }
    my_putstr("STOP_SIMULATION\n");
    getline(&gbl->buff, &len, stdin);
    if (my_strlen(gbl->buff) < 5) {
        gbl->exit = 1;
        return (1);
    }
    return (0);
}

void stop_car(need_for_speed_t *gbl)
{
    my_putstr("CAR_FORWARD:0\n");
    if (stop_end(gbl) == 1) return;
    for (int i = 0; i < 33; i++)
        free(gbl->parse_capt[i]);
    free(gbl->parse_capt);
    free(gbl->buff);
    free(gbl);
}