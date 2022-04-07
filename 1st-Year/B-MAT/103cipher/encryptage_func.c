/*
** EPITECH PROJECT, 2020
** encryptage_func.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *encryptage_func(matrice *mat, int ac, char **av)
{
    printf("Encrypted message:\n");
    for (int i = 0, k = 0; i < mat->size_av1 && k < mat->size_av1; i++) {
        for (int j = 0; j < mat->size_mat; j++, k++) {
            for (int z = 0; z < mat->size_mat; z++)
                mat->encry_mat[i][j] += mat->msg_mat[i][z] * mat->key_mat[z][j];
                printf("%d", mat->encry_mat[i][j]);
                if (k <= mat->size_av1)
                    printf(" ");
        }
    }
    printf("\n");
    return (mat);
}