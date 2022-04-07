/*
** EPITECH PROJECT, 2020
** coord_boats.c
** File description:
** navy
*/

#include "navy.h"

char *find_coord(char *boat, char *buff)
{
    boat = my_strcpy(boat, buff);
    boat[7] = '\0';
    return (boat);
}

list *coord_boats(list *player, int ac, char **av, char **buff)
{
    player->boat2 = find_coord(player->boat2, buff[0]);
    player->boat3 = find_coord(player->boat3, buff[1]);
    player->boat4 = find_coord(player->boat4, buff[2]);
    player->boat5 = find_coord(player->boat5, buff[3]);
    return (player);
}