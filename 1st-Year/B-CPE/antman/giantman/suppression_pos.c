/*
** EPITECH PROJECT, 2020
** suppresion at a position gift
** File description:
** fonction lst chainees
*/

#include "structure.h"
#include "function.h"

lst *suppression_pos(lst *list, int pos)
{
    lst *new = list;
    lst *prec = list;
    lst *cur = list;

    if (list == NULL)
        return (NULL);
    if (pos == 0) {
        list = list->next;
        return (list);
    }
    for (int i = 0; i < pos && new != NULL; i++) {
        prec = new;
        new = new->next;
        cur = new->next;
    }
    prec->next = cur;
    free(new);
    return (list);
}
