/*
** EPITECH PROJECT, 2021
** destroy_gestion.c
** File description:
** generator
*/

#include "../../include/my.h"

void destroy_struct(generator *gen)
{
    free(gen->cell);
    free(gen->maze);
    free(gen);
}