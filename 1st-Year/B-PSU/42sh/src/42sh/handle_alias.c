/*
** EPITECH PROJECT, 2021
** add_path
** File description:
** minishell1
*/

#include "../../include/my.h"

char **separate_array_separator_pt2(storage_t *storage, char **inputs,
char **to_return, int *index)
{
    free(inputs[0]);
    for (int i = 1; inputs[i] != NULL; i++) {
        to_return[*index] = my_strdup(inputs[i]);
        free(inputs[i]);
        (*index)++;
    } free(inputs);
    return (to_return);
}

char **separate_array_separator(storage_t *storage, char **inputs)
{
    char **to_return;
    int nbr_of_spaces = 0;
    int len_of_inputs = 0;
    int index = 0;
    char *token = NULL;
    for (int i = 0; inputs[i] != NULL; i++) {
        len_of_inputs++;
    } for (int i = 0; inputs[0][i] != '\0'; i++) {
        if (inputs[0][i] == ' ')
            nbr_of_spaces++;
    } to_return = malloc(sizeof(char *) * (nbr_of_spaces + len_of_inputs + 1));
    to_return[nbr_of_spaces + len_of_inputs] = NULL;
    token = strtok(inputs[0], " ");
    while (token != NULL) {
        to_return[index] = my_strdup(token);
        index++;
        token = strtok(NULL, " ");
    } to_return = separate_array_separator_pt2(storage, inputs,
    to_return, &index);
    return (to_return);
}

char **aplly_alias(storage_t *storage, char **inputs)
{
    storage->alias->alias_loop = 0;
    storage->alias->alias_ll = storage->alias->alias_ll_last_ptr;
    for (int stop = 1; stop != 0;){
        stop = 0;
        while (storage->alias->alias_ll->next != NULL) {
            if (strcmp(inputs[0], storage->alias->alias_ll->arg_one) == 0) {
                free(inputs[0]);
                inputs[0] = my_strdup(storage->alias->alias_ll->arg_two);
                inputs = separate_array_separator(storage, inputs);
                storage->alias->alias_loop++;
                stop++;
                break;
            } storage->alias->alias_ll = storage->alias->alias_ll->next;
        } storage->alias->alias_ll = storage->alias->alias_ll_last_ptr;
        if (storage->alias->alias_loop >= 40) {
            fprintf(stderr, "Alias loop.\n");
            storage->alias->alias_error = 1;
            break;
        }
    } storage->alias->alias_ll = storage->alias->alias_ll_last_ptr;
    return (inputs);
}