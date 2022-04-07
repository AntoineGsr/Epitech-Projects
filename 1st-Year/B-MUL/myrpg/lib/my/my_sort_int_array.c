/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** sort int array
*/

#include "my.h"

void    my_sort_int_array(int *array, int size)
{
    int temp;
    int index = 0;

    while ((index + 1) < size) {
        if (array[index + 1] < array[index]) {
            temp = array[index];
            array[index] = array[index + 1];
            array[index + 1] = temp;
            index = 0;
        }
        else
            index = index + 1;
    }
}