/*
** EPITECH PROJECT, 2020
** my_strcapitalize.c
** File description:
** lib
*/

int verif_switchcase(char *str, int i)
{
    if (str[i] >= 'a' && str[i] <= 'z') {
        if (i == 0)
            return (-32);
        if ((str[i - 1] < 'a' || str[i - 1] > 'z')
            || (str[i - 1] < 'A' || str[i - 1] > 'Z'))
            return (-32);
    }
    if (str[i] >= 'A' && str[i] <= 'Z') {
        if (i == 0)
            return (0);
        if ((str[i - 1] >= 'a' && str[i - 1] <= 'z')
            || (str[i - 1] >= 'A' || str[i - 1] <= 'Z'))
            return (32);
    }
    return (0);
}

char *my_strcapitalize(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i] + verif_switchcase(str, i);
    }
    return (str);
}
