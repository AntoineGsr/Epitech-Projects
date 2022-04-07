/*
** EPITECH PROJECT, 2020
** key_comatrice_func.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *key_comatrice_func(matrice *mat, int ac ,char **av)
{
    if (mat->size_mat == 2) {
        mat->comat_mat[0][0] = mat->key_mat[1][1];
        mat->comat_mat[0][1] = -mat->key_mat[1][0];
        mat->comat_mat[1][0] = -mat->key_mat[0][1];
        mat->comat_mat[1][1] = mat->key_mat[0][0];
    }
    if (mat->size_mat == 3) {
        mat->comat_mat[0][0] = mat->key_mat_transpo[1][1] * mat->key_mat_transpo[2][2] - mat->key_mat_transpo[1][2] * mat->key_mat_transpo[2][1];
        mat->comat_mat[0][1] = (-1) * (mat->key_mat_transpo[1][0] * mat->key_mat_transpo[2][2] - mat->key_mat_transpo[2][0] * mat->key_mat_transpo[1][2]);
        mat->comat_mat[0][2] = mat->key_mat_transpo[1][0] * mat->key_mat_transpo[2][1] - mat->key_mat_transpo[2][0] * mat->key_mat_transpo[1][1];
        mat->comat_mat[1][0] = (-1) * (mat->key_mat_transpo[0][1] * mat->key_mat_transpo[2][2] - mat->key_mat_transpo[2][1] * mat->key_mat_transpo[0][2]);
        mat->comat_mat[1][1] = mat->key_mat_transpo[0][0] * mat->key_mat_transpo[2][2] - mat->key_mat_transpo[2][0] * mat->key_mat_transpo[0][2];
        mat->comat_mat[1][2] = (-1) * (mat->key_mat_transpo[0][0] * mat->key_mat_transpo[2][1] - mat->key_mat_transpo[2][0] * mat->key_mat_transpo[0][1]);
        mat->comat_mat[2][0] = mat->key_mat_transpo[0][1] * mat->key_mat_transpo[1][2] - mat->key_mat_transpo[1][1] * mat->key_mat_transpo[0][2];
        mat->comat_mat[2][1] = (-1) * (mat->key_mat_transpo[0][0] * mat->key_mat_transpo[1][2] - mat->key_mat_transpo[1][0] * mat->key_mat_transpo[0][2]);
        mat->comat_mat[2][2] = mat->key_mat_transpo[0][0] * mat->key_mat_transpo[1][1] - mat->key_mat_transpo[1][0] * mat->key_mat_transpo[0][1];
    }
    return (mat);
}