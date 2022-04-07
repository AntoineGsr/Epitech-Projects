/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** pushswap
*/

#include "pushswap.h"

int main(int ac, char **av)
{
    list *gbl = create_list(ac, av);
    list *gbl_b = create_list(ac, av);
    l_list *l_a = malloc(sizeof(l_list));
    l_list *l_b = malloc(sizeof(l_list));

    if (gbl->max < ac - 2 || ac == 1)
        return (84);
    for (int i = 1; i < ac; i++) {
        if ((av[i][0] < '0' || av[i][0] > '9') && av[i][0] != '-')
            return (84);
        l_a = add_to_list(&gbl, &l_a, my_getnbr(av[i]));
    }
    l_a = gbl->first;
    bubble_sort(&l_a, &l_b, &gbl, &gbl_b);
    my_putchar('\n');
    return (0);
}