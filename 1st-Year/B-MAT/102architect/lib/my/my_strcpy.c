/*
** EPITECH PROJECT, 2020
** my_strcpy.c
** File description:
** lib
*/

void my_putchar(char c);

char *my_strcpy(char *dest, char const *src)
{
    for (int i = 0; src[i] != '\0'; i++)
        dest[i] = src[i];
    return (dest);
}
