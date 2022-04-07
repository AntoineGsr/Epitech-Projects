/*
** EPITECH PROJECT, 2021
** ANTMAN
** File description:
** ANTMAN
*/

#ifndef ANTMAN
#define ANTMAN

#include "my.h"
#include "struct.h"
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

compression *create_struct(int ac, char **av);
list *create_gbl_dico(compression *antman, char **av);
l_list *add_first(list **gbl, l_list **l_a, char *value);
void destroy_allocation(compression *antman, list **gbl, l_list **elem);
void destroy_elem(list **gbl, l_list **elem);
void destroy_dico(list **gbl, l_list **elem);
int error_handler(char **, compression *);
int find_sizefiles(char *);
char *my_memset_char(int size);
int verif_dictionary(list **gbl, l_list **elem, char *str, int i);
void complete_dictionary(list **gbl, l_list **elem, compression *antman);
int modifie_frequency(list **gbl, l_list **elem, char *str);
void write_compression(list **gbl, l_list **elem, compression *antman);
int small_file(compression *antman);

#endif /* ANTMAN */