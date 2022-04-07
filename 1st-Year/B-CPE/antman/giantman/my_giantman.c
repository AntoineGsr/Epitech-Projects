/*
** EPITECH PROJECT, 2021
** function with algo of decomp
** File description:
** sous fonction
*/

#include "function.h"
#include "structure.h"

void temporary(giantman **use, char *tmp, char *temp, int *i)
{
    int opn = 0;
    int wrt = 0;

    if ((*use)->files[*i + 1] < '0' || (*use)->files[*i + 1] > '9') {
        for (int b = 0; (*use)->lib->pos[0] != (*use)->files[*i] && b < 9; b++)
            (*use)->lib = (*use)->lib->next;
        opn = open((*use)->av[1], O_WRONLY | O_APPEND);
        wrt = write(opn, (*use)->lib->str, my_strlen((*use)->lib->str));
    } else {
        for (int b = 0; (*use)->files[*i] >= '0'
            && (*use)->files[*i] <= '9'; *i = *i + 1, b++)
            tmp[b] = (*use)->files[*i];
        for (int b = 0; my_strcmp((*use)->lib->pos, tmp) != 0
            && (*use)->lib->next != NULL;)
            (*use)->lib = (*use)->lib->next;
        opn = open((*use)->av[1], O_WRONLY | O_APPEND);
        wrt = write(opn, (*use)->lib->str, my_strlen((*use)->lib->str));
        *i = *i - 1;
    }
    close(opn);
}

void my_giantman(giantman *use)
{
    lst *test = malloc(sizeof(lst));
    char *temp = NULL;
    char *tmp = NULL;
    int opn = 0;
    int wrt = 0;

    put_letters_lib(use, 0);
    test = use->lib;
    for (int i = 0; use->files[i] != '\0'; i++) {
        use->lib = test;
        tmp = my_memset_char(15);
        temp = my_memset_char(15);
        if (use->files[i] < '0' || use->files[i] > '9') {
            opn = open(use->av[1], O_WRONLY | O_APPEND);
            wrt = write(opn, &use->files[i], 1);
            close(opn);
        } else
            temporary(&use, tmp, temp, &i);
        free(tmp);
        free(temp);
    }
}