/*
** EPITECH PROJECT, 2020
** initialistion lst chainee
** File description:
** fonction lst chainees
*/

#include "function.h"
#include "structure.h"

lst *initialisation_arg(char *newstr, char *newpos)
{
    lst *list = malloc(sizeof(*list));

    if (list == NULL)
        return NULL;
    list->str = newstr;
    list->pos = newpos;
    list->next = NULL;
    return (list);
}