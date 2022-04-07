/*
** EPITECH PROJECT, 2020
** create_struct.c
** File description:
** my_ls
*/

#include "my_ls.h"

struct stat create_struct(char *av)
{
    struct stat data;

    stat(av, &data);
    return (data);
}