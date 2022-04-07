/*
** EPITECH PROJECT, 2021
** handle_variable_make_new
** File description:
** handle_variable_make_new
*/

#include "../../include/my.h"

static char *make_part_3_line(char *line)
{
    int lenght = 0;
    int i = 0;
    char *res = NULL;

    for (; line[i] != '$'; i++);
    for (; line[i] != ' ' && line[i] != '\t' && line[i] != '\0'
    && line[i] != '\n'; i++);
    for (int j = i; line[j] != '\0'; j++, lenght++);
    res = malloc(sizeof(char) * (lenght + 1));
    for (int j = 0; line[i] != '\0'; i++, j++)
        res[j] = line[i];
    res[lenght] = '\0';
    return res;
}

static char *make_part_1_line(char *line)
{
    int lenght = 0;
    char *res = NULL;

    for (int i = 0; line[i] != '$'; i++, lenght++);
    res = malloc(sizeof(char) * (lenght + 1));
    for (int i = 0; line[i] != '$'; i++)
        res[i] = line[i];
    res[lenght] = '\0';
    return res;
}

char *make_new_line(char *line, char *var_content)
{
    char *part1 = make_part_1_line(line);
    char *part2 = var_content;
    char *part3 = make_part_3_line(line);

    part1 = my_strcat(part1, part2);
    part1 = my_strcat(part1, part3);
    free(part2);
    free(part3);
    return part1;
}