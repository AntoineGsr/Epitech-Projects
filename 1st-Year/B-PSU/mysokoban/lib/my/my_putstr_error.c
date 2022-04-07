/*
** EPITECH PROJECT, 2020
** my_putstr_fast.c
** File description:
** lib
*/

#include "my.h"

int my_putstr_error(char const *str)
{
    write(2, str, my_strlen(str));
    return (0);
}
