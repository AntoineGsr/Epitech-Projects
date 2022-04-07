/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** mysh
*/

#include "../../include/my.h"

int my_strlen(char *str)
{
    int len = 0;

    for (int i = 0; str[i]; i++) {
        len++;
    }
    return (len);
}
