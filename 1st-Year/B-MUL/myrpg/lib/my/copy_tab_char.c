/*
** EPITECH PROJECT, 2020
** process info .c
** File description:
** process info .c
*/

#include <stdio.h>
#include <stdlib.h>

int get_tab_len(char **tab);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char **copy_tab_char(char **tab)
{
    char **to_return;
    int tab_len = get_tab_len(tab);
    to_return = malloc(sizeof(char *) * ((tab_len) + 1));
    to_return[tab_len] = NULL;
    for (int i = 0; tab[i] != NULL; i++) {
        to_return[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1));
        to_return[i][my_strlen(tab[i])] = '\0';
        to_return[i] = my_strcpy(to_return[i], tab[i]);
    }
    return (to_return);
}