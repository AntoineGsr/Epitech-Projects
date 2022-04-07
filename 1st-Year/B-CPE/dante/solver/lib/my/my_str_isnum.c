/*
** EPITECH PROJECT, 2020
** B-CPE-110-NCY-1-1-BSQ-sebastien.raoult
** File description:
** my_str_isnum
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i]) {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}
