/*
** EPITECH PROJECT, 2020
** precision.h
** File description:
** lib
*/

#ifndef PRECISION_H_
#define PRECISION_H_

char *dot(char *str, int i);

struct precision {
    char precision;
    char *(*type_preci)(char *str, int i);
};

static const struct precision PRECISION_FUNCS[] = {
    {'.', &dot}
};

#endif /* PRECISION_H_ */
