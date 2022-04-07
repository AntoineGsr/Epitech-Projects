/*
** EPITECH PROJECT, 2020
** key_determinant.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *key_determinant_func(matrice *mat, int ac, char **av)
{
    if (mat->size_mat == 2) {
        mat->determinant = mat->key_mat[0][0] * mat->key_mat[1][0] - mat->key_mat[0][1] * mat->key_mat[1][1];
    }
    if (mat->size_mat == 3) {
        mat->determinant = (mat->key_mat[0][0] * mat->key_mat[1][1] * mat->key_mat[2][2])
        + (mat->key_mat[0][1] * mat->key_mat[1][2] * mat->key_mat[2][0])
        + (mat->key_mat[0][2] * mat->key_mat[1][0] * mat->key_mat[2][1])
        - (mat->key_mat[0][2] * mat->key_mat[1][1] * mat->key_mat[2][0])
        - (mat->key_mat[0][1] * mat->key_mat[1][0] * mat->key_mat[2][2])
        - (mat->key_mat[0][0] * mat->key_mat[1][2] * mat->key_mat[2][1]);
    }
    return (mat);
}