/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban
*/

#include "../include/matchstick.h"

int main(int ac, char **av)
{
    global *data = NULL;

    if (error_gestion(ac, av) == 84) return (84);
    data = create_struct(av);
    if (data == NULL) return (84);
    display_map(data);
    while (data->total_stick > 0 && data->ctrl_d == 0) {
        if (game_gestion(&data) == 84)
            return (84);
    }
    if (data->ctrl_d == 1)
        return (0);
    if (data->player_turn < 2) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (1);
    } else {
        my_putstr("You lost, too bad...\n");
        return (2);
    }
}