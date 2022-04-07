/*
** EPITECH PROJECT, 2020
** decryptage_func.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *decryptage_func(matrice *mat, int ac, char **av)
{
    printf("Decrypted message:\n");
    for (int i = 0, k = 0; i < mat->size_av1 && k < mat->size_av1; i++) {
        for (int j = 0; j < mat->size_mat; j++, k++) {
            for (int z = 0; z < mat->size_mat; z++) {
                mat->decry_mat[i][j] += mat->msg_mat[i][z] * mat->key_inverse_mat[z][j];
                printf("%c", mat->encry_mat[i][j]);
            }
        }
        printf(" ");
    }
    printf("\n");
    return (mat);
}