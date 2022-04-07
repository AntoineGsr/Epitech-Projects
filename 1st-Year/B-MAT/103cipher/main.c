/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** 103cipher
*/

#include "103cipher.h"


int error_gestion(int ac, char **av)
{
    if (ac != 4)
        return (-1);
    if (av[3][0] != '1' && av[3][0] != '0')
        return (-1);
    if (av[3][1] != '\0')
        return (-1);
    return (0);
}

int main(int ac, char **av)
{
    matrice *mat = NULL;

    if (helper_func(ac, av) == 0)
        return (0);
    if (error_gestion(ac, av) == -1)
        return (84);
    mat = create_struct(ac, av);
    mat = key_func(mat, ac, av);
    if (av[3][0] == '0' && av[3][1] == '\0') {
        mat = message_func(mat, ac, av);
        mat = encryptage_func(mat, ac, av);
    } else if (av[3][0] == '1' && av[3][1] == '\0') {
        mat = message_encrypted_func(mat, ac, av);
        mat = key_transpo_func(mat, ac, av);
        mat = key_comatrice_func(mat, ac, av);
        mat = key_determinant_func(mat, ac, av);
        mat = key_inverse_func(mat, ac, av);
        mat = decryptage_func(mat, ac, av);
    } else
        return (84);
    return (0);
}
