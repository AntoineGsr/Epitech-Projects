/*
** EPITECH PROJECT, 2020
** error_gestion.c
** File description:
** navy
*/

#include "navy.h"

int error_input(char *str)
{
    int size = my_strlen(str);

    if (size != 3)
        return (-1);
    if (!(str[0] >= 'A' && str[0] <= 'H'))
        return (-1);
    if (!(str[1] >= '1' && str[1] <= '8'))
        return (-1);
    return (0);
}

int read_txt(char *av)
{
    int opn = 0;
    int rd_fl = 0;
    char copy_txt[31];

    opn = open(av, O_RDONLY);
    if (opn == -1)
        return (-1);
    rd_fl = read(opn, copy_txt, 31);
    copy_txt[31] = '\0';
    if (verif_start_line(copy_txt) == -1)
        return (-1);
    if (verif_dot(copy_txt) == -1)
        return (-1);
    if (verif_letter(copy_txt) == -1)
        return (-1);
    if (verif_nb(copy_txt) == -1)
        return (-1);
    if (error_size_boat(copy_txt) == -1 || error_eq_dif_boat(copy_txt) == -1)
        return (-1);
    return (0);
}

int error_gestion(int ac, char **av)
{
    if (ac == 2) {
        if (read_txt(av[1]) == -1)
            return (-1);
        return (0);
    } else if (ac == 3) {
        if (read_txt(av[2]) == -1)
            return (-1);
        return (0);
    } else
        return (-1);
}
