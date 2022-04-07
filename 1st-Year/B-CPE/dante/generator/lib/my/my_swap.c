/*
** EPITECH PROJECT, 2020
** my_swap.c
** File description:
** lib
*/

void my_swap(int *a, int *b)
{
    int stock = *a;

    *a = *b;
    *b = stock;
}
