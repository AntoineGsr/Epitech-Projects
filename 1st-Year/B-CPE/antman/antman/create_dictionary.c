/*
** EPITECH PROJECT, 2021
** create_dictionary.c
** File description:
** antman
*/

#include "../include/antman.h"

int modifie_frequency(list **gbl, l_list **elem, char *str)
{
    for (int i = 0; (*elem)->value[i] == str[i]; i++) {
        if ((*elem)->value[i] == '\0' && str[i] == '\0') {
            (*elem)->frequency += 1;
            (*gbl)->code_memory = (*elem)->code;
            *elem = (*gbl)->first;
            return (1);
        }
    }
    return (0);
}

int verif_dictionary(list **gbl, l_list **elem, char *str, int i)
{
    if ((*gbl)->first == NULL)
        return (0);
    for (; *elem != NULL; (*elem) = (*elem)->next) {
        if (modifie_frequency(gbl, elem, str) == 1)
            return (1);
    }
    *elem = (*gbl)->first;
    return (0);
}

void create_code(list **gbl, l_list **elem, char *chain, char *sck_last)
{
    char *chain_bis = my_memset_char(15000);
    int opn = 0;
    int wrt = 0;

    chain_bis = my_strcpy(chain_bis, chain);
    chain_bis[my_strlen(chain_bis) - 1] = '\0';
    if (my_strlen((*elem)->value) > 0) {
        if (verif_dictionary(gbl, elem, chain_bis, 0) == 1) {
            opn = open((*gbl)->av1, O_WRONLY | O_APPEND);
            wrt = write(opn, my_getstr((*gbl)->code_memory),
            my_strlen(my_getstr((*gbl)->code_memory)));
        }
    }
    if (verif_dictionary(gbl, elem, sck_last, 0) == 0)
        *elem = add_first(gbl, elem, sck_last);
    opn = open((*gbl)->av1, O_WRONLY | O_APPEND);
    wrt = write(opn, sck_last, my_strlen(sck_last));
    free(chain_bis);
    close(opn);
}

void complete_dictionary(list **gbl, l_list **elem, compression *antman)
{
    char *chain = my_memset_char(my_strlen(antman->file) + 1);
    char *next_char = my_memset_char(2);
    char *sck_last = my_memset_char(2);

    chain[0] = antman->file[0];
    for (int i = 1; antman->file[i] != '\0'; i++) {
        next_char[0] = antman->file[i];
        sck_last[0] = antman->file[i - 1];
        if (verif_dictionary(gbl, elem, chain, i) == 0) {
            *elem = add_first(gbl, elem, chain);
            create_code(gbl, elem, chain, sck_last);
            chain = my_memset_char(my_strlen(antman->file) + 1);
            chain[0] = next_char[0];
        } else
            chain = my_strcat(chain, next_char);
    }
    create_code(gbl, elem, chain, next_char);
    free(chain);
    free(next_char);
}