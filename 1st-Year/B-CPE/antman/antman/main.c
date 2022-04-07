/*
** EPITECH PROJECT, 2021
** main
** File description:
** fonction principale
*/

#include "../include/antman.h"

int main(int ac, char **av)
{
    compression *antman = create_struct(ac, av);
    list *gbl = NULL;
    l_list *elem = NULL;

    if (ac != 3)
        return (84);
    if (error_handler(av, antman) == 84)
        return (84);
    if (av[2][0] != '1')
        return (0);
    gbl = create_gbl_dico(antman, av);
    elem = malloc(sizeof(l_list));
    if (small_file(antman) == 0) {
        complete_dictionary(&gbl, &elem, antman);
        free(elem->value);
    }
    destroy_allocation(antman, &gbl, &elem);
    return (0);
}