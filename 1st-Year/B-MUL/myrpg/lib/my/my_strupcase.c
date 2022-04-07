/*
** EPITECH PROJECT, 2020
** my_strupcase
** File description:
** minuscule into majuscule
*/

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] <= 'z' && str[i] >= 'a')
            str[i] -= 32;
    return (str);
}
