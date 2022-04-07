/*
** EPITECH PROJECT, 2021
** check parenthese
** File description:
** check if the parentheses are well used
*/

#include "include/my.h"

void execute_subshell(char *command, storage_t *storage)
{
    char *subshell_command = define_subshell_command(command);
    char *cur_dir = getcwd(NULL, 0);

    storage->status = subshell_main(storage->env, subshell_command);
    chdir(cur_dir);
    free(cur_dir);
    free(command);
}