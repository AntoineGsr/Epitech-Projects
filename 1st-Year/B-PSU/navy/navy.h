/*
** EPITECH PROJECT, 2020
** navy.h
** File description:
** navy
*/

#ifndef BSN_H_
#define BSN_H_

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include "./lib/my/my.h"

typedef struct global_list global_list;
struct global_list
{
    int sig_pid;
    int sig_signo;
    int boat_touch;
    int sig1_count;
    int sig2_count;
};

extern global_list *sig_list;

typedef struct list list;
struct list
{
    char **map_me;
    char **map_ennemi;
    char *boat2;
    char *boat3;
    char *boat4;
    char *boat5;
    char *input_coord;
    char *input_txt;
    int my_life;
    int ennemi_life;
    int pid;
    int defense;
    int touch;
    int letter;
    int nb;
    int ret;
};

int error_gestion(int ac, char **av);

int error_eq_dif_boat(char *copy_txt);

int verif_nb_size(char *copy_txt);

int error_size_boat(char *copy_txt);

int verif_letter(char *copy_txt);

int verif_nb(char *copy_txt);

int verif_nb_size(char *copy_txt);

int verif_start_line(char *copy_txt);

int verif_dot(char *copy_txt);

int helper(int ac, char **av);

int convert_letter(char letter);

int convert_nb(char letter);

char **create_buff(int ac, char **av, char **buff);

int create_maps(list **player, int ac, char **av);

list *create_struct(int ac, char **av);

list *coord_boats(list *player, int ac, char **av, char **buff);

void display_map(list *player);

int connect_users(int ac, char **av, list **player);

void print_defense(list **player, struct sigaction sms);

void print_attack(list **player, struct sigaction sms);

int error_input(char *str);

int read_input(list **player, struct sigaction sms);

int communication_users(int ac, list *player, struct sigaction sms,
struct sigaction sms2);

void receive_message(list *player);

void send_message(list *player, struct sigaction confirmate);

list *verif_transition_kill(list *player);

list *receive_letter_kill(list *player);

list *receive_number_kill(list *player);

#endif /* BSN_H_ */
