/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** premier ou pas
*/

int my_is_prime(int nb)
{
    if (nb <= 1 || nb > 2147483647)
        return (0);
    for (int i = 2 ; nb >= i ; i++)
        for (int j = 2 ; nb >= j ; j++)
            if (i * j == nb)
                return (0);
    return (1);
}
