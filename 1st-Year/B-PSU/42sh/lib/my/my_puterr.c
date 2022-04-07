/*
** EPITECH PROJECT, 2021
** my_puterr
** File description:
** minishell
*/

#include "../../include/my.h"

void my_puterr(char *str)
{
    int len = my_strlen(str);

    write(2, str, len);
}
