/*
** EPITECH PROJECT, 2020
** height.h
** File description:
** lib
*/

#ifndef height_H_
#define height_H_

char *height_nb(char *str, int i, va_list copy);

struct height {
    char height;
    char *(*type_height)(char *str, int i, va_list copy);
};

static const struct height height_FUNCS[] = {
    {'0', &height_nb},
    {'1', &height_nb},
    {'2', &height_nb},
    {'3', &height_nb},
    {'4', &height_nb},
    {'5', &height_nb},
    {'6', &height_nb},
    {'7', &height_nb},
    {'8', &height_nb},
    {'9', &height_nb}
};

#endif /* height_H_ */
