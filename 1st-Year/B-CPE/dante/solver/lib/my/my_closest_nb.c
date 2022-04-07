/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_closest_nb
*/

#include "my.h"

int my_closest_nb(int n, int m)
{
    int q = n / m;
    int n1 = m * q;
    int n2 = (n * m > 0) ? m * (q + 1) : m * (q - 1);

    if (MY_ABS(n - n1) < MY_ABS(n - n2))
        return (n1);
    return (n2);
}
