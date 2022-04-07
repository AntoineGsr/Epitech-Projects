/*
** EPITECH PROJECT, 2020
** malloc_buff_size.c
** File description:
** 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./include/my.h"
#include "./include/specifer.h"
#include "global.h"
#include "bsq.h"

int malloc_buff_size(char const *filepath)
{
    struct stat *buff;
    int size = 0;

    buff = malloc(sizeof(struct stat));
    stat(filepath, buff);
    size = buff->st_size;
    free(buff);
    return (size);
}
