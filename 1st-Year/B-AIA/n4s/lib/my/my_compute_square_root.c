/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** lib
*/

int my_compute_square_root(int nb)
{
    int square = 0;

    while (square <= nb) {
        if ((square * square) == nb) {
            return (square);
        }
        square += 1;
    }
    return (0);
}
