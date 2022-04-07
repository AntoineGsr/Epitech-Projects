/*
** EPITECH PROJECT, 2020
** 104intersection.h
** File description:
** n4s
*/

#ifndef N4S_H_
#define N4S_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "../lib/my/my.h"

typedef struct need_for_speed_s {
    char **parse_capt;
    float speed;
    float wheel_dir;
    char *buff;
    int is_backing;
    float elapsed_time;
    int exit;
} need_for_speed_t;

char **my_str_to_word_array_separator_struct(char *av, char sep);
need_for_speed_t *create_struct(void);
void start_car(need_for_speed_t *gbl);
void stop_car(need_for_speed_t *gbl);
void parse_lidar(need_for_speed_t *gbl);
void parse_speed(need_for_speed_t *gbl);
void forward(need_for_speed_t *gbl);
void rotate(need_for_speed_t *gbl);
void backward(need_for_speed_t *gbl);
char *parse_end_game(char *av, char sep, int nb_sep);
void check_end(need_for_speed_t *gbl, int nb_sep);

#endif /* N4S_H_ */