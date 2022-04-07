/*
** EPITECH PROJECT, 2021
** STRUCTURE
** File description:
** STRUCTURE
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "antman.h"

typedef struct l_list l_list;
struct l_list
{
    char *value;
    int code;
    int frequency;
    l_list *previous;
    l_list *next;
};

typedef struct list list;
struct list
{
    int total_dico;
    int high_frequency;
    int max_code;
    int code_memory;
    char *av1;
    l_list *first;
    l_list *last;
};

typedef struct compression compression;
struct compression
{
    char *file;
    char *av1;
    char av2;
};

#endif /* STRUCT_H_ */