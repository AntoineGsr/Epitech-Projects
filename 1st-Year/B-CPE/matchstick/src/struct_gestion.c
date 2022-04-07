/*
** EPITECH PROJECT, 2021
** struct_gestion.c
** File description:
** matchstick
*/

#include "../include/matchstick.h"

void create_struct_array(global **data)
{
    for (int i = 0; i < (*data)->rows; i++) {
        for (int j = 0; j < (i + 1) * 2 - 1; j++) {
            (*data)->sticks_line[i] += 1;
            (*data)->total_stick += 1;
        }
    }
}

global *create_struct(char **av)
{
    global *data = malloc(sizeof(global));

    if (data == NULL) return NULL;
    data->row_equal_one = 0;
    data->row_upper_one = 0;
    data->higher_line = 0;
    data->coord_higher_line = 0;
    data->rows = my_getnbr(av[1]);
    data->cols = 0;
    data->player_turn = -1;
    data->choose = 0;
    data->total_stick = 0;
    data->pick_stick = my_getnbr(av[2]);
    data->input = malloc(sizeof(char *) * 2);
    data->sticks_line = NULL;
    data->sticks_line = my_memset_int(data->rows);
    data->ctrl_d = 0;
    create_struct_array(&data);
    return (data);
}