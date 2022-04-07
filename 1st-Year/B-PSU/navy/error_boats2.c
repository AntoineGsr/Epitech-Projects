/*
** EPITECH PROJECT, 2020
** verif_nb_size.c
** File description:
** navy
*/

#include "navy.h"

int verif_nb_size(char *copy_txt)
{
    int arr[4];

    arr[0] = my_getnbr(copy_txt);
    arr[1] = my_getnbr(copy_txt + 8);
    arr[2] = my_getnbr(copy_txt + 16);
    arr[3] = my_getnbr(copy_txt + 24);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (arr[i] == arr[j] && i != j)
                return (-1);
        }
    }
    return (0);
}
