/*
** EPITECH PROJECT, 2020
** struct_array.h
** File description:
** my_ls
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct S_array S_array;
struct S_array {
    char **full_ls;
    char *mask;
    char *stock;
    char *sck_name;
    char *name;
    int rows;
    int dsk_blk;
    int not_d;
    int total_name;
    int i;
};

#endif /* STRUCT_H_ */
