/*
** EPITECH PROJECT, 2020
** my_strlowcase
** File description:
** maj to min
*/

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] <= 'Z' && str[i] >= 'A')
            str[i] += 32;
    return (str);
}
