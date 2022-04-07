/*
** EPITECH PROJECT, 2020
** send_message.c
** File description:
** navy
*/

#include "navy.h"

void send_message(list *player, struct sigaction confirmate)
{
    my_putstr_fast("attack: ");
    while (read_input(&player, confirmate) == -1)
        my_putstr_fast("attack: ");
    for (char i = 'A' - 1; i != player->input_coord[0]; i++) {
        while (kill(player->pid, SIGUSR1) == -1);
        if (usleep(50000) == 0)
            kill(player->pid, SIGUSR1);
    }
    while (kill(player->pid, SIGUSR2) == -1);
    while (usleep(50000) == 0 && sig_list->sig_signo != 12)
        kill(player->pid, SIGUSR2);
    for (char j = '1' - 1; j != player->input_coord[1]; j++) {
        while (kill(player->pid, SIGUSR1) == -1);
        if (usleep(50000) == 0)
            kill(player->pid, SIGUSR1);
    }
    while (kill(player->pid, SIGUSR2) == -1);
    while (usleep(500000) == -1)
        while (kill(player->pid, SIGUSR2) == -1);
    usleep(1000);
}