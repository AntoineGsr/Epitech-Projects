/*
** EPITECH PROJECT, 2020
** create_maps.c
** File description:
** navy
*/

#include "navy.h"

int complete_letter(char *boat, char **map)
{
    int letter1 = convert_letter(boat[2]);
    int letter2 = convert_letter(boat[5]);
    int nb1 = convert_nb(boat[3]);
    int nb2 = convert_nb(boat[6]);

    if (letter1 > letter2) {
        for (int i = letter1; i >= letter2; i--) {
            if (map[nb1][i] != '.' && map[nb1][i] != boat[0])
                return (-1);
            map[nb1][i] = boat[0];
        }
    }
    if (letter1 < letter2) {
        for (int i = letter1; i <= letter2; i++) {
            if (map[nb1][i] != '.' && map[nb1][i] != boat[0])
                return (-1);
            map[nb1][i] = boat[0];
        }
    }
    return (0);
}

int complete_number(char *boat, char **map)
{
    int letter1 = convert_letter(boat[2]);
    int letter2 = convert_letter(boat[5]);
    int nb1 = convert_nb(boat[3]);
    int nb2 = convert_nb(boat[6]);

    if (nb1 > nb2) {
        for (int i = nb1; i >= nb2; i--) {
            if (map[nb1][letter1] != '.' && map[nb1][letter1] != boat[0])
                return (-1);
            map[i][letter1] = boat[0];
        }
    }
    if (nb1 < nb2) {
        for (int i = nb1; i <= nb2; i++) {
            if (map[nb1][letter1] != '.' && map[nb1][letter1] != boat[0])
                return (-1);
            map[i][letter1] = boat[0];
        }
    }
}

int complete_map(char *boat, char **map)
{
    if (complete_letter(boat, map) == -1)
        return (-1);
    if (complete_number(boat, map) == -1)
        return (-1);
    return (0);
}

int create_maps(list **player, int ac, char **av)
{
    if (complete_map((*player)->boat2, (*player)->map_me) == -1) return (-1);
    if (complete_map((*player)->boat3, (*player)->map_me) == -1) return (-1);
    if (complete_map((*player)->boat4, (*player)->map_me) == -1) return (-1);
    if (complete_map((*player)->boat5, (*player)->map_me) == -1) return (-1);
    return (0);
}