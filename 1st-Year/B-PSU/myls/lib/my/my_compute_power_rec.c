/*
** EPITECH PROJECT, 2020
** my_compute_power_rec.c
** File description:
** lib
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0) {
        return (0);
    }
    if (p == 0) {
        return (1);
    }
    return (nb * my_compute_power_rec(nb, p - 1));
}
