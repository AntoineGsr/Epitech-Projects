/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** solver
*/

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../include/my.h"
#include "solver.h"

static char *fs_open_file(char const *filepath)
{
    struct stat info;
    int fd;
    char *buffer;

    if (stat(filepath, &info) == -1 || !(info.st_size))
        return (NULL);
    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * info.st_size + 1);
    if (!buffer)
        return (NULL);
    if (read(fd, buffer, info.st_size) != info.st_size) {
        free(buffer);
        return (NULL);
    }
    buffer[info.st_size] = '\0';
    close(fd);
    return (buffer);
}

int main(int ac, char * const *av)
{
    char *buffer = NULL;
    char **map = NULL;

    if (ac != 2)
        return (84);
    buffer = fs_open_file(av[1]);
    if (buffer == NULL)
        return (84);
    map = my_str_to_wordtab(buffer, "\n");
    free(buffer);
    if (map[0][0] != '*') {
        free_double_array((void ***)&map);
        return (84);
    }
    find_path(map);
    free_double_array((void ***)&map);
    return (0);
}
