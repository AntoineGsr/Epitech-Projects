/*
** EPITECH PROJECT, 2020
** my_str_isnum
** File description:
** is num
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9');
        else
            return (0);
    }
    return (1);
}
