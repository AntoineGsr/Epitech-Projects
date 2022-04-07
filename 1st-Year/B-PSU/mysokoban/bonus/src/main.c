/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

int main(int ac, char **av)
{
    global *game = create_struct(ac, av);
    list *list_o = create_global_list(ac, av);
    l_list *node_o = NULL;
    int ret_value = 0;

    if (helper(ac, av) == 1) return (0);
    if (game == NULL) return (84);
    if (loop_create_list(&game, &list_o, &node_o) == 84) return (84);
    ncurses_activation();
    while (game->nb_o > 0 && game->nb_x > 0) {
        display_map(game);
        move_charact(&game, &list_o, &node_o);
        refresh();
    }
    display_map(game);
    refresh();
    if (game->nb_x == 0 && game->nb_o > 0)
        ret_value = 1;
    leave_game(game, &list_o, &node_o);
    return (ret_value);
}