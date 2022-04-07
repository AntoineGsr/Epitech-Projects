/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** file 1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "./lib/my/my.h"

float *velocity(char *x1, char *y1, char *z1, char *x2, char *y2,
char *z2, char *n);

int error_management(int ac, char **av);

void help_management(void)
{
    int fd;
    char buffer[317];

    fd = open("help.txt", O_RDONLY);
    read(fd, buffer, 316);
    printf("%s\n", buffer);
    exit(0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help_management();
    if (error_management(ac, av) == 0) {
        return (84);}
    velocity(av[1], av[2], av[3], av[4], av[5], av[6], av[7]);
    return (0);
}
