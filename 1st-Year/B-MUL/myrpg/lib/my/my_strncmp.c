/*
** EPITECH PROJECT, 2020
** str ncmp
** File description:
** strn cmp
*/

#include <unistd.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1[i] == '\0' && s2[i] == '\0')
        return (0);
    while (n > i && s1[i] == s2[i]) {
        if (s1[i] == '\0')
            return (0);
        i++;
    } return (s1[i] - s2[i]);
}
