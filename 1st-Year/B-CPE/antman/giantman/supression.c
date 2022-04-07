/*
** EPITECH PROJECT, 2020
** suppression
** File description:
** fonction lst chainees
*/

#include "structure.h"
#include "function.h"

lst *suppression(lst *list)
{
    lst *new = list;
    lst *last = list;

    if (list == NULL)
        return (NULL);
    while (last->next != NULL) {
        new = last;
        last = last->next;
    }
    new->next = NULL;
    free(last);
    return (new);
}