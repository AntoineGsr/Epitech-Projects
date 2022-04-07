/*
** EPITECH PROJECT, 2021
** find file to redirect
** File description:
** find the file for < redirection
*/

#include "include/my.h"

void find_position_left_redirect(char **inputs_with_redirect, forl_t *f)
{
    for (; inputs_with_redirect[f->i]; f->i++) {
        for (f->j = 0; inputs_with_redirect[f->i][f->j]; f->j++)
            if (inputs_with_redirect[f->i][f->j] == '<')
                break;
        if (inputs_with_redirect[f->i][f->j] != '\0')
            break;
    }
    f->j++;
    while (inputs_with_redirect[f->i][f->j] == ' ' ||
        inputs_with_redirect[f->i][f->j] == '\t')
        f->j++;
    if (inputs_with_redirect[f->i][f->j] == '\0') {
        f->i++;
        f->j = 0;
    }
}

char *find_file_to_redirect(char **inputs_with_redirect)
{
    forl_t f = {0, 0};
    int len = 0;
    char *file_path;

    find_position_left_redirect(inputs_with_redirect, &f);
    for (int m = f.i, n = f.j; inputs_with_redirect[m][n] &&
        inputs_with_redirect[m][n] != ' ' &&
        inputs_with_redirect[m][n] != '\t'; n++)
        len++;
    file_path = malloc(sizeof(char) * (len + 1));
    for (int k = 0; inputs_with_redirect[f.i][f.j] &&
        inputs_with_redirect[f.i][f.j] != ' ' &&
        inputs_with_redirect[f.i][f.j] != '\t'; k++, f.j++)
        file_path[k] = inputs_with_redirect[f.i][f.j];
    file_path[len] = '\0';
    return (file_path);
}