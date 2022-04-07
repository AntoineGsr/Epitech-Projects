/*
** EPITECH PROJECT, 2020
** flag.h
** File description:
** lib
*/

#ifndef FLAG_H_
#define FLAG_H_

char *diez(char *str, int i, va_list copy);

char *neg_signe(char *str, int i, va_list copy);

char *pos_or_neg(char *str, int i, va_list copy);

char *add_a_zero(char *str, int i, va_list copy);

char *space_to_print(char *str, int i, va_list copy);

struct flag {
    char flag;
    char *(*type_flag)(char *str, int i, va_list copy);
};

static const struct flag FLAG_FUNCS[] = {
    {'#', &diez},
    {'-', &neg_signe},
    {'+', &pos_or_neg},
    {'0', &add_a_zero},
    {' ', &space_to_print}
};

#endif /* FLAG_H_ */
