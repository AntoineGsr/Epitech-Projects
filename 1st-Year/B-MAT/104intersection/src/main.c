/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** 104intersection
*/

#include "104intersection.h"

int main(int ac, char **av)
{
    helper(ac, av);
    error_gestion(ac, av);
    type_form(ac, av);
    line_para(ac ,av);
    intersection_point(ac, av);
    return (0);
}