/*
** EPITECH PROJECT, 2020
** process info .c
** File description:
** process info .c
*/

#include <stdio.h>
#include <stdlib.h>

void my_putstr(char const *str);

void print_tab_char(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
    }
}