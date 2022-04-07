/*
** EPITECH PROJECT, 2020
** my_getnbr.c
** File description:
** .c
*/

int my_signe(char const *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '-')
            count++;
    if (count % 2 != 0) {
        return (-1);
    }
    return (1);
}

int my_getnbr(char const *str)
{
    int i = 0;
    int nbr = 0;
    int signe = my_signe(str);

    while (str[i] == '-' || str[i] == '+') {
        i++;
    }
    for (i; str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10 + (str[i] - 48);
        } else
            return (nbr * signe);
    }
    return (nbr * signe);
}
