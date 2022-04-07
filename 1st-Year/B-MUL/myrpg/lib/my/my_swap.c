/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** swap int
*/

void my_swap(int *a, int *b)
{
    int temporaire = *a;

    *a = *b;
    *b = temporaire;
}
