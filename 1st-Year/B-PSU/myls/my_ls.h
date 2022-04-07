/*
** EPITECH PROJECT, 2020
** my_ls.h
** File description:
** my_ls
*/



#ifndef MYLS_H_
#define MYLS_H_

#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <grp.h>
#include <time.h>
#include <pwd.h>
#include "./include/all_h.h"
#include "my_ls.h"
#include "struct_array.h"

char *name_file(int ac, char **av, S_array *S_arr);

int error_right(S_array *S_arr);

int print_ls(char *full_ls, struct stat data, struct dirent *file,
S_array *S_arr);

void init_stuct_array(S_array *S_arr);

void create_mask_array(int ac, char **av, S_array *S_arr);

char **full_array_create(S_array *S_arr, struct dirent *file,
struct stat data, char **av);

char *empty_full_ls(char *full_ls, char *test, int *count);

char *get_my_period(char *period);

int flag_to_exe(struct stat data, struct dirent *file, S_array *S_arr,
char **av);

int no_flags(struct dirent *file);

void *type_file(struct stat data);

struct stat create_struct(char *av);

char *perms_file(struct stat data);

void total_block(S_array *S_arr);

int l_flag(S_array *S_arr, struct dirent *file, struct stat data);

int r_flag(S_array *S_arr, struct dirent *file, struct stat data);

#endif /* MYLS_H_ */
