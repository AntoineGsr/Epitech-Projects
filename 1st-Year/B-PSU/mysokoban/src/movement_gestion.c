/*
** EPITECH PROJECT, 2021
** movement_gestion.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

void check_loose(global **game, int pos_x, int pos_y)
{
    if ((*game)->map[pos_x + 1][pos_y] == '#'
        && (*game)->map[pos_x][pos_y + 1] == '#') {
        (*game)->nb_x -= 1;
        return;
    }
    if ((*game)->map[pos_x + 1][pos_y] == '#'
        && (*game)->map[pos_x][pos_y - 1] == '#') {
        (*game)->nb_x -= 1;
        return;
    }
    if ((*game)->map[pos_x - 1][pos_y] == '#'
        && (*game)->map[pos_x][pos_y + 1] == '#') {
        (*game)->nb_x -= 1;
        return;
    }
    if ((*game)->map[pos_x - 1][pos_y] == '#'
        && (*game)->map[pos_x][pos_y - 1] == '#') {
        (*game)->nb_x -= 1;
        return;
    }
}

void reload_game(global **game, list **list_o, l_list **node_o)
{
    int ac = (*game)->ac;
    char **av = (*game)->av;

    destroy_struct(*game);
    destroy_list(list_o, node_o);
    *game = create_struct(ac, av);
    *list_o = create_global_list(ac, av);
    *node_o = NULL;
    for (int i = 1; (*game)->map[i] != NULL; i++) {
        for (int j = 0; (*game)->map[i][j] != '\0'; j++) {
            if ((*game)->map[i][j] == 'O') {
                *node_o = add_to_list(list_o, node_o, i, j);
            }
        }
    }
}

void register_previous_case(global **game, int stock_x, int stock_y)
{
    if ((*game)->input_ascii == UP || (*game)->input_ascii == DOWN
        || (*game)->input_ascii == LEFT || (*game)->input_ascii == RIGHT) {
        if ((*game)->action == 0) {
            (*game)->map[stock_x][stock_y] = ' ';
        } else {
            if ((*game)->previous_case == 'X')
                (*game)->previous_case = ' ';
            (*game)->map[stock_x][stock_y] = (*game)->previous_case;
            (*game)->previous_case =
            (*game)->map[(*game)->pos_xp][(*game)->pos_yp];
        }
    }
}

void verif_nb_o(global **game, list **list_o, l_list **node_o)
{
    for (; *node_o != NULL; *node_o = (*node_o)->next) {
        if ((*game)->map[(*node_o)->pos_x][(*node_o)->pos_y] == ' ') {
            (*game)->map[(*node_o)->pos_x][(*node_o)->pos_y] = 'O';
            (*game)->nb_o += 1;
        }
    }
    *node_o = (*list_o)->first;
}

void move_charact(global **game, list **list_o, l_list **node_o)
{
    int stock_x = (*game)->pos_xp;
    int stock_y = (*game)->pos_yp;

    (*game)->box_move = 'n';
    (*game)->input_ascii = getch();
    if ((*game)->input_ascii == SPACE_BAR) {
        reload_game(game, list_o, node_o);
        return;
    }
    register_previous_case(game, stock_x, stock_y);
    if ((*game)->input_ascii == UP)
        if (up_down(game, stock_x, stock_y, -1) == 1) return;
    if ((*game)->input_ascii == DOWN)
        if (up_down(game, stock_x, stock_y, 1) == 1) return;
    if ((*game)->input_ascii == RIGHT)
        if (right_left(game, stock_x, stock_y, 1) == 1) return;
    if ((*game)->input_ascii == LEFT)
        if (right_left(game, stock_x, stock_y, -1) == 1) return;
    verif_nb_o(game, list_o, node_o);
}
