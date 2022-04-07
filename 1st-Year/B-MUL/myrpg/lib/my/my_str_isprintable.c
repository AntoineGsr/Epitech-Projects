/*
** EPITECH PROJECT, 2020
** my_str_isprintable
** File description:
** is printable
*/

int my_str_isprintable(char const *str)
{
    if (str == "")
        return (1);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < ' ' || str[i] > '~')
            return (0);
    return (1);
}
