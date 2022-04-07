/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** power en recursif
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 2)
        return (nb * nb);
    if (p == 1)
        return (nb);
    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    return (nb * my_compute_power_rec(nb, p - 1));
}
