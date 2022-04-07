/*
** EPITECH PROJECT, 2020
** str len
** File description:
** lenght of an str
*/

int my_strlen(char const *str)
{
    int n;

    for (n = 0; str[n] != '\0'; n++);

    return (n);
}
