/*
** EPITECH PROJECT, 2020
** key_func.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *key_func(matrice *mat, int ac ,char **av)
{
    if (av[3][0] == '0' && av[3][1] == '\0')
        printf("Key matrix:\n");
    for (int k = 0, i = 0; i < mat->size_mat; i++) {
        for (int j = 0; j < mat->size_mat && k < my_strlen(av[2]); j++, k++) {
            mat->key_mat[i][j] = av[2][k];
        }
    }
    for (int i = 0; i < mat->size_mat && av[3][0] == '0' && av[3][1] == '\0'; i++) {
        for (int j = 0; j < mat->size_mat; j++) {
            printf("%d", mat->key_mat[i][j]);
            if (j < mat->size_mat - 1)
                printf("\t");
        }
        printf("\n");
    }
    if (av[3][0] == '0' && av[3][1] == '\0')
        printf("\n");
    return (mat);
}