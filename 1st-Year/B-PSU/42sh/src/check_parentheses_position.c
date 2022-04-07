/*
** EPITECH PROJECT, 2021
** check parentheses position
** File description:
** check the position of the parentheses
*/

#include "include/my.h"

int is_left_parenthese_invalid(char *line, int k)
{
    for (; k >= 0 && line[k] != ';' && line[k] != '|' &&
        line[k] != '&' && line[k] != '>' && line[k] != '<'; k--)
        if (line[k] != ' ' && line[k] != '\t' && line[k] != '(')
            return (1);
    return (0);
}

int check_left_parentheses(char *line)
{
    int k = 0;
    int quotation = 0;

    for (; line[k]; k++) {
        if (line[k] == '"')
            quotation = change_quotation_status(quotation);
        if (line[k] == '(' && is_left_parenthese_invalid(line, k) &&
            quotation == 0)
            return (0);
    }
    return (1);
}

int is_right_parenthese_invalid(char *line, int k)
{
    for (; line[k] != '\n' && line[k] != ';' && line[k] != '|' &&
        line[k] != '&' && line[k] != '>' && line[k] != '<'; k++)
        if (line[k] != ' ' && line[k] != '\t' && line[k] != ')')
            return (1);
    return (0);
}

int check_right_parentheses(char *line)
{
    int k = 0;
    int quotation = 0;

    for (; line[k]; k++) {
        if (line[k] == '"')
            quotation = change_quotation_status(quotation);
        if (line[k] == ')' && is_right_parenthese_invalid(line, k) &&
            quotation == 0)
            return (0);
    }
    return (1);
}

int check_parentheses_position(char *line, storage_t *storage)
{
    int parenthese = 0;
    int quotation = 0;

    for (int i = 0; line[i]; i++) {
        while (line[i] == '"') {
            quotation = change_quotation_status(quotation);
            i++;
        }
        if (line[i] == '(' && quotation == 0)
            parenthese = 1;
    }
    if (parenthese == 0)
        return (1);
    if (check_left_parentheses(line) == 0 || check_right_parentheses(line) == 0)
        return (parenthese_error("Badly placed ()'s.\n", storage, line));
    for (int i = 0; line[i]; i++)
        if (line[i] == '(' && line[i + 1] == ')')
            return (parenthese_error("Invalid null command.\n", storage, line));
    return (1);
}