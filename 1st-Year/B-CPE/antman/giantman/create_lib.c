/*
** EPITECH PROJECT, 2021
** create_lib.c
** File description:
** giantman
*/

#include "function.h"
#include "structure.h"

int verif_boolean(int *boolean, char *temp, lst *copy)
{
    if (my_strcmp(temp, copy->str) == 0)
        *boolean = 1;
}

void one_character(giantman **use, lst *copy, char *temp, int i)
{
    int boolean = 0;

    temp = my_memset_char(2);
    temp[0] = (*use)->files[i];
    if (i == 0) {
        (*use)->lib = initialisation_arg(temp, my_getstr((*use)->a));
        (*use)->x++;
        (*use)->a++;
    } else {
        while (copy->next != NULL) {
            verif_boolean(&boolean, temp, copy);
            copy = copy->next;
        }
        if (boolean == 0) {
            insertion_pos((*use)->lib, temp, my_getstr((*use)->a), (*use)->x);
            (*use)->x++;
            (*use)->a++;
        }
    }
}

int more_character(giantman **use, lst *copy, char *temp, int i)
{
    int tmp = i;
    int z = 0;
    int num = 0;

    temp = my_memset_char(15);
    for (; (*use)->files[tmp] >= '0' && (*use)->files[tmp] <= '9'; z++, i++) {
        num *= 10;
        num += (*use)->files[tmp] - '0';
        tmp++;
    }
    for (int b = 1; b < num && copy->next != NULL; b++)
        copy = copy->next;
    temp = my_strcat(temp, copy->str);
    temp[my_strlen(temp)] = (*use)->files[tmp];
    insertion_pos((*use)->lib, temp, my_getstr((*use)->a), (*use)->x);
    (*use)->x++;
    (*use)->a++;
    i--;
    return (i);
}

void put_letters_lib(giantman *use, int i)
{
    char *temp = NULL;
    lst *copy = malloc(sizeof(lst));

    for (i; use->files[i] != '\0'; i++) {
        copy = use->lib;
        if (use->files[i] < '0' || use->files[i] > '9') {
            one_character(&use, copy, temp, i);
        } else
            i = more_character(&use, copy, temp, i);
    }
    free(temp);
}