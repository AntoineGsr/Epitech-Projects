/*
** EPITECH PROJECT, 2020
** create_struct.c
** File description:
** 103cipher
*/

#include "103cipher.h"

matrice *create_struct(int ac, char **av)
{
    matrice *mat = malloc(sizeof(*mat));
    mat->size_mat = matrix_size(ac, av);
    mat->size_av1 = my_strlen(av[1]);
    mat->key_mat = empty_matrix(mat->size_mat, mat->size_mat);
    mat->key_mat_transpo = empty_matrix(mat->size_mat, mat->size_mat);
    mat->comat_mat = empty_matrix(mat->size_mat, mat->size_mat);
    mat->msg_mat = empty_matrix(mat->size_av1, mat->size_mat);
    mat->encry_mat = empty_matrix(mat->size_av1, mat->size_mat);
    mat->key_inverse_mat = empty_matrix_double(mat->size_mat, mat->size_mat);
    mat->decry_mat = empty_matrix(mat->size_av1, mat->size_mat);
    mat->determinant = 0;
    return (mat);
}