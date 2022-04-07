/*
** EPITECH PROJECT, 2021
** fork_gestion.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

static void sort_input(global_list **father)
{
    for (int i = 0; (*father)->input[i] != '\0'; i++) {
        if ((*father)->input[i] == '|' || (*father)->input[i] == '<'
            || (*father)->input[i] == '>')
            (*father)->input[i] = ';';
    }
    (*father)->input_sort =
    my_str_to_word_array_separator((*father)->input, ';');
}

static void parse_input_sort(global_list **father)
{
    if ((*father)->input_sort != NULL && (*father)->input_sort[0][0] != '\0') {
        (*father)->sort = my_str_to_word_array((*father)->input_sort[
        (*father)->step]);
    } else {
        (*father)->sort = my_str_to_word_array((*father)->input);
    }
    for (int i = 0; (*father)->sort != NULL && (*father)->sort[i] != NULL; i++)
        (*father)->ac = i + 1;
}

int fork_gestion(global_list **father, list **my_env, l_list **node_env)
{
    size_t len = 0;
    int line_size = 0;

    signal(SIGINT, handler_sigint);
    if ((*father)->step == 0) {
        line_size = getline(&(*father)->input, &len, stdin);
        if (verif_ctrl_d(father, line_size) == 1) return (0);
    }
    sort_input(father);
    parse_input_sort(father);
    (*father)->child_pid = fork();
    switch ((*father)->child_pid) {
        case -1: return (1);
            break;
        case 0: child_gestion(father, my_env, node_env);
            break;
        default: father_gestion(father, my_env, node_env);
            break;
    }
    return (0);
}