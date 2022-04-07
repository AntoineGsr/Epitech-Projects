/*
** EPITECH PROJECT, 2020
** pushswap.h
** File description:
** pushswap
*/

#ifndef SWAP_H_
#define SWAP_H_

#include <stdio.h>
#include <stdlib.h>
#include "./lib/my/my.h"

typedef struct l_list l_list;
struct l_list
{
    int nb;
    l_list *previous;
    l_list *next;
};

typedef struct list list;
struct list
{
    int print;
    int nb_ac;
    int max;
    int nb_count;
    int sck_min;
    int nb_rotate;
    int pos;
    int t_rotate;
    int ra_rra;
    l_list *first;
    l_list *last;
};

int count_nb_args(int ac, char **av);

list *create_list(int ac, char **av);

l_list *add_to_list(list **gbl, l_list **l_a, int nb);

l_list *add_first(list **gbl, l_list **l_a, int nb);

l_list *del_to_list(list **gbl, l_list **l_a, int nb);

int verif_sort(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

l_list *find_minimum(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

l_list *rotate_la(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

l_list push_lb(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

l_list *bubble_sort(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

void sa_func(l_list **l_a, list **gbl);

void sb_func(l_list **l_b, list **gbl_b);

void sc_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

void pa_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

void pb_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

l_list *ra_func(l_list **l_a, list **gbl);

l_list *rb_func(l_list **l_a, list **gbl);

void rr_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

l_list *rra_func(l_list **l_a, list **gbl);

l_list *rrb_func(l_list **l_a, list **gbl);

void rrr_func(l_list **l_a, l_list **l_b, list **gbl, list **gbl_b);

list *print_action(list **gbl, char *action);

#endif /* SWAP_H_ */
