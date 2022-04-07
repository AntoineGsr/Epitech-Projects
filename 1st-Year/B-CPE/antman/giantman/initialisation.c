/*
** EPITECH PROJECT, 2020
** initialistion less argument
** File description:
** fonction lst chainees
*/

#include "structure.h"

lst *initialisation(void)
{
    lst *list = malloc(sizeof(*list));

    if (list == NULL)
        return NULL;
    list->str = NULL;
    list->pos = NULL;
    list->next = NULL;
    return (list);
}
