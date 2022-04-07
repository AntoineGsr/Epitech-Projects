/*
** EPITECH PROJECT, 2021
** make_set
** File description:
** make_set
*/

#include "../../include/my.h"

static int is_alphanum(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 48 ||
        (str[i] > 57 && str[i] < 65) ||
        (str[i] > 90 && str[i] < 97) ||
            str[i] > 122)
            return 0;
    }
    return 1;
}

static int add_local_var_exist(char *var_c, char *var_n, storage_t *storage)
{
    local_var_t *tmp = storage->local_var;

    while (tmp->next != NULL) {
        if (strcmp(var_n, tmp->var_name) == 0) {
            tmp->content = var_c;
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void add_local_var(char *var_content, char *var_name, storage_t *storage)
{

    if (add_local_var_exist(var_content, var_name, storage) == 0) {
        local_var_t *new_var = malloc(sizeof(local_var_t));
        new_var->var_name = my_strdup(var_name);
        new_var->content = my_strdup(var_content);
        new_var->next = storage->local_var;
        storage->local_var = new_var;
    }
}

static char *find_var_name(char **inputs)
{
    int lenght = 0;
    char *var_name = NULL;

    for (; inputs[1][lenght] != '\0' && inputs[1][lenght] != '='; lenght++);
    var_name = malloc(sizeof(char) * (lenght + 1));
    for (int i = 0; inputs[1][i] != '\0' && inputs[1][i] != '='; i++)
        var_name[i] = inputs[1][i];
    var_name[lenght] = '\0';
    return var_name;
}

void make_set(char **inputs, storage_t *storage)
{
    char *var_name = NULL;
    char *var_content = NULL;

    if (inputs[1] == NULL)
        return make_set_no_arg(storage);
    var_name = find_var_name(inputs);
    var_content = find_var_content(inputs);
    if (var_name[0] < 65 || (var_name[0] > 90 && var_name[0] < 97) ||
    var_name[0] > 122) {
        printf("set: Variable name must begin with a letter.\n");
        return;
    }
    if (is_alphanum(var_name) == 0) {
        printf("set: Variable name must contain alphanumeric characters.\n");
        return;
    }
    add_local_var(var_content, var_name, storage);
}