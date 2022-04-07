/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr_two(char const *str, long nbr, int i)
{
    if (str[0] >= '0' && str[0] <= '9')
        for (i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
            nbr = nbr * 10 + (str[i] - 48);
            if (nbr < -2147483648 || nbr > 2147483647)
                return (0);
        }
    return (nbr);
}

int my_getnbr(char const *str)
{
    int moins = 0;
    int i;
    long nbr;

    if ((str[0] != '-' || str[0] != '+') || (str[0] < '0' || str[0] > '9'))
        nbr = 0;
    if (str[0] == '-' || str[0] == '+') {
        for (i = 0; str[i] == '-' || str[i] == '+'; i++)
            if (str[i] == '-')
                moins++;
        for (; str[i] >= '0' && str[i] <= '9'; i++)
            nbr = nbr * 10 + (str[i] - 48);
        if (moins % 2 == 1)
            nbr = nbr * (-1);
    }
    return (my_getnbr_two(str, nbr, i));
}
