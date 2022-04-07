/*
** EPITECH PROJECT, 2021
** game_gestion.c
** File description:
** matchstick
*/

#include "../include/matchstick.h"

int read_input(global **data)
{
    size_t len = 0;
    int line_size = 0;
    int turn = (*data)->player_turn;

    verif_turn_player(data, &turn);
    line_size = getline(&(*data)->input[turn], &len, stdin);
    if (line_size == EOF) {
        (*data)->ctrl_d = 1;
        return (2);
    }
    if (input_error(data, turn) == 1) return (1);
    if (turn == 0) {
        if (player_turn(data, turn) == 1) return (1);
    } else {
        if (input_not_range(data, turn) == 1) return (1);
    }
    if ((*data)->player_turn == 2)
        display_player_action(data, turn);
    return (0);
}

int game_ai(global **data)
{
    (*data)->row_equal_one = 0;
    (*data)->row_upper_one = 0;
    (*data)->higher_line = (*data)->sticks_line[0];
    (*data)->coord_higher_line = 0;

    my_putstr("AI's turn...\n");
    my_putstr("AI removed ");
    calcul_sticks_row(data);
    if (pick_higher_nb(data) == 1) return (0);
    if (optimise_stick_pick(data) == 1) return (0);
    if (pick_one_stick(data) == 1) return (0);
    return (0);
}

int game_gestion(global **data)
{
    int input = 0;

    input = read_input(data);
    if (input == 2) return (0);
    if (input == 84) return (84);
    if (input == 1)
        (*data)->player_turn = 0;
    if ((*data)->player_turn == 2) {
        display_map(*data);
        if ((*data)->total_stick > 0) {
            game_ai(data);
            display_map(*data);
            (*data)->player_turn = -1;
        }
    }
    return (0);
}