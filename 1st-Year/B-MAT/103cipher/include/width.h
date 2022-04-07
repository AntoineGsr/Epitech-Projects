/*
** EPITECH PROJECT, 2020
** width.h
** File description:
** lib
*/

#ifndef WIDTH_H_
#define WIDTH_H_

char *width_nb(char *str, int i, va_list copy);

struct width {
    char width;
    char *(*type_width)(char *str, int i, va_list copy);
};

static const struct width WIDTH_FUNCS[] = {
    {'0', &width_nb},
    {'1', &width_nb},
    {'2', &width_nb},
    {'3', &width_nb},
    {'4', &width_nb},
    {'5', &width_nb},
    {'6', &width_nb},
    {'7', &width_nb},
    {'8', &width_nb},
    {'9', &width_nb}
};

#endif /* WIDTH_H_ */
