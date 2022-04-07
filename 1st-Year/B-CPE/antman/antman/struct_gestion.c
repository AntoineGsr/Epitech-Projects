/*
** EPITECH PROJECT, 2021
** struct_gestion.c
** File description:
** antman
*/

#include "../include/antman.h"

list *create_gbl_dico(compression *antman, char **av)
{
    list *gbl = malloc(sizeof(list));

    if (gbl == NULL)
        return (NULL);
    gbl->first = NULL;
    gbl->last = NULL;
    gbl->total_dico = 0;
    gbl->high_frequency = 0;
    gbl->max_code = 0;
    gbl->av1 = my_memset_char(my_strlen(av[1]));
    gbl->av1 = av[1];
    gbl->code_memory = 0;
    return (gbl);
}

compression *create_struct(int ac, char **av)
{
    compression *elem = malloc(sizeof(compression));

    if (elem == NULL || ac < 3)
        return NULL;
    elem->file = NULL;
    elem->av1 = my_memset_char(my_strlen(av[1]));
    elem->av1 = av[1];
    elem->av2 = av[1][0];
    return (elem);
}

void destroy_elem(list **gbl, l_list **elem)
{
    (*gbl)->first = (*elem)->next;
    (*elem)->next = NULL;
    (*elem)->previous = NULL;
    free(*elem);
    (*elem) = (*gbl)->first;
}

void destroy_dico(list **gbl, l_list **elem)
{
    while ((*gbl)->first != NULL) {
        destroy_elem(gbl, elem);
    }
    free(*gbl);
}

void destroy_allocation(compression *antman, list **gbl, l_list **elem)
{
    free(antman->file);
    free(antman);
    destroy_dico(gbl, elem);
}