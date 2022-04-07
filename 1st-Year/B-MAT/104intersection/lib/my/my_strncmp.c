/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** lib
*/

int my_value(int value);

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int value = 0;

    while (s1[i] == s2[i] && i <= n - 1) {
        if (s1[i] == '\0' && s2[i] == '\0') {
            value = s1[i - 1] - s2[i - 1];
            return (my_value(value));
        }
        i++;
    }
    value =  s1[i] - s2[i];
    return (my_value(value));
}
