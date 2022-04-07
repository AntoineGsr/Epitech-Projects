/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

float previous_time(sfTime time)
{
    float previous = time.microseconds / 1000000.0;

    return (previous);
}

int count_sep(char *str, char sep)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == sep) {
            count++;
        }
    } return (count);
}