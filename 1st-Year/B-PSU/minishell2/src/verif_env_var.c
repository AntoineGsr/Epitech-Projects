/*
** EPITECH PROJECT, 2021
** verif_env_var.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

void change_pwd_env(list **gbl, l_list **l_a, char *str)
{
    char buff[300];

    for (; (*l_a)->next != NULL; (*l_a) = (*l_a)->next) {
        if (my_strncmp(str, "PWD", my_strlen(str)) == 0
            && my_strncmp(str, (*l_a)->value_env, my_strlen(str)) == 0) {
            getcwd(buff, 300);
            (*l_a)->value_env = my_memset_char(my_strlen(buff) + 5);
            (*l_a)->value_env = my_strcat((*l_a)->value_env, "PWD=");
            (*l_a)->value_env = my_strcat((*l_a)->value_env, buff);
            break;
        }
    }
}

l_list *verif_env_exist(list **gbl, l_list **l_a, char *str)
{
    for (; (*l_a)->next != NULL; (*l_a) = (*l_a)->next) {
        if (my_strncmp(str, (*l_a)->value_env, my_strlen(str)) == 0) {
            return NULL;
        }
    }
    if (my_strncmp(str, (*l_a)->value_env, my_strlen(str)) == 0) {
        return NULL;
    }
    return (*l_a);
}
