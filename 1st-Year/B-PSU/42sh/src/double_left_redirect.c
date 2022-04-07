/*
** EPITECH PROJECT, 2021
** left redirect
** File description:
** handle left redirections
*/

#include "include/my.h"

char *store_inputs_user(char *end_word)
{
    char *line = NULL;
    size_t len = 0;
    char *str = malloc(sizeof(char) * 1);
    char *new_str;

    str[0] = '\0';
    while (1) {
        my_putstr("? ");
        if (getline(&line, &len, stdin) == -1)
            return (NULL);
        if (is_same_str(end_word, line)) {
            free(line);
            free(end_word);
            return (str);
        }
        new_str = my_strcat(str, line);
        free(str);
        str = my_strdup(new_str);
        free(new_str);
    }
}

int define_pos_first_redirect(char *command, char c)
{
    for (int i = 0; command[i]; i++)
        if (command[i] == c)
            return (i);
    return (0);
}

char *add_file(char *command, char *file, int pos)
{
    int size = my_strlen(command) + my_strlen(file) + 1;
    char *new_command = malloc(sizeof(char) * (size + 1));
    int k = 0;
    int i = 0;

    for (; k < pos; k++)
        new_command[k] = command[k];
    i = k;
    new_command[i++] = ' ';
    for (int j = 0; file[j]; j++, i++)
        new_command[i] = file[j];
    for (; command[k]; k++, i++)
        new_command[i] = command[k];
    new_command[size] = '\0';
    free(command);
    return (new_command);
}

void double_left_redirect(char *command, storage_t *storage)
{
    char *end_word = define_file_name(command, '<');
    char *str = store_inputs_user(my_strcat(end_word, "\n"));
    int k = define_pos_first_redirect(command, '<');
    int fd = 0;

    command = redefine_command(command, end_word, '<');
    free(end_word);
    if (!str) {
        free(command);
        return;
    }
    fd = open(".db_l_redirect", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, str, my_strlen(str));
    close(fd);
    free(str);
    command = add_file(command, ".db_l_redirect", k);
    execute_command(command, storage);
}