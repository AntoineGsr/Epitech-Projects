/*
** EPITECH PROJECT, 2020
** connection_users.c
** File description:
** navy
*/

#include "navy.h"

void first_message(int sig, siginfo_t *info, void *context)
{
    sig_list->sig_pid = info->si_pid;
    while (kill(info->si_pid, SIGUSR1) == -1);
}

int connect_usr2(int ac, char **av, list **player, struct sigaction sig)
{
    my_putstr_fast("my_pid: ");
    my_put_nbr(getpid());
    my_putstr_fast("\nsuccessfully connected\n\n");
    while (kill(my_getnbr(av[1]), SIGUSR1) == -1);
    sigaction(SIGUSR1, &sig, NULL);
    if (usleep(15000000) == 0)
        return (-1);
    (*player)->pid = sig_list->sig_pid;
    return (0);
}

int connect_usr1(int ac, char **av, list **player, struct sigaction sig)
{
    my_putstr_fast("my_pid:");
    my_put_nbr(getpid());
    my_putstr_fast("\nwaiting for enemy connection...\n");
    sigaction(SIGUSR1, &sig, NULL);
    if (usleep(15000000) == 0)
        return (-1);
    my_putstr_fast("\nenemy connected\n\n");
    (*player)->pid = sig_list->sig_pid;
    return (0);
}

int connect_users(int ac, char **av, list **player)
{
    struct sigaction sig = {0};
    sig.sa_flags = SA_SIGINFO;
    sig.sa_sigaction = &first_message;

    if (ac == 2) {
        if (connect_usr1(ac, av, player, sig) == -1)
            return (-1);
    } else if (ac == 3) {
        if (connect_usr2(ac, av, player, sig) == -1)
            return (-1);
    } else
        return (-1);
    return (0);
}