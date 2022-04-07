/*
** EPITECH PROJECT, 2021
** make_ls
** File description:
** mysh
*/

#include "include/my.h"

int check_error_arch(char **inputs, storage_t *storage)
{
    if (errno == ENOEXEC) {
        fprintf(stderr, "%s: %s.%s\n", inputs[0], strerror(errno),
        " Wrong Architecture.");
        storage->status = 1;
        return (1);
    } return (0);
}