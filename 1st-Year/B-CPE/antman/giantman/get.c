/*
** EPITECH PROJECT, 2020
** get the content of a node
** File description:
** fonction lst chainees
*/

#include "structure.h"

char *get(lst *list, int pos)
{
    lst *new = list;
    int i = 0;

    if (list == NULL)
        return NULL;
    while (i < pos) {
        i++;
        new = new->next;
    }
    return (new->str);
}