/*
** EPITECH PROJECT, 2021
** make_ls
** File description:
** mysh
*/

#include "include/my.h"

void crash_msg(int status, storage_t *storage)
{
    switch (WTERMSIG(status)) {
        case SIGSEGV: my_puterr("Segmentation fault");
        storage->status = 139;
        break;
        case SIGFPE: my_puterr("Floating exception");
        storage->status = 136;
        break;
        default: break;
    }
}

void make_command(char *command, char **inputs, storage_t *storage)
{
    char *path_command = add_path(command, storage->env);
    int id = 0;
    int status = 0;
    if (!path_command) {
        my_puterr("Segmentation fault\n");
        return;
    } id = fork();
    if (id == 0)
        storage->execve_return = execve(path_command, inputs, storage->env);
    if (check_error_arch(inputs, storage) == 1) return;
    free(path_command);
    waitpid(0, &status, 0);
    if (WIFSIGNALED(status)) {
        crash_msg(status, storage);
        if (WCOREDUMP(status))
            my_puterr(" (core dumped)");
        my_puterr("\n");
    } storage->status = WEXITSTATUS(status);
}