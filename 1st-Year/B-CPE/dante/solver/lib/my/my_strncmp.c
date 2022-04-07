/*
** EPITECH PROJECT, 2020
** CPool Day 06
** File description:
** my_stnrcmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (i = 0; s1[i] == s2[i]; i++) {
        --n;
        if (n == 0)
            return (0);
    }
    return (s1[i] - s2[i]);
}
