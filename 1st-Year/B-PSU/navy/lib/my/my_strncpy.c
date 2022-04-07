/*
** EPITECH PROJECT, 2020
** my_strncpy.c
** File description:
** lib
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    for (i; i != n; i++) {
        dest[i] = src[i];
        if (src[i] == '\0') {
            dest[i + 1] = '\0';
            return (dest);
        }
    }
    return (dest);
}
