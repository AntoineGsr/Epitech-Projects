/*
** EPITECH PROJECT, 2021
** secondary function
** File description:
** sous fonction
*/

#include "function.h"

int find_sizefiles(char *str)
{
    struct stat info;

    stat(str, &info);
    return (info.st_size);
}

int intlen(int a)
{
    int i = 0;

    for (i; a > 0; a /= 10, i++);
    return (i);
}