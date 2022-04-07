/*
** EPITECH PROJECT, 2020
** process info .c
** File description:
** process info .c
*/

#include <stdio.h>
#include <stdlib.h>

int get_tab_len(char **tab)
{
    int count_len = 0;
    for (int i = 0; tab[i] != NULL; i++) {
        count_len++;
    }
    return (count_len);
}