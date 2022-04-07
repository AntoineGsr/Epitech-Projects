/*
** EPITECH PROJECT, 2020
** name_file.c
** File description:
** my_ls
*/

#include "my_ls.h"

int type_file_verif(struct stat data)
{
    switch (data.st_mode & S_IFMT) {
    case S_IFBLK: return (0);
        break;
    case S_IFCHR: return (0);
        break;
    case S_IFDIR: return (0);
        break;
    case S_IFIFO: return (0);
        break;
    case S_IFLNK: return (0);
        break;
    case S_IFREG: return (0);
        break;
    case S_IFSOCK: return (0);
        break;
    default: return (1);
        break;
    }
}

int error_filepath(char *av, struct stat data)
{
    DIR *dir = opendir(av);

    if (type_file_verif(data) == 0)
        return (0);
    if (dir == NULL) {
        my_putstr_fast("ls: cannot access '");
        my_putstr_fast(av);
        my_putstr_fast("': No such file or directory\n");
        exit(84);
    }
    return (0);
}

void empty_to_full(char *av, S_array *S_arr, struct stat d_verif, int *count)
{
    if (S_ISDIR(d_verif.st_mode)) {
        S_arr->name = my_strcat(av, "/\0");
        *count = *count + 1;
    } else {
        S_arr->name = my_strcpy(S_arr->name, av);
        my_strcpy(av, "/\0");
        S_arr->not_d = 1;
        *count = *count + 1;
    }
}

char *name_file(int ac, char **av, S_array *S_arr)
{
    int count = 0;
    int sck_name = 0;
    struct stat d_verif;

    for (int i = 1; i < ac; i++) {
        if (av[i][0] != '-' && sck_name == 0) {
            S_arr->sck_name = my_strcpy(S_arr->sck_name, av[i]);
            sck_name++;
        }
        if (av[i][0] != '-' && count == 0) {
            stat(av[i], &d_verif);
            error_filepath(av[i], d_verif);
            empty_to_full(av[i], S_arr, d_verif, &count);
        }
    }
    if (count == 0) {
        S_arr->sck_name = my_strcpy(S_arr->sck_name, "./\0");
        S_arr->name = "./\0";
    }
    return NULL;
}
