/*
** EPITECH PROJECT, 2021
** B-PSU-101-NCY-1-1-bsminishell1-sebastien.raoult
** File description:
** my_count_word_array
*/

#include "my.h"

size_t my_count_word_array(char * const *tab)
{
    int i = 0;

    for (i = 0; tab[i]; i++);
    return (i);
}
