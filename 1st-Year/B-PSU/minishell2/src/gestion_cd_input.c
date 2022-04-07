/*
** EPITECH PROJECT, 2021
** gestion_cd_input.c
** File description:
** minishell1
*/

#include "../include/minishell.h"

int compare_cd_fth_pth(global_list **father, list **my_env, l_list **node_env)
{
    int dir = 0;
    char *path = NULL;
    int i = 0;

    path = my_memset_char(300);
    if ((*father)->sort[1][0] == '~') {
        path = my_strcat(path, (*my_env)->home);
        i = 1;
    }
    path = my_strcat(path, (*father)->sort[1] + i);
    dir = chdir(path);
    free(path);
    return (dir);
}

int compare_unsetenv_oldpwd(global_list **father, list **my_env,
l_list **node_env, char *str)
{
    while (*node_env != NULL && (*my_env)->total_env > 1) {
        if (my_strncmp(str, (*node_env)->value_env,
            my_strlen(str)) == 0) {
            unsetenv_del_node(father, my_env, node_env);
            (*my_env)->total_env -= 1;
            return (1);
        }
        *node_env = (*node_env)->next;
    }
    if ((*father)->old_cd > 0)
        unsetenv_fth_last_var(father, my_env, node_env);
    return (0);
}

int compare_cd_arg(global_list **father, list **my_env, l_list **node_env)
{
    int dir = 0;

    if ((*father)->sort[1] == NULL
        || my_strcmp((*father)->sort[1], "~") == 0) {
        if ((*my_env)->pwd_create == 1) {
            dir = chdir((*my_env)->home);
        } else {
            dir = chdir((*my_env)->home + 5);
        }
    } else if ((*father)->sort[1] != NULL && my_strcmp((*father)->sort[1],
        "-") == 0) {
        (*father)->sort[1][0] = '\0';
        dir = chdir((*father)->oldpwd);
    } else {
        dir = compare_cd_fth_pth(father, my_env, node_env);
    }
    return (dir);
}

int verif_cd_access(global_list **father, char *path)
{
    int error = 0;
    struct stat statbuf;

    error = stat(path, &statbuf);
    if (error != 0) return (1);
    if (S_ISREG(statbuf.st_mode)) {
        my_putstr_fast_error(path);
        my_putstr_fast_error(": Not a directory.\n");
        return (1);
    }
    my_putstr_fast_error((*father)->sort[1]);
    if (access(path, F_OK) == 0) {
        if (access(path, X_OK) != 0) {
            my_putstr_fast_error(": Permission denied.\n");
            return (1);
        }
        error = execve(path, (*father)->sort, (*father)->env);
        return (1);
    }
    return (0);
}

void compare_cd_oldpwd(global_list **father, list **my_env, l_list **node_env,
int dir)
{
    char *oldpwd = my_memset_char(300);
    int access = 0;

    oldpwd = my_strcpy(oldpwd, "OLDPWD=");
    if (dir == -1) {
        (*father)->exit_child = 1;
        access = verif_cd_access(father, (*father)->sort[1]);
        if (access == 0)
            my_putstr_fast_error(": No such file or directory.\n");
    } else {
        compare_unsetenv_oldpwd(father, my_env, node_env, "OLDPWD=");
        *node_env = (*my_env)->first;
        *node_env = add_last(my_env, node_env, my_strcat(oldpwd,
        (*father)->memory_pwd));
        (*father)->oldpwd = my_memset_char(
        my_strlen((*node_env)->value_env) + 3);
        (*father)->oldpwd = my_strcpy((*father)->oldpwd,
        (*node_env)->value_env + 7);
        *node_env = (*my_env)->first;
    }
}