/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** lib
*/

void my_putchar(char c);

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    for (i; src[i] != '\0'; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}
