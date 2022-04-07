/*
** EPITECH PROJECT, 2021
** FUNCTION
** File description:
** FUNCTION
*/

#ifndef FUNCT_H_
#define FUNCT_H_

#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "structure.h"
#include "../lib/my/my.h"

typedef struct {
    int x;
    int a;
    char *files;
    char **av;
    lst *lib;
} giantman;

int main(int, char **);
void my_giantman(giantman *);
giantman lib_handle(giantman, int);
void free_all(giantman *);
void use_set(giantman *, char **);
int find_sizefiles_giant(char *);
int intlen(int);
int other_error(char **, giantman *);
char *my_memset_char(int);
void put_letters_lib(giantman *use, int i);

#endif /* FUNCT_H_ */