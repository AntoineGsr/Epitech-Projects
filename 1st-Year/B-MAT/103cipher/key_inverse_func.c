/*
** EPITECH PROJECT, 2020
** key_inverse_func.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *key_inverse_func(matrice *mat, int ac ,char **av)
{
    printf("Key matrix:\n");
    for (int i = 0; i < mat->size_mat; i++) {
        for (int j = 0; j < mat->size_mat; j++) {
            mat->key_inverse_mat[i][j] = (1.000000 / (double) mat->determinant) * (double) mat->comat_mat[i][j];
            if (mat->key_inverse_mat[i][j] == -0.000000)
                mat->key_inverse_mat[i][j] *= (-1.000000);
            printf("%.3f", mat->key_inverse_mat[i][j]);
            if (j < mat->size_mat - 1)
                printf("\t");
        }
        printf("\n");
    }
    printf("\n");
    return (mat);
}