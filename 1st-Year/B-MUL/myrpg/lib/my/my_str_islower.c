/*
** EPITECH PROJECT, 2020
** my_str_islower
** File description:
** is lower
*/

int my_str_islower(char const *str)
{
    if (str == "")
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < 'a' || str[i] > 'z')
            return (0);
    return (1);
}
