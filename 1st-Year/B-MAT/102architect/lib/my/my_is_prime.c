/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** lib
*/

int my_is_prime(int nb)
{
    int i;
    int compt = 0;

    if (nb <= 1) {
        return (0);
    }
    for (i = 1; i <= nb; i++) {
        if (nb % i == 0) {
            compt = compt + 1;
        }
    }
    if (compt > 2) {
        return (0);
    }
    return (1);
}
