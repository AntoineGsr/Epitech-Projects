/*
** EPITECH PROJECT, 2020
** my_strlowcase.c
** File description:
** lib
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
    }
    return (str);
}
