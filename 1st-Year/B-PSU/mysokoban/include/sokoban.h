/*
** EPITECH PROJECT, 2020
** 104intersection.h
** File description:
** minishell
*/

#ifndef MINI_H_
#define MINI_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "../lib/my/my.h"

#define SPACE_BAR 32
#define UP 65
#define DOWN 66
#define RIGHT 67
#define LEFT 68

typedef struct global global;
struct global
{
    char *str;
    char *input;
    char **map;
    char previous_case;
    char box_move;
    int rows;
    int cols;
    int input_ascii;
    int nb_o;
    int nb_x;
    int nb_p;
    int nb_hashtag;
    int pos_xp;
    int pos_yp;
    int action;
    int ac;
    char **av;
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

list *create_global_list(int ac, char **av);
int loop_create_list(global **game, list **list_o, l_list **node_o);
l_list *add_to_list(list **gbl, l_list **node, int i, int j);
l_list *add_first(list **gbl, l_list **node, int nb);
void del_last_first(list **gbl, l_list **node);
void del_to_list(list **gbl, l_list **node, int pos);
void destroy_first_l_list(list **gbl, l_list **node);
void destroy_list(list **gbl, l_list **node);
char *display(l_list *node);
global *create_struct(int ac, char **av);
void destroy_struct(global *game);
int helper(int ac, char **av);
char *read_map(int ac, char **av);
int calcul_row(char *str);
int calcul_col(char *str);
void ncurses_activation(void);
void ncurses_desactivation(void);
void move_charact(global **game, list **list_o, l_list **node_o);
int up_down(global **game, int stock_x, int stock_y, int val);
int right_left(global **game, int stock_x, int stock_y, int val);
void check_loose(global **game, int pos_x, int pos_y);
void display_map(global *game);
void leave_game(global *game, list **list_o, l_list **node_o);

#endif /* MINI_H_ */