/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** /
*/

int my_strcmp(char *s1, char *s2)
{
    int	i = 0;
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            int val = s1[i] - s2[i];
            return val;
        } else {
            i++;
        }
    }
    return 0;
}
