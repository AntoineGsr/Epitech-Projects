/*
** EPITECH PROJECT, 2020
** insertion avec postion lst chainee
** File description:
** fonction lst chainees
*/

#include "structure.h"

void new_not_null(lst **new, char *newstr, char *newpos, int pos)
{
    if (*new != NULL) {
        (*new)->str = newstr;
        (*new)->pos = newpos;
        (*new)->next = NULL;
    }
}

lst *insertion_pos(lst *list, char *newstr, char *newpos, int pos)
{
    lst *new = malloc(sizeof(lst));
    lst *prec = list;
    lst *cur = list;

    if (list == NULL) return (NULL);
    new_not_null(&new, newstr, newpos, pos);
    if (pos == 0) {
        new->str = newstr;
        new->pos = newpos;
        new->next = cur;
        return (new);
    }
    for (int i = 0; i < pos; i++) {
        prec = cur;
        cur = cur->next;
    }
    prec->next = new;
    new->next = cur;
    return (new);
}