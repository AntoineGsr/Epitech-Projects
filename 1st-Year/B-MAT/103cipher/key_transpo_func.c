/*
** EPITECH PROJECT, 2020
** key_transpo_func.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *key_transpo_func(matrice *mat, int ac ,char **av)
{
    for (int i = 0; i < mat->size_mat; i++) {
        for (int j = 0; j < mat->size_mat; j++) {
            mat->key_mat_transpo[i][j] = mat->key_mat[j][i];
        }
    }
    return (mat);
}