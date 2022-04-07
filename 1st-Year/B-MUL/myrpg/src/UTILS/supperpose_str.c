/*
** EPITECH PROJECT, 2021
** superpose str
** File description:
** my_defender
*/

#include "../../include/my.h"

char *superpose_str(char *base, char *to_put)
{
    int base_size = my_strlen(base);
    int to_put_size = my_strlen(to_put);
    char *to_return = malloc(sizeof(char) * (base_size + 1));
    to_return = my_strcpy(to_return, base);

    if (to_put_size >= base_size) return (to_put);
    for (int i = 0; i < to_put_size; i++) {
        to_return[base_size - i - 1] = to_put[to_put_size - i - 1];
    }
    return (to_return);
}