/*
** EPITECH PROJECT, 2021
** define_inputs
** File description:
** define the inputs (command and args)
*/

#include "include/my.h"

int set_words_nbr(char *line)
{
    int words_nbr = 0;
    int quotation = 0;

    if (my_strlen(line) > 0 && line[0] != '\t' &&
        line[0] != ' ' && line[0] != '"')
        words_nbr = 1;
    for (int i = 0, tab_or_space_found = 0; line[i] != '\0'; i++) {
        if (line[i] == '"' && quotation == 0)
            quotation = 1;
        else if (line[i] == '"' && quotation == 1)
            quotation = 0;
        if ((line[i] == ' ' || line[i] == '\t') && quotation == 0)
            tab_or_space_found = 1;
        else if (tab_or_space_found == 1 && line[i] != '\n' && line[i] != '"') {
            words_nbr++;
            tab_or_space_found = 0;
        }
        if (quotation == 1 && line[i] != '"' && words_nbr == 0)
            words_nbr = 1;
    }
    return (words_nbr);
}

int *set_sizes_inputs(int *sizes_inputs, char *line, int words_nbr)
{
    int quotation = 0;

    for (int i = 0, k = 0, size = 0, size_setter = 0; line[i] != '\0'; i++) {
        while (line[i] == '"') {
            quotation = change_quotation_status(quotation);
            i++;
        }
        if ((line[i] != '\t' && line[i] != ' ' &&
            line[i] != '\n') || quotation == 1) {
            size++;
            size_setter = 1;
        }
        else if (size_setter == 1) {
            sizes_inputs[k++] = size;
            size = 0;
            size_setter = 0;
        }
    }
    return (sizes_inputs);
}

int *find_size_inputs(char *line, int words_nbr)
{
    int *sizes_inputs = malloc(sizeof(int) * words_nbr);

    if (!sizes_inputs) {
        my_puterr("Segmentation fault\n");
        return (NULL);
    }
    sizes_inputs = set_sizes_inputs(sizes_inputs, line, words_nbr);
    return (sizes_inputs);
}

char *set_input_str(char *line, int size, int p)
{
    char *str_input = malloc(sizeof(char) * (size + 1));
    int q = 0;
    if (!str_input)
        segfault_char_star();
    for (int i = 0, k = 0, j = 0, rdy_to_set_char = 0; line[i] != '\0'; i++) {
        for (; line[i] == '"'; i++)
            q = change_quotation_status(q);
        if ((line[i] != '\t' && line[i] != ' ' && line[i] != '\n') || q == 1)
            rdy_to_set_char = 1;
        else if (rdy_to_set_char == 1) {
            k++;
            rdy_to_set_char = 0;
        }
        if (((line[i] != '\t' && line[i] != ' ' && line[i] != '\n') ||
            q == 1) && k == p) {
            str_input[j] = line[i];
            j++;
        }
    } str_input[size] = '\0';
    return (str_input);
}

char **define_inputs(char *line)
{
    int *size;
    int words_nbr = set_words_nbr(line);
    char **inputs = malloc(sizeof(char *) * (words_nbr + 1));
    char *str_input;

    if ((size = find_size_inputs(line, words_nbr)) == NULL)
        return (NULL);
    for (int i = 0; i < words_nbr; i++) {
        if ((str_input = set_input_str(line, size[i], i)) == NULL) {
            free(size);
            free(line);
            return (NULL);
        }
        inputs[i] = my_strdup(str_input);
        free(str_input);
    }
    inputs[words_nbr] = NULL;
    free(size);
    free(line);
    return (inputs);
}