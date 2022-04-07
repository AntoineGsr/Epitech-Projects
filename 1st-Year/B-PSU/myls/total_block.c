/*
** EPITECH PROJECT, 2020
** total_block.c
** File description:
** my_ls
*/

#include "my_ls.h"

void total_block(S_array *S_arr)
{
    struct dirent *file;
    struct stat data;
    DIR *dir = opendir(S_arr->name);
    char *name;

    while ((file = readdir(dir)) != NULL) {
        name = malloc(sizeof(char) * 100);
        name = my_strcat(my_strcpy(name, S_arr->name), file->d_name);
        if (file->d_name[0] != '~' && file->d_name[0] != '.' &&
            S_arr->mask[1] == '0') {
            data = create_struct(name);
            S_arr->dsk_blk = S_arr->dsk_blk + data.st_blocks;
        }
        if (S_arr->mask[1] == '1') {
            data = create_struct(name);
            S_arr->dsk_blk = S_arr->dsk_blk + data.st_blocks;
        }
        free(name);
    }
    S_arr->dsk_blk = S_arr->dsk_blk / 2;
}
