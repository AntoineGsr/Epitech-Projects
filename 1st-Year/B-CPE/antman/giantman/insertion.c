/*
** EPITECH PROJECT, 2020
** insertion
** File description:
** fonction lst chainees
*/

#include "structure.h"

lst *insertion(lst *list, char *newnbr)
{
    lst *new = malloc(sizeof(*new));
    lst *prec = list;

    if (list == NULL)
        return (NULL);
    if (new != NULL) {
        new->str = newnbr;
        new->next = NULL;
    }
    while (prec->next != NULL)
        prec = prec->next;
    prec->next = new;
    return (list);
}