/*
** EPITECH PROJECT, 2020
** line_para.c
** File description:
** 104intersection
*/

#include "104intersection.h"

int line_para(int ac, char **av)
{
    printf("Line passing through the point (%d, %d, %d) ", my_getnbr(av[2]), my_getnbr(av[3]), my_getnbr(av[4]));
    printf("and parallel to the vector (%d, %d, %d)\n", my_getnbr(av[5]), my_getnbr(av[6]), my_getnbr(av[7]));
}