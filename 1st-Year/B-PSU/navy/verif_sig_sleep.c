/*
** EPITECH PROJECT, 2020
** verif_sig_sleep.c
** File description:
** navy
*/

#include "navy.h"

list *kill_usleep(list *player, int sig_kill)
{
    while (kill(player->pid, sig_kill) == -1);
    return (player);
}

list *verif_transition_kill(list *player)
{
    while (kill(player->pid, SIGUSR2) == -1);
        if (usleep(30000) == -1)
            player = kill_usleep(player, 12);
    return (player);
}

list *receive_letter_kill(list *player)
{
    while (kill(player->pid, SIGUSR1) == -1);
        if (usleep(30000) == 0)
            player = kill_usleep(player, 10);
    return (player);
}

list *receive_number_kill(list *player)
{
    while (kill(player->pid, SIGUSR1) == -1);
        if (usleep(30000) == 0)
            player = kill_usleep(player, 10);
    return (player);
}
