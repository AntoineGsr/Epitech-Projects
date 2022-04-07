/*
** EPITECH PROJECT, 2020
** create_struct.c
** File description:
** navy
*/

#include "navy.h"

list *map_malloc(list *player)
{
    player->map_me = malloc(sizeof(char *) * 8);
    player->map_ennemi = malloc(sizeof(char *) * 8);
    for (int i = 0; i < 8; i++) {
        player->map_me[i] = malloc(sizeof(char) * 9);
        player->map_ennemi[i] = malloc(sizeof(char) * 9);
        player->map_me[i][0] = '\0';
        player->map_ennemi[i][0] = '\0';
        for (int j = 0; j < 8; j++) {
            player->map_me[i][j] = '.';
            player->map_ennemi[i][j] = '.';
        }
        player->map_me[i][8] = '\0';
        player->map_ennemi[i][8] = '\0';
    }
    return (player);
}

char *boat_malloc(int size)
{
    char *boat = malloc(sizeof(char) * size);
    for (int i = 0; i < size; i++)
        boat[i] = '0';
    boat[7] = '\0';
    return (boat);
}

list *create_struct(int ac, char **av)
{
    list *player = malloc(sizeof(*player));

    if (player == NULL)
        return NULL;
    player = map_malloc(player);
    player->boat2 = boat_malloc(8);
    player->boat3 = boat_malloc(8);
    player->boat4 = boat_malloc(8);
    player->boat5 = boat_malloc(8);
    player->my_life = 14;
    player->ennemi_life = 14;
    player->input_coord = NULL;
    player->input_txt = NULL;
    player->pid = getpid();
    player->defense = 0;
    player->touch = 0;
    player->letter = 0;
    player->nb = 0;
    player->ret = 2;
    return (player);
}