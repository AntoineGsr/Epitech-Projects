/*
** EPITECH PROJECT, 2021
** main
** File description:
** mysh
*/

#include "include/my.h"

int main(int ac, char **av, char **env)
{
    storage_t storage = {NULL, 0, 0};

    if (error_handling(ac, av, env) == 84) {
        return (84);
    }
    storage.oldpwd = getcwd(NULL, 0);
    if ((storage.env = alloc_env(env, env)) == NULL)
        storage.env = alloc_env(env, env);
    init_all(&storage);
    my_sh(&storage);
    if (isatty(0))
        my_putstr("exit\n");
    free_all(&storage);
    return (storage.status);
}