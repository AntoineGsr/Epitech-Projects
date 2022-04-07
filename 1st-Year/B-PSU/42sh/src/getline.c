/*
** EPITECH PROJECT, 2021
** get_line
** File description:
** getline
*/

#include "include/my.h"

static int find_ignoreeof_loc(storage_t *storage)
{
    int res = 1;
    local_var_t *tmp = storage->local_var;

    while (tmp->next != NULL)  {
        if (strcmp(tmp->var_name, "ignoreeof") == 0)
            res = atoi(tmp->content);
        tmp = tmp->next;
    }
    return res;
}

char *get_line_my_sh(storage_t *storage)
{
    char *line = NULL;
    int ignoreeof_loc = find_ignoreeof_loc(storage);
    size_t len = 0;

    if (getline(&line, &len, stdin) == -1) {
        storage->ignoreeof++;
        if (storage->ignoreeof == ignoreeof_loc && ignoreeof_loc > 0) {
            free(line);
            return NULL;
        } else {
            printf("Use \"exit\" to leave.\n");
            clearerr(stdin);
            return my_strdup("");
        }
    }
    storage->ignoreeof = 0;
    return line;
}