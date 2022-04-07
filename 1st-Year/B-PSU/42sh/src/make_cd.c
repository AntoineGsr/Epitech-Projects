/*
** EPITECH PROJECT, 2021
** make_cd
** File description:
** mysh
*/

#include "include/my.h"

void redefine_old_pwd(storage_t *storage, char *new_old_pwd)
{
    free(storage->oldpwd);
    storage->oldpwd = my_strdup(new_old_pwd);
    free(new_old_pwd);
}

void make_cd_two(char **inputs, storage_t *storage)
{
    char *cur_old_pwd = my_strdup(storage->oldpwd);

    redefine_old_pwd(storage, getcwd(NULL, 0));
    if (is_same_str(inputs[1], "-")) {
        chdir(cur_old_pwd);
        free(cur_old_pwd);
        return;
    }
    if (chdir(inputs[1]) == -1) {
        storage->status = 1;
        redefine_old_pwd(storage, cur_old_pwd);
        my_puterr(inputs[1]);
        my_puterr(": ");
        my_puterr(strerror(errno));
        my_puterr(".\n");
        return;
    }
    free(cur_old_pwd);
}

void redirect_to_home(storage_t *storage)
{
    if (chdir("/home/") == -1) {
        storage->status = 1;
        my_puterr("cd: No Home directory.\n");
    }
    storage->status = 0;
}

void make_cd(char **inputs, storage_t *storage)
{
    int str_nbr = set_str_nbr(inputs) - 1;

    storage->status = 1;
    if (str_nbr > 1)
        return (my_puterr("cd: Too many arguments.\n"));
    else if (str_nbr == 0)
        return (redirect_to_home(storage));
    storage->status = 0;
    make_cd_two(inputs, storage);
    add_local_var(getcwd(NULL, 0), "cwd", storage);
}