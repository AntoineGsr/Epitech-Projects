/*
** EPITECH PROJECT, 2020
** print_ls.c
** File description:
** my_ls
*/

#include "my_ls.h"

int display_terminal(S_array *S_arr, char *full_ls, int size)
{
    if (S_arr->not_d != 1) {
        for (size += 1; full_ls[size] != '\0'; size++)
            my_putchar(full_ls[size]);
    } else {
        for (size; full_ls[size] != '\0'; size++)
            my_putchar(full_ls[size]);
    }
    my_putchar('\n');
    return (0);
}

int print_name(char *name_nslash, char *full_ls, S_array *S_arr)
{
    int size = my_strlen(full_ls) - 1;

    if (S_arr->mask[5] == '1') {
        my_putstr_fast(full_ls);
        my_putchar('\n');
        return (0);
    }
    if (full_ls[size] == '/')
        full_ls[size] = '\0';
    for (size; size > 0 && full_ls[size] != '/'; size--);
    display_terminal(S_arr, full_ls, size);
    return (0);
}

void print_rights(struct stat data, struct passwd *user, struct group *g_user)
{
    type_file(data);
    perms_file(data);
    my_put_nbr(data.st_nlink);
    my_putchar(' ');
    my_putstr_fast(user->pw_name);
    my_putchar(' ');
    my_putstr_fast(g_user->gr_name);
    my_putchar(' ');
    my_put_nbr(data.st_size);
    my_putchar(' ');
    get_my_period(ctime(&data.st_ctime));
    my_putchar(' ');
}

int print_ls(char *full_ls, struct stat data, struct dirent *file,
S_array *S_arr)
{
    struct passwd *user;
    struct group *g_user;
    struct stat d_verif;
    char *name_nslash = malloc(sizeof(char) * 100);

    user = getpwuid(data.st_uid);
    g_user = getgrgid(data.st_gid);
    if (S_arr->mask[0] == '1') {
        print_rights(data, user, g_user);
    }
    stat(S_arr->sck_name, &d_verif);
    if (S_ISDIR(d_verif.st_mode)) {
        print_name(name_nslash, full_ls, S_arr);
    } else {
        my_putstr_fast(S_arr->sck_name);
        my_putchar('\n');
    }
    free(name_nslash);
    return (0);
}