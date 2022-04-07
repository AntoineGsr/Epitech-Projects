/*
** EPITECH PROJECT, 2020
** create_list.c
** File description:
** lib_antoine_gasser
*/

#include "../include/sokoban.h"

int loop_create_list(global **game, list **list_o, l_list **node_o)
{
    for (int i = 1; (*game)->map[i] != NULL; i++) {
        for (int j = 0; (*game)->map[i][j] != '\0'; j++) {
            if ((*game)->map[i][j] == 'O') {
                *node_o = add_to_list(list_o, node_o, i, j);
                if (*node_o == NULL) return (84);
            }
        }
    }
    return (0);
}

list *create_global_list(int ac, char **av)
{
    list *gbl = malloc(sizeof(list));

    if (gbl == NULL)
        return NULL;
    gbl->first = NULL;
    gbl->last = NULL;
    gbl->max_node = 0;
    return (gbl);
}