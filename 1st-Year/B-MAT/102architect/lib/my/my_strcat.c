/*
** EPITECH PROJECT, 2020
** my_strcat.c
** File description:
** lib
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int destsize = my_strlen(dest);
    int i = 0;

    for (i; src[i] != '\0'; i++) {
        dest[destsize + i] = src[i];
    }
    dest[destsize + i] = '\0';
    return (dest);
}
