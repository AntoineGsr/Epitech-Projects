/*
** EPITECH PROJECT, 2021
** display_prompt
** File description:
** display the prompt of my shell
*/

#include "include/my.h"

int get_slashs_nbr(char *complete_path)
{
    int nbr = 0;

    for (int i = 0; complete_path[i] != '\0'; i++) {
        if (complete_path[i] == '/') {
            nbr++;
        }
    }
    return (nbr);
}

int get_pos_first_char_dir(char *complete_path, int slashs_nbr)
{
    int pos = 0;
    int passed_slashs = 0;

    for (int i = 0; complete_path[i] != '\0'; i++) {
        if (passed_slashs == slashs_nbr) {
            pos = i;
            break;
        }
        if (complete_path[i] == '/') {
            passed_slashs++;
        }
    }
    return (pos);
}

int get_size_name_dir(char *complete_path, int pos)
{
    int size = 0;

    for (int i = pos; complete_path[i] != '\0'; i++) {
        size++;
    }
    return (size);
}

char *get_cur_dir_name(char *complete_path)
{
    int slashs_nbr = get_slashs_nbr(complete_path);
    int pos = get_pos_first_char_dir(complete_path, slashs_nbr);
    int size = get_size_name_dir(complete_path, pos);
    char *name = malloc(sizeof(char) * (size + 1));

    if (!name) {
        my_puterr("Segmentation fault\n");
        return (NULL);
    }
    for (int i = pos, k = 0; complete_path[i] != '\0'; i++, k++) {
        name[k] = complete_path[i];
    }
    name[size] = '\0';
    free(complete_path);
    return (name);
}

void display_prompt(storage_t *storage)
{
    char *cwd = get_cur_dir_name(getcwd(NULL, 0));

    if (!cwd)
        return;
    if (!storage->prompt_change) {
        my_putstr(BOLDGREEN "[minishell_" BOLDRED "♥");
        my_putstr("nmarius" BOLDRED "♥~");
        my_putstr(cwd);
        my_putstr("]†$> " RESET);
    } else {
        my_putstr(storage->prompt_color);
        my_putstr(storage->prompt_text);
        my_putstr(RESET);
    }
    free(cwd);
}