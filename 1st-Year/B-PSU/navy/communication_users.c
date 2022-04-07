/*
** EPITECH PROJECT, 2020
** communication_users.c
** File description:
** navy
*/

#include "navy.h"

int val_ret(list *player)
{
    if (player->my_life > 0 && player->ennemi_life == 0) {
        display_map(player);
        my_putstr_fast("I won\n\n");
        return (0);
    } else if (player->ennemi_life > 0 && player->my_life == 0) {
        display_map(player);
        my_putstr_fast("Enemy won\n\n");
        return (1);
    } else
        return (2);
}

int communication_player1(int ac, list *player, struct sigaction sms,
struct sigaction sms2)
{
    display_map(player);
    send_message(player, sms);
    print_attack(&player, sms);
    if ((player->ret = val_ret(player)) != 2)
        return (player->ret);
    receive_message(player);
    print_defense(&player, sms);
    if ((player->ret = val_ret(player)) != 2)
        return (player->ret);
    free(player->input_coord);
    return (2);
}

int communication_player2(int ac, list *player, struct sigaction sms,
struct sigaction sms2)
{
    display_map(player);
    receive_message(player);
    print_defense(&player, sms);
    if ((player->ret = val_ret(player)) != 2)
        return (player->ret);
    send_message(player, sms);
    print_attack(&player, sms);
    if ((player->ret = val_ret(player)) != 2)
        return (player->ret);
    free(player->input_coord);
    return (2);
}

int communication_users(int ac, list *player, struct sigaction sms,
struct sigaction sms2)
{
    int return_val = 2;

    while (return_val == 2) {
        if (ac == 2)
            return_val = communication_player1(ac, player, sms, sms2);
        if (ac == 3)
            return_val = communication_player2(ac, player, sms, sms2);
    }
    return (return_val);
}