/*
** EPITECH PROJECT, 2020
** process info .c
** File description:
** process info .c
*/

#include <stdio.h>
#include <stdlib.h>

char **str_to_tab(char *str, char sep)
{
    char **tab = NULL;
    char *word = NULL;
    int k = 0;
    int b = 0;
    int nb_line = 0;
    int nb_char = 0;
    int save_k = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == sep) nb_line++;
    tab = malloc(sizeof(char *) * (nb_line + 2));
    tab[nb_line + 1] = NULL;
    for (int j = 0, save_k = k - 1; j < nb_line + 1; j++, save_k = k - 1) {
        for (nb_char = 0; str[k] != '\0' && str[k] != sep; k++, nb_char++);
        k++;
        tab[j] = malloc(sizeof(char) * (nb_char + 1));
        tab[j][nb_char] = '\0';
        for (int a = save_k + 1, b = 0; str[a] != '\0' &&
        str[a] != sep; a++, b++)
            tab[j][b] = str[a];
    } return (tab);
}