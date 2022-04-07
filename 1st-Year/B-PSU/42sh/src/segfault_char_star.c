/*
** EPITECH PROJECT, 2021
** segfault inputs
** File description:
** display segfault and return NULL
*/

#include "include/my.h"

char *segfault_char_star(void)
{
    my_puterr("Segmentation fault\n");
    return (NULL);
}