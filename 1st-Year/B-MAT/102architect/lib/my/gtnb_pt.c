/*
** EPITECH PROJECT, 2020
** my_getnbr_print.c
** File description:
** lib
*/

int gtnb_pt(char const *str)
{
    int i = 0;
    int nbr = 0;

    while (str[i] == '.') {
        i++;
    }
    for (i; str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10 + (str[i] - 48);
        } else
            return (nbr);
    }
    return (nbr);
}
