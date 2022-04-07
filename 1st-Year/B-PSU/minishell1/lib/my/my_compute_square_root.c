/*
** EPITECH PROJECT, 2020
** my_compute_square_root.c
** File description:
** lib
*/

int my_compute_square_root(int nb)
{
    int carre = 0;

    while (carre <= nb) {
        if ((carre * carre) == nb) {
            return (carre);
        }
        carre = carre + 1;
    }
    return (0);
}
