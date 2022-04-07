/*
** EPITECH PROJECT, 2021
** is_same_str
** File description:
** mysh
*/

#include "../../include/my.h"

int is_same_str(char *str1, char *str2)
{
    int len_str1 = my_strlen(str1);

    if (len_str1 != my_strlen(str2)) {
        return (0);
    }
    for (int i = 0; i < len_str1; i++) {
        if (str1[i] != str2[i]) {
            return (0);
        }
    }
    return (1);
}
