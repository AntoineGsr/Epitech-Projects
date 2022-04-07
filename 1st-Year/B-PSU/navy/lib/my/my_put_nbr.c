/*
** EPITECH PROJECT, 2020
** my_put_nbr.c
** File description:
** lib
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    long nb2 = nb;

    if (nb2 < 0) {
        nb2 = nb2 * (-1);
        my_putchar('-');
    }
    if (nb2 >= 10) {
        my_put_nbr(nb2 / 10);
    }
    my_putchar((nb2 % 10) + 48);
    return (0);
}
