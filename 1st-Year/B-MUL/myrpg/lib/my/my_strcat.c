/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** str cat
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char const *str1, char const *str2)
{
    char *str_unified = malloc(sizeof(char) *
    (my_strlen(str1) + my_strlen(str2) + 1));
    int i;
    for (i = 0; str1[i]; i++)
        str_unified[i] = str1[i];
    for (int j = 0; str2[j]; j = j + 1, i++) {
        str_unified[i] = str2[j];
    } str_unified[i] = '\0';
    return (str_unified);
}
