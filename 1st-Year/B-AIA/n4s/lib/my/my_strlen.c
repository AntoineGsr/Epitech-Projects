/*
** EPITECH PROJECT, 2020
** my_strlen.c
** File description:
** lib
*/

int my_strlen(char const *str)
{
    char const *lol;

    for (lol = str; *str; ++str);
    return (str - lol);
}