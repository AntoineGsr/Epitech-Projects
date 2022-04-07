/*
** EPITECH PROJECT, 2021
** handle_variable_exist
** File description:
** handle_variable_exists
*/

#include "../../include/my.h"

static char *dup_env_content(char *env_var)
{
    char *res = NULL;
    int lenght = 0;
    int i = 0;

    for (; env_var[i] != '='; i++);
    i++;
    for (int j = i; env_var[j] != '\0'; j++, lenght++);
    res = malloc(sizeof(char) * (lenght + 1));
    for (int j = 0; env_var[i] != '\0'; i++, j++)
        res[j] = env_var[i];
    res[lenght] = '\0';
    return res;
}

static int is_same_varialbe(char *env_var, char *var_name)
{
    int lenght = 0;

    for (; env_var[lenght] != '='; lenght++);
    if (lenght != strlen(var_name))
        return 0;
    for (int i = 0; env_var[i] != '\0' && var_name[i] != '\0'; i++)
        if (env_var[i] != var_name[i])
            return 0;
    return 1;
}

char *is_variable_exist(char *var_name, storage_t *storage)
{
    local_var_t *tmp = storage->local_var;

    while (tmp->next != NULL) {
        if (strcmp(var_name, tmp->var_name) == 0)
            return my_strdup(tmp->content);
        tmp = tmp->next;
    }
    for (int i = 0; storage->env[i] != NULL; i++)
        if (is_same_varialbe(storage->env[i], var_name) == 1)
            return dup_env_content(storage->env[i]);
    return NULL;
}