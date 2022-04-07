/*
** EPITECH PROJECT, 2021
** my_sh
** File description:
** mysh
*/

#include "include/my.h"

void handler(int sig)
{
    my_putstr("\n");
    exit(1);
}

int is_line_valid(char *line)
{
    for (int i = 0; line[i] != '\n'; i++)
        if (line[i] != ';' && line[i] != ' ')
            return (1);
    free(line);
    return (0);
}

int are_quotations_valid(char *line, storage_t *storage)
{
    int quotations_nbr = 0;
    char c = '"';
    int other_char = 0;

    for (int i = 0; line[i] != '\n'; i++) {
        if (line[i] != '"')
            other_char = 1;
        if (line[i] == '"')
            quotations_nbr++;
    }
    if (quotations_nbr % 2 == 0 && other_char == 1)
        return (1);
    free(line);
    if (other_char == 0)
        return (0);
    my_puterr("Unmatched '");
    write(2, &c, 1);
    my_puterr("'.\n");
    storage->status = 1;
    return (0);
}

int are_parentheses_valid(char *line, storage_t *storage)
{
    int left = 0;
    int right = 0;
    int quotation = 0;
    for (int i = 0; line[i]; i++) {
        for (; line[i] == '"'; i++)
            quotation = change_quotation_status(quotation);
        if (line[i] == ')' && quotation == 0)
            left++;
        if (left > right) break;
        if (line[i] == '(' && quotation == 0)
            right++;
    } storage->status = 1;
    if (left > right)
        my_puterr("Too many )'s.\n");
    if (right > left)
        my_puterr("Too many ('s.\n");
    if (right == left) {
        storage->status = 0;
        return (check_parentheses_position(line, storage));
    } free(line);
    return (0);
}

void my_sh(storage_t *storage)
{
    char *line = NULL;

    if (isatty(0))
        display_prompt(storage);
    signal(SIGINT, handler);
    if ((line = get_line_my_sh(storage)) == NULL)
        return;
    storage->commands = add_at(storage->commands, my_strdup(line), 0);
    storage->line = line;
    storage->history->history_ll = save_command_into_history(storage,
    line, storage->history->history_ll);
    check_to_start(line, storage);
    if (storage->exit == 0)
        my_sh(storage);
}