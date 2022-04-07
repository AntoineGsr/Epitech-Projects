/*
** EPITECH PROJECT, 2021
** exec_pipe
** File description:
** exec the pipe between the two commands in argument
*/

#include "include/my.h"

void dup_close_and_exec(char *command, int fd2, int *fd, storage_t *storage)
{
    if (fd2 == 1)
        dup2(fd[1], STDOUT_FILENO);
    else
        dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    close(fd[1]);
    execute_command(command, storage);
    exit(storage->status);
}

void exec_pipe(char *first_command, char *second_command, storage_t *storage)
{
    pid_t pid;
    int fd[2];
    int status;

    pipe(fd);
    pid = fork();
    if (pid == 0)
        dup_close_and_exec(first_command, 1, fd, storage);
    else
        pid = fork();
    if (pid == 0)
        dup_close_and_exec(second_command, 0, fd, storage);
    else {
        close(fd[0]);
        close(fd[1]);
        waitpid(pid, &status, 0);
    }
    wait(NULL);
    if (WIFEXITED(status))
        storage->status = WEXITSTATUS(status);
}