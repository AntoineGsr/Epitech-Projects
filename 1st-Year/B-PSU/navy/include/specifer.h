/*
** EPITECH PROJECT, 2020
** specifer.h
** File description:
** lib
*/

#ifndef SPECIFER_H_
#define SPECIFER_H_

int integer(va_list list, char *preci);

int octal(va_list list, char *preci);

int hexa(va_list list, char *preci);

int hexa_cap(va_list list, char *preci);

int unsigned_long(va_list list, char *preci);

int character(va_list list, char *preci);

int string(va_list list, char *preci);

int flow(va_list list, char *preci);

int pointer_adress(va_list list, char *preci);

int binary(va_list list, char *preci);

int no_printable(va_list list, char *preci);

int pourcent_double(va_list list, char *preci);

int nothing_print(va_list list, char *preci);

struct specifer {
    char specif;
    int (*type_print)(va_list list, char *preci);
};

static const struct specifer SPECIFER_FUNCS[] = {
    {'d', &integer},
    {'i', &integer},
    {'c', &character},
    {'s', &string},
    {'u', &unsigned_long},
    {'o', &octal},
    {'x', &hexa},
    {'X', &hexa_cap},
    {'f', &flow},
    {'F', &flow},
    {'p', &pointer_adress},
    {'b', &binary},
    {'S', &no_printable},
    {'%', &pourcent_double},
    {'n', &nothing_print}
};

#endif /* SPECIFER_H_ */
