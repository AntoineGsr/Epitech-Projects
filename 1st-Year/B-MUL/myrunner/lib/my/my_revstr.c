/*
** EPITECH PROJECT, 2020
** my_revstr.c
** File description:
** lib
*/

int my_strlen(char const *str);

char *my_revstr(char *str)
{
    int length = my_strlen(str) - 1;
    int lengthstock = length;
    int array[length];
    int i = 0;

    for (length; length >= 0; length--)
        array[length] = str[length];
    for (i; i <= lengthstock; i++)
        str[i] = array[lengthstock - i];
    return (str);
}
