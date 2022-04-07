/*
** EPITECH PROJECT, 2021
** make_exe
** File description:
** minishell1
*/

#include "include/my.h"

void make_exe(char *file, char **inputs, storage_t *storage)
{
    int id = fork();
    int status = 0;
    if (id == 0)
        execve(file, inputs, storage->env);
    if (check_error_arch(inputs, storage) == 1) exit (1);
    waitpid(0, &status, 0);
    if (WIFSIGNALED(status)) {
        switch (WTERMSIG(status)) {
            case SIGSEGV: my_puterr("Segmentation fault");
            storage->status = 139;
            break;
            case SIGFPE: my_puterr("Floating exception");
            storage->status = 136;
            break;
            default: break;
        }
        if (WCOREDUMP(status))
            my_puterr(" (core dumped)");
        my_puterr("\n");
    } else storage->status = WEXITSTATUS(status);
}