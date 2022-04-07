/*
** EPITECH PROJECT, 2020
** 104intersection.h
** File description:
** 103cipher
*/

#ifndef INTER_H_
#define INTER_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../lib/my/my.h"

int helper(int ac, char **av);

int error_gestion(int ac, char **av);

int type_form(int ac, char **av);

int line_para(int ac, char **av);

int intersection_point(int ac, char **av);

#endif /* INTER_H_ */
