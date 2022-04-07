/*
** EPITECH PROJECT, 2020
** list2
** File description:
** pushswap
*/

#include <stdlib.h>
#include <unistd.h>
#include "../../include/my.h"

char *get_at(list_t *list, int pos)
{
    int i = 0;

    if (is_empty_list(list)) {
        return (NULL);
    }
    while (i < pos) {
        i++;
        list = list->next;
    }
    return (list->data);
}

void set_at(list_t *list, char *data, int pos)
{
    int i = 0;

    if (is_empty_list(list)) {
        return;
    }
    while (i < pos) {
        i++;
        list = list->next;
    }
    list->data = data;
}

list_t *free_at(list_t *list, int pos)
{
    list_t *prec = list;
    list_t *cur = list;
    int i = 0;
    if (is_empty_list(list))
        return (NULL);
    if (pos == 0) {
        list = list->next;
        free(cur->data);
        free(cur);
        return (list);
    }
    while (i < pos) {
        i++;
        prec = cur;
        cur = cur->next;
    }
    prec->next = cur->next;
    free(cur->data);
    free(cur);
    return (list);
}

list_t *free_list(list_t *list)
{
    list_t *tmp = NULL;

    while (list) {
        tmp = list->next;
        free(list->data);
        free(list);
        list = tmp;
    }
    return (list);
}

void print_list(list_t *list)
{
    int i = 1;

    while (list) {
        printf("[%d]    %s", i, list->data);
        list = list->next;
        i++;
    }
}