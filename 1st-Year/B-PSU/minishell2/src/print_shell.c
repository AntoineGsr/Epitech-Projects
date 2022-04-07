/*
** EPITECH PROJECT, 2021
** print_shell.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int my_putstr_fast_zero(char const *str)
{
    if (isatty(0) == 1)
        write(1, str, my_strlen(str));
    return (0);
}

int my_putstr_fast_error(char const *str)
{
    write(2, str, my_strlen(str));
    return (0);
}

void print_prompt(void)
{
    char buff[300];
    int count = 0;
    int count2 = 0;
    int j = 0;

    getcwd(buff, 300);
    for (int i = 0; buff[i] != '\0'; i++) {
        if (buff[i] == '/')
            count += 1;
    }
    for (j; count2 < count; j++) {
        if (buff[j] == '/')
            count2 += 1;
    }
    my_putstr_fast_zero(BOLDBLUE "[minishell-agasser]" RESET);
    my_putstr_fast_zero("-" BOLDWHITE);
    my_putstr_fast_zero("[");
    my_putstr_fast_zero(buff + j);
    my_putstr_fast_zero("]$> " RESET);
}