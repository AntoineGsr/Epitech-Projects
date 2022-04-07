/*
** EPITECH PROJECT, 2020
** 103cipher.h
** File description:
** 103cipher
*/

#ifndef CIPHER_H_
#define CIPHER_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "./lib/my/my.h"

typedef struct matrice matrice;
struct matrice
{
    int **key_mat;
    int **key_mat_transpo;
    int **msg_mat;
    int **encry_mat;
    int **decry_mat;
    int **comat_mat;
    double **key_inverse_mat;
    int size_mat;
    int size_av1;
    int determinant;
};

int helper_func(int ac, char **av);

matrice *create_struct(int ac, char **av);

int matrix_size(int ac, char **av);

int **empty_matrix(int row, int col);

double **empty_matrix_double(int row, int col);

matrice *key_func(matrice *mat, int ac, char **av);

matrice *message_func(matrice *mat, int ac, char **av);

matrice *encryptage_func(matrice *mat, int ac, char **av);

matrice *key_transpo_func(matrice *mat, int ac ,char **av);

matrice *key_comatrice_func(matrice *mat, int ac ,char **av);

matrice *key_determinant_func(matrice *mat, int ac, char **av);

matrice *key_inverse_func(matrice *mat, int ac, char **av);

matrice *message_encrypted_func(matrice *mat, int ac, char **av);

matrice *decryptage_func(matrice *mat, int ac, char **av);

#endif /* CIPHER_H_ */
