/*
** EPITECH PROJECT, 2021
** change quotation status
** File description:
** quatation turned on when off, and turned off when on
*/

#include "include/my.h"

int change_quotation_status(int quotation)
{
    if (quotation == 0)
        quotation = 1;
    else if (quotation == 1)
        quotation = 0;
    return (quotation);
}