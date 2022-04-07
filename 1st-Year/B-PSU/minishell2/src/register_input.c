/*
** EPITECH PROJECT, 2021
** register_input.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

void save_pwd(global_list **father)
{
    char buff[300];

    (*father)->old_cd += 1;
    getcwd(buff, 300);
    if (my_strcmp((*father)->sort[0], "cd") == 0) {
        (*father)->memory_pwd = my_memset_char(my_strlen(buff) + 1);
        (*father)->memory_pwd = my_strcat((*father)->memory_pwd, buff);
    }
}

void register_input(global_list **father, char *str)
{
    (*father)->input_modif = my_memset_char(my_strlen(str) + 1);
    (*father)->input_modif = my_strcat((*father)->input_modif, str);
}