/*
** EPITECH PROJECT, 2020
** error_boats.c
** File description:
** navy
*/

#include "navy.h"

int verif_size_number(char *copy_txt)
{
    int letter1 = convert_letter(copy_txt[2]);
    int letter2 = convert_letter(copy_txt[5]);
    int size = convert_nb(copy_txt[0]) + 1;
    int i = 1;

    if (letter1 > letter2) {
        for (i = 1; letter2 + i <= letter1; i++);
        if (size != i)
            return (-1);
    }
    if (letter1 < letter2) {
        for (i = 1; letter1 + i <= letter2; i++);
        if (size != i)
            return (-1);
    }
    return (0);
}

int verif_size_letter(char *copy_txt)
{
    int nb1 = convert_nb(copy_txt[3]);
    int nb2 = convert_nb(copy_txt[6]);
    int size = convert_nb(copy_txt[0]) + 1;
    int i = 1;

    if (nb1 > nb2) {
        for (i = 1; nb2 + i <= nb1; i++);
        if (size != i)
            return (-1);
    }
    if (nb1 < nb2) {
        for (i = 1; nb1 + i <= nb2; i++);
        if (size != i)
            return (-1);
    }
    return (0);
}

int error_size_boat(char *copy_txt)
{
    if (verif_size_letter(copy_txt) == -1) return (-1);
    if (verif_size_number(copy_txt) == -1) return (-1);
    if (verif_size_letter(copy_txt + 8) == -1) return (-1);
    if (verif_size_number(copy_txt + 8) == -1) return (-1);
    if (verif_size_letter(copy_txt + 16) == -1) return (-1);
    if (verif_size_number(copy_txt + 16) == -1) return (-1);
    if (verif_size_letter(copy_txt + 24) == -1) return (-1);
    if (verif_size_number(copy_txt + 24) == -1) return (-1);
    return (0);
}

int verif_eq_dif_boat(char *copy_txt)
{
    int letter1 = convert_letter(copy_txt[2]);
    int letter2 = convert_letter(copy_txt[5]);
    int nb1 = convert_nb(copy_txt[3]);
    int nb2 = convert_nb(copy_txt[6]);
    int count = 0;
    int count2 = 0;

    if (nb1 > nb2) count += 1;
    if (nb1 < nb2) count += 1;
    if (letter1 > letter2) count += 1;
    if (letter1 < letter2) count += 1;
    if (letter1 == letter2) count2 += 1;
    if (nb1 == nb2) count2 += 1;
    if (count != 1 || count2 != 1)
        return (-1);
    return (0);
}

int error_eq_dif_boat(char *copy_txt)
{
    if (verif_eq_dif_boat(copy_txt) == -1)
        return (-1);
    if (verif_eq_dif_boat(copy_txt + 8) == -1)
        return (-1);
    if (verif_eq_dif_boat(copy_txt + 16) == -1)
        return (-1);
    if (verif_eq_dif_boat(copy_txt + 24) == -1)
        return (-1);
    if (verif_nb_size(copy_txt) == -1)
        return (-1);
    return (0);
}