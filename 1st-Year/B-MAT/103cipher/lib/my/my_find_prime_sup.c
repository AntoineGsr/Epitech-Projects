/*
** EPITECH PROJECT, 2020
** my_find_prime_sup.c
** File description:
** lib
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int i;
    int compt = 0;
    int nb1;

    for (nb; nb <= 2147483647; nb++) {
        nb1 = my_is_prime(nb);
        if (nb1 == 1) {
            return (nb);
        }
    }
}
