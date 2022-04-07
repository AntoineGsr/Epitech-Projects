/*
** EPITECH PROJECT, 2020
** empty_matrix.c
** File description:
** 103cipher
*/

#include "103cipher.h"

double **empty_matrix_double(int row, int col)
{
    double **matrix = malloc(sizeof(double *) * row);
    for(int i = 0; i < row; i++) {
        matrix[i] = malloc(sizeof(double) * col);
    }
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            matrix[i][j] = 0.000000;
    }
    return (matrix);
}

int **empty_matrix(int row, int col)
{
    int **matrix = malloc(sizeof(int *) * row);
    for(int i = 0; i < row; i++) {
        matrix[i] = malloc(sizeof(int) * col);
    }
    for(int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            matrix[i][j] = 0;
    }
    return (matrix);
}