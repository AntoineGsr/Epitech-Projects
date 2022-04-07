/*
** EPITECH PROJECT, 2021
** handle_variable
** File description:
** handle_variable
*/

#include "../../include/my.h"

static char *find_vars(char *line)
{
    int i = 0;
    int lenght = 0;
    char *var_name = NULL;

    for (; line[i] != '$'; i++);
    i++;
    for (int j = i; line[j] != ' ' && line[j] != '\t' && line[j] != '\0'
    && line[j] != '\n'; j++, lenght++);
    var_name = malloc(sizeof(char) * (lenght + 1));
    for (int j = 0; line[i] != ' ' && line[i] != '\t' && line[i] != '\0'
    && line[j] != '\n'; j++, i++)
        var_name[j] = line[i];
    var_name[lenght] = '\0';
    return var_name;
}

static char *create_new_line(char *line, storage_t *storage)
{
    char *var = find_vars(line);
    char *var_content = is_variable_exist(var, storage);

    if (var_content == NULL) {
        my_puterr(var);
        my_puterr(": Undefined variable.\n");
        return NULL;
    }
    return make_new_line(line, var_content);
}

static int is_dollars_in_line(char *line)
{
    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '$')
            return 1;
    return 0;
}

char *handle_variable(char *line, storage_t *storage)
{
    while (is_dollars_in_line(line)) {
        line = create_new_line(line, storage);
        if (line == NULL)
            return NULL;
    }
    return line;
}