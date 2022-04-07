/*
** EPITECH PROJECT, 2021
** function for set the program or for finish
** File description:
** sous fonction
*/

#include "function.h"
#include "structure.h"

char *my_memset_char(int size)
{
    char *str = malloc(sizeof(char) * size);

    for (int i = 0; i < size; i++)
        str[i] = '\0';
    return (str);
}

void use_set(giantman *use, char **av)
{
    use->av = av;
    use->lib = malloc(sizeof(lst));
    use->x = 0;
    use->a = 1;
}

void free_all(giantman *use)
{
    free(use->files);
}