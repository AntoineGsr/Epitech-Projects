/*
** EPITECH PROJECT, 2021
** var_content
** File description:
** make_set_var_content
*/

#include "../../include/my.h"

char *find_var_content_2(char **inputs)
{
    if (strcmp(inputs[2], "=") != 0)
        return "";
    if (inputs[3] == NULL)
        return "";
    return my_strdup(inputs[3]);
}

char *find_var_content_1(char **inputs)
{
    int i = 0;
    int lenght = 0;
    char *content = NULL;

    for (; inputs[1][i] != '\0' && inputs[1][i] != '='; i++);
    if (inputs[1][i] == '\0')
        return "";
    i++;
    for (int j = i; inputs[1][j] != '\0'; j++, lenght++);
    content = malloc(sizeof(char) * (lenght + 1));
    for (int j = 0; inputs[1][i] != '\0'; j++, i++)
        content[j] = inputs[1][i];
    content[lenght] = '\0';
    return content;
}

char *find_var_content(char **inputs)
{
    if (inputs[2] == NULL)
        return find_var_content_1(inputs);
    else
        return find_var_content_2(inputs);
}