/*
** EPITECH PROJECT, 2020
** print_action.c
** File description:
** navy
*/

#include "navy.h"

char *defense(list **player)
{
    int letter = convert_letter((*player)->input_coord[0]);
    int nb = convert_nb((*player)->input_coord[1]);

    if (!((*player)->map_me[nb][letter] >= '2'
        && (*player)->map_me[nb][letter] <= '5')) {
        if ((*player)->map_me[nb][letter] != 'x')
            (*player)->map_me[nb][letter] = 'o';
        while (usleep(50000) == 0);
        while (kill((*player)->pid, SIGUSR2) == -1);
        return ("missed");
    }
    (*player)->my_life -= 1;
    (*player)->map_me[nb][letter] = 'x';
    while (usleep(50000) == 0);
    while (kill((*player)->pid, SIGUSR1) == -1);
    return ("hit");
}

char *attack(list **player)
{
    int letter = convert_letter((*player)->input_coord[0]);
    int nb = convert_nb((*player)->input_coord[1]);

    while (kill((*player)->pid, SIGUSR2) == -1);
    while (usleep(50000) == 0);
    if (sig_list->sig_signo == 12) {
        if ((*player)->map_ennemi[nb][letter] != 'x')
            (*player)->map_ennemi[nb][letter] = 'o';
        return ("missed");
    }
    (*player)->ennemi_life -= 1;
    (*player)->map_ennemi[nb][letter] = 'x';
    return ("hit");
}

char *hit_or_missed(list **player, struct sigaction sms)
{
    if ((*player)->defense == 1) {
        return (defense(player));
    }
    if ((*player)->defense == 0) {
        return (attack(player));
    }
    return ("ERROR");
}

void print_defense(list **player, struct sigaction sms)
{
    (*player)->defense = 1;
    my_putchar((*player)->input_coord[0]);
    my_putchar((*player)->input_coord[1]);
    my_putstr_fast(": ");
    my_putstr_fast(hit_or_missed(player, sms));
    my_putstr_fast("\n\n");
}

void print_attack(list **player, struct sigaction sms)
{
    (*player)->defense = 0;
    my_putchar((*player)->input_coord[0]);
    my_putchar((*player)->input_coord[1]);
    my_putstr_fast(": ");
    my_putstr_fast(hit_or_missed(player, sms));
    my_putstr_fast("\n\n");
}