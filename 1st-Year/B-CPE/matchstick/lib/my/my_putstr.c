/*
** EPITECH PROJECT, 2020
** my_putstr_fast.c
** File description:
** lib
*/

#include "my.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return (0);
}
