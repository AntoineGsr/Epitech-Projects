/*
** EPITECH PROJECT, 2020
** message_encrypted_func.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *message_encrypted_func(matrice *mat, int ac, char **av)
{
    int size = my_strlen(av[1]);

    for (int i = 0, k = 0; i < mat->size_av1 && k < mat->size_av1; i++) {
        for (int j = 0; j < mat->size_mat && k < size; j++, k++) {
            mat->decry_mat[i][j] = my_getnbr(av[1]);
            av[1] = av[1] + my_strlen(my_getstr(my_getnbr(av[1])));
        }
    }
    return (mat);
}
