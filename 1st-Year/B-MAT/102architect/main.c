/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** file 1
*/

#include "102architect.h"

void help_management(void)
{
    int fd;
    char buffer[444];

    fd = open("help.txt", O_RDONLY);
    read(fd, buffer, 443);
    printf("%s\n", buffer);
    exit(0);
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help_management();
    error_gestion(ac, av);
    double base[3] = {0, 0, 0};
    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            for (int j = 0; j < 4; j++) {
                if (av[i][1] == AFLAG_FUNCS[j].a_flag)
                    AFLAG_FUNCS[j].type_aflag(av, i, ac, base);
            }
        }
    }
    return (0);
}
