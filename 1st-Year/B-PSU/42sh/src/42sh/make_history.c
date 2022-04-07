/*
** EPITECH PROJECT, 2021
** add_path
** File description:
** minishell1
*/

#include "../../include/my.h"

void display_history(storage_t *storage)
{
    while (storage->history->history_ll->next != NULL) {
        printf("%s", storage->history->history_ll->command);
        storage->history->history_ll = storage->history->history_ll->next;
    } storage->history->history_ll = storage->history->history_ll_last_ptr;
}

history_node_t *save_command_into_history(storage_t *storage,
char *line, history_node_t *to_put)
{
    history_node_t *tmp = malloc(sizeof(history_node_t));
    tmp->command = my_strdup(line);
    tmp->index = storage->history->total_command_nbr;
    storage->history->total_command_nbr++;
    tmp->next = to_put;
    tmp->previous = NULL;
    tmp->next->previous = tmp;
    storage->history->history_ll_last_ptr = tmp;
    return (tmp);
}

int does_it_correspond(char *str1, char *str2)
{
    for (int i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return (1);
        }
    } return (0);
}

int check_history_correspondance(storage_t *storage, char *to_check)
{
    int to_return = 0;
    while (storage->history->history_ll->next != NULL) {
        if (does_it_correspond(to_check, storage->history->history_ll->command)
        == 0) {
            define_commands(my_strdup(storage->history->history_ll->command),
            storage);
            to_return = 1;
            break;
        }
        storage->history->history_ll = storage->history->history_ll->next;
    } return (to_return);
}

void make_history(storage_t *storage, char **inputs)
{
    int str_nbr = set_str_nbr(inputs) - 1;
    if (str_nbr != 0 || my_strlen(inputs[0]) == 1)
        return (my_puterr("!: Command not found.\n"));
    char *to_check = inputs[0] + 1;
    if (check_history_correspondance(storage, to_check) == 0) {
        fprintf(stderr, "%s: Event not found.\n", to_check);
    }
    storage->history->history_ll = storage->history->history_ll_last_ptr;
}