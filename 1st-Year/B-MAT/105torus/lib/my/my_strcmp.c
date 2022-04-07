/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** lib
*/

int my_value(int value)
{
    if (value < 0)
        return (-1);
    if (value > 0)
        return (1);
    if (value == 0)
        return (0);
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int value;

    if (s1[i] == '\0' || s2[i] == '\0') {
        value =  (s1[i] - s2[i]);
        return (my_value(value));
    }
    for (i; s1[i] != '\0' || s2[i] != '\0'; i++) {
        if (s1[i] != s2[i]) {
            value = (s1[i]) - (s2[i]);
            return (my_value(value));
        }
    }
}
