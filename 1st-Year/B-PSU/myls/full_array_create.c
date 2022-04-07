/*
** EPITECH PROJECT, 2020
** full_array_creation.c
** File description:
** my_ls
*/

#include "my_ls.h"

void coding_style(S_array *S_arr, char *nm)
{
    S_arr->full_ls[S_arr->i] = my_strcat(S_arr->full_ls[S_arr->i], nm);
    S_arr->rows += 1;
    S_arr->i = S_arr->i + 1;
}

void array_flags(S_array *S_arr, struct dirent *file, struct stat data,
DIR *dir)
{
    char *nm = NULL;

    while ((file = readdir(dir)) != NULL && S_arr->not_d != 1) {
        nm = malloc(sizeof(char) * 256);
        nm = my_strcpy(nm, S_arr->name);
        nm = my_strcat(nm, file->d_name);
        if (stat(nm, &data) == -1)
            exit (84);
        if (file->d_name[0] != '.' && S_arr->mask[1] == '0'
            && S_arr->mask[5] == '0') {
            coding_style(S_arr, nm);
        }
        if (S_arr->mask[1] == '1' && S_arr->mask[5] == '0') {
            S_arr->full_ls[S_arr->i] = my_strcat(S_arr->full_ls[S_arr->i], nm);
            S_arr->rows += 1;
            S_arr->i = S_arr->i + 1;
        }
        free(nm);
    }
}

int d_flag_array(S_array *S_arr)
{
    int j = 0;

    if (S_arr->mask[5] == '1' && S_arr->not_d == 1) {
        S_arr->full_ls[S_arr->i] = my_strcpy(S_arr->full_ls[0], S_arr->name);
        return (1);
    } else if (S_arr->mask[5] == '1') {
        for (j = 0; j < my_strlen(S_arr->name) - 1; j++)
            S_arr->full_ls[S_arr->i][j] = S_arr->name[j];
        return (1);
    }
    return (0);
}

char **full_array_create(S_array *S_arr, struct dirent *file,
struct stat data, char **av)
{
    DIR *dir = NULL;

    if (d_flag_array(S_arr) == 1)
        return (0);
    if (S_arr->not_d != 1) {
        if ((dir = opendir(S_arr->name)) != NULL) {
            array_flags(S_arr, file, data, dir);
        } else
            error_right(S_arr);
    }
    if (S_arr->not_d == 1) {
        S_arr->full_ls[0] = my_strcpy(S_arr->full_ls[0], S_arr->name);
        S_arr->rows += 1;
    } else
        closedir(dir);
    S_arr->rows -= 1;
    return (0);
}
