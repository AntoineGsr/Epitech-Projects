/*
** EPITECH PROJECT, 2020
** my_strupcase.c
** File description:
** lib
*/

char *my_strupcase(char *str)
{
    int i = 0;

    for (i; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - 32;
    }
    return (str);
}
