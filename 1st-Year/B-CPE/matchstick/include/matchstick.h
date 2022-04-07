/*
** EPITECH PROJECT, 2020
** 104intersection.h
** File description:
** minishell
*/

#ifndef MATCH_H_
#define MATCH_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../lib/my/my.h"

typedef struct global global;
struct global
{
    int row_equal_one;
    int row_upper_one;
    int higher_line;
    int coord_higher_line;
    char **input;
    int *sticks_line;
    int total_stick;
    int rows;
    int cols;
    int pick_stick;
    int player_turn;
    int choose;
    int ctrl_d;
};

typedef struct l_list l_list;
struct l_list
{
    int pos_x;
    int pos_y;
    l_list *previous;
    l_list *next;
};

typedef struct list list;
struct list
{
    int max_node;
    l_list *first;
    l_list *last;
};

int error_gestion(int ac, char **av);
global *create_struct(char **av);
void display_map(global *data);
int game_gestion(global **data);
int input_error(global **data, int turn);
void verif_turn_player(global **data, int *turn);
int player_turn(global **data, int turn);
int input_not_range(global **data, int turn);
void display_player_action(global **data, int turn);
void calcul_sticks_row(global **data);
int pick_higher_nb(global **data);
int optimise_stick_pick(global **data);
int pick_one_stick(global **data);

#endif /* MATCH_H_ */