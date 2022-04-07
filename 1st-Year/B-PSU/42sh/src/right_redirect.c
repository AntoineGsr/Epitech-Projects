/*
** EPITECH PROJECT, 2021
** right_redirect
** File description:
** handle right redirections
*/

#include "include/my.h"

void simple_right_redirect(char *command, storage_t *storage)
{
    char *file_name = define_file_name(command, '>');
    int fd = 0;
    int pid = 0;

    command = redefine_command(command, file_name, '>');
    pid = fork();
    if (pid == 0) {
        fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, STDOUT_FILENO);
        close(fd);
        execute_command(command, storage);
        exit(1);
    }
    free(command);
    free(file_name);
    wait(NULL);
}

void double_right_redirect(char *command, storage_t *storage)
{
    char *file_name = define_file_name(command, '>');
    int fd = 0;
    int pid = 0;
    char *str;

    command = redefine_command(command, file_name, '>');
    pid = fork();
    if (pid == 0) {
        str = file_reader(file_name);
        fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        dup2(fd, STDOUT_FILENO);
        close(fd);
        my_putstr(str);
        free(str);
        execute_command(command, storage);
        exit(1);
    }
    free(file_name);
    free(command);
    wait(NULL);
}