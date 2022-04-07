/*
** EPITECH PROJECT, 2020
** verif_map.c
** File description:
** navy
*/

#include "navy.h"

int verif_letter(char *copy_txt)
{
    if (copy_txt[2] < 'A' || copy_txt[2] > 'Z')
        return (-1);
    if (copy_txt[5] < 'A' || copy_txt[5] > 'Z')
        return (-1);
    if (copy_txt[10] < 'A' || copy_txt[10] > 'Z')
        return (-1);
    if (copy_txt[13] < 'A' || copy_txt[13] > 'Z')
        return (-1);
    if (copy_txt[18] < 'A' || copy_txt[18] > 'Z')
        return (-1);
    if (copy_txt[21] < 'A' || copy_txt[21] > 'Z')
        return (-1);
    if (copy_txt[26] < 'A' || copy_txt[26] > 'Z')
        return (-1);
    if (copy_txt[29] < 'A' || copy_txt[29] > 'Z')
        return (-1);
    return (0);
}

int verif_nb(char *copy_txt)
{
    if (copy_txt[3] < '1' || copy_txt[3] > '8')
        return (-1);
    if (copy_txt[6] < '1' || copy_txt[6] > '8')
        return (-1);
    if (copy_txt[11] < '1' || copy_txt[11] > '8')
        return (-1);
    if (copy_txt[14] < '1' || copy_txt[14] > '8')
        return (-1);
    if (copy_txt[19] < '1' || copy_txt[19] > '8')
        return (-1);
    if (copy_txt[22] < '1' || copy_txt[22] > '8')
        return (-1);
    if (copy_txt[27] < '1' || copy_txt[27] > '8')
        return (-1);
    if (copy_txt[30] < '1' || copy_txt[30] > '8')
        return (-1);
    return (0);
}

int verif_start_line(char *copy_txt)
{
    if (copy_txt[0] < '2' || copy_txt[0] > '5')
        return (-1);
    if (copy_txt[8] < '1' || copy_txt[8] > '5')
        return (-1);
    if (copy_txt[16] < '2' || copy_txt[16] > '5')
        return (-1);
    if (copy_txt[24] < '2' || copy_txt[24] > '5')
        return (-1);
    return (0);
}

int verif_dot(char *copy_txt)
{
    if (copy_txt[1] != ':')
        return (-1);
    if (copy_txt[4] != ':')
        return (-1);
    if (copy_txt[9] != ':')
        return (-1);
    if (copy_txt[12] != ':')
        return (-1);
    if (copy_txt[17] != ':')
        return (-1);
    if (copy_txt[20] != ':')
        return (-1);
    if (copy_txt[25] != ':')
        return (-1);
    if (copy_txt[28] != ':')
        return (-1);
    return (0);
}