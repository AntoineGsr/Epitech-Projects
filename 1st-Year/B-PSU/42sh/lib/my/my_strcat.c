/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** create a string with the 2 strings in parameters
*/

#include "../../include/my.h"

char *my_strcat(char *str1, char *str2)
{
    int len1 = my_strlen(str1);
    int len2 = my_strlen(str2);
    int size = len1 + len2;
    int k = 0;
    char *new_str = malloc(sizeof(char) * (size + 1));

    for (int i = 0; i < len1; i++, k++) {
        new_str[k] = str1[i];
    }
    for (int i = 0; i < len2; i++, k++) {
        new_str[k] = str2[i];
    }
    new_str[size] = '\0';
    return (new_str);
}