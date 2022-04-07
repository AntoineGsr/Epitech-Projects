/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** minishell
*/

#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    global_list *father = create_father(av, env);
    list *my_env = create_env(av, env);
    l_list *node_env = malloc(sizeof(l_list));
    int return_value = 0;
    int exit = 0;

    if (ac != 1) return (84);
    if (node_env == NULL) return (0);
    create_shell(&father, &my_env, &node_env, env);
    while (father->exit_null == 0) {
        update_env(&my_env, &node_env);
        if (father->step == 0)
            print_prompt();
        return_value = fork_gestion(&father, &my_env, &node_env);
        if (return_value == 1) return (84);
    }
    exit = father->exit;
    destroy_list(&my_env, &node_env);
    free(father);
    return (exit);
}