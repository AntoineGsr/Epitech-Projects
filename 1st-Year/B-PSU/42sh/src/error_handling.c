/*
** EPITECH PROJECT, 2021
** error_handling
** File description:
** mysh
*/

#include "include/my.h"

int error_handling(int ac, char **av, char **env)
{
    if (ac != 1) {
        my_puterr("Invalid number of arguments. Use ./mysh\n");
        return (84);
    }
    if (env == NULL) {
        my_puterr("Invalid environement\n");
        return (84);
    }
    return (0);
}