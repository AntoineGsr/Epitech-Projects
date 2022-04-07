/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** navy
*/

#include "navy.h"

global_list *sig_list;

void create_global_list(void)
{
    sig_list = malloc(sizeof(global_list));
    sig_list->sig_pid = 0;
    sig_list->sig_signo = 0;
    sig_list->boat_touch = 0;
    sig_list->sig1_count = 0;
    sig_list->sig2_count = 0;
}

void get_info(int sig, siginfo_t *info, void *context)
{
    sig_list->sig_signo = sig;
    if (sig == 10)
        sig_list->sig1_count += 1;
    if (sig == 12)
        sig_list->sig2_count += 1;
}

int main(int ac, char **av)
{
    list *player;
    char **buff;
    struct sigaction sms = {0};
    struct sigaction sms2 = {0};

    create_global_list();
    sms.sa_sigaction = &get_info;
    sms2.sa_sigaction = &get_info;
    if (helper(ac, av) == 0) return (0);
    if (error_gestion(ac, av) == -1) return (84);
    buff = create_buff(ac, av, buff);
    player = create_struct(ac, av);
    player = coord_boats(player, ac, av, buff);
    if (create_maps(&player, ac, av) == -1) return (84);
    if (connect_users(ac, av, &player) == -1) return (84);
    sigaction(SIGUSR1, &sms, NULL);
    sigaction(SIGUSR2, &sms2, NULL);
    return (communication_users(ac, player, sms, sms2));
}