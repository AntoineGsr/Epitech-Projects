/*
** EPITECH PROJECT, 2020
** receive_message.c
** File description:
** navy
*/

#include "navy.h"

list *receive_letter(list *player)
{
    while (sig_list->sig_signo != 12) {
        usleep(30000);
        if (sig_list->sig_signo == 10) {
            player->input_coord[0]++;
            player = receive_letter_kill(player);
        }
    }
    return (player);
}

list *verif_transition(list *player)
{
    while (sig_list->sig_signo == 12) {
        player = verif_transition_kill(player);
    }
    sig_list->sig_signo = 0;
    return (player);
}

list *receive_number(list *player)
{
    while (sig_list->sig_signo != 12) {
        usleep(30000);
        if (sig_list->sig_signo == 10) {
            player->input_coord[1]++;
            player = receive_number_kill(player);
        }
    }
    return (player);
}

void receive_message(list *player)
{
    my_putstr("waiting for enemy’s attack...\n");
    player->input_coord = malloc(sizeof(char) * 3);
    player->input_coord[0] = 'A' - 1;
    player->input_coord[1] = '1' - 1;
    pause();
    player = receive_letter(player);
    pause();
    player = verif_transition(player);
    player->input_coord[1]++;
    player = receive_number(player);
    usleep(10000);
    while (kill(player->pid, SIGUSR1) == -1);
    while (usleep(5000) == 0)
        while (kill(player->pid, SIGUSR1) == -1);
}