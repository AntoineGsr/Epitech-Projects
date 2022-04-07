/*
** EPITECH PROJECT, 2020
** my_str_isalpha
** File description:
** is alpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if ((str[i] > 'A' && str[i] < 'Z')
            || (str[i] > 'a' && str[i] < 'z'));
        else
            return (0);
    }
    return (1);
}