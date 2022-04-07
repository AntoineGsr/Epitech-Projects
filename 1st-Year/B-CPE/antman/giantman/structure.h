/*
** EPITECH PROJECT, 2020
** myopen.c
** File description:
** giantman
*/

#ifndef STRUCT
#define STRUCT

#include <stdio.h>
#include <stdlib.h>
#include "../lib/my/my.h"

typedef struct lst lst;
struct lst
{
    char *str;
    char *pos;
    lst *next;
};

char *get(lst *, int);
lst *initialisation(void);
lst *initialisation_arg(char *, char *);
lst *insertion(lst *, char *);
lst *insertion_pos(lst *, char *, char *, int);
lst *suppression(lst *);
lst *suppression_pos(lst *, int);
lst *suppression(lst *);

#endif /* STRUCT */