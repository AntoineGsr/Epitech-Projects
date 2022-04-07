/*
** EPITECH PROJECT, 2020
** type_form.c
** File description:
** 104intersection
*/

#include "104intersection.h"

int type_form(int ac, char **av)
{
    if (av[1][0] == '1')
        printf("Sphere of radius %d\n", my_getnbr(av[8]));
    if (av[1][0] == '2')
        printf("Cylinder of radius %d\n", my_getnbr(av[8]));
    if (av[1][0] == '3')
        printf("Cone with a %d degree angle\n", my_getnbr(av[8]));
    return (0);
}