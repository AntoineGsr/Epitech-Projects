/*
** EPITECH PROJECT, 2020
** rev_str
** File description:
** reverse str
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int j = my_strlen(str) - 1;
    char switch_char;

    while (i < j)
    {
        switch_char = str[i];
        str[i] = str[j];
        str[j] = switch_char;
        j--;
        i++;
    }
    return (str);
}