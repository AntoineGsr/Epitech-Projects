/*
** EPITECH PROJECT, 2020
** my_compute_square_root
** File description:
** square
*/

int my_compute_square_root(int nb)
{
    for (int i = 0 ; i <= nb ; i++)
        if (i * i == nb)
            return (i);
    return (0);
}
