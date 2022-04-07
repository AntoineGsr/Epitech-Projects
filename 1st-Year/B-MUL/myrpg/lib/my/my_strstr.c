/*
** EPITECH PROJECT, 2025
** my_strstr
** File description:
** compare two str
*/

#include "my.h"

char *my_strstr(char *str, char const *to_find)
{
    int check = 0;

    for (int i = 0; i <= my_strlen(str); i++) {
        if (str[i] == to_find[check]) {
            check++;
            if (check == my_strlen(to_find))
                return (&str[(i - my_strlen(to_find) + 1)]);
        }
        else
            check = 0;
    }
    return (0);
}