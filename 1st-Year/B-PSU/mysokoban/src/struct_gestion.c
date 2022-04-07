/*
** EPITECH PROJECT, 2021
** struct_gestion.c
** File description:
** sokoban
*/

#include "../include/sokoban.h"

void destroy_struct(global *game)
{
    for (int i = 0; game->map[i] != NULL; i++)
        free(game->map[i]);
    free(game->map);
    free(game->str);
    free(game);
}

void count_x_o_p(global **game, int i, int j)
{
    switch ((*game)->map[i][j]) {
        case 'X': (*game)->nb_x += 1;
            break;
        case 'O': (*game)->nb_o += 1;
            break;
        case 'P': (*game)->nb_p += 1;
            break;
        case '#': (*game)->nb_hashtag += 1;
            break;
    }
}

int find_charact(global **game)
{
    for (int i = 0; (*game)->map[i][0] != '\0'; i++) {
        for (int j = 0; (*game)->map[i][j] != '\0'; j++) {
            count_x_o_p(game, i, j);
            if ((*game)->map[i][j] == 'P') {
                (*game)->pos_xp = i;
                (*game)->pos_yp = j;
            }
            if (!((*game)->map[i][j] == 'X' || (*game)->map[i][j] == 'O'
                || (*game)->map[i][j] == 'P' || (*game)->map[i][j] == '#'
                || (*game)->map[i][j] == ' ' || (*game)->map[i][j] == '\n'))
                return (1);
        }
    }
    if ((*game)->nb_p != 1) return (1);
    if ((*game)->nb_o != (*game)->nb_x) return (1);
    if ((*game)->nb_hashtag < 12) return (1);
    return (0);
}

void init_variables(global **game)
{
    (*game)->pos_xp = 0;
    (*game)->pos_yp = 0;
    (*game)->nb_o = 0;
    (*game)->nb_x = 0;
    (*game)->nb_p = 0;
    (*game)->nb_hashtag = 0;
    (*game)->action = 0;
}

global *create_struct(int ac, char **av)
{
    global *game = malloc(sizeof(global));

    if (game == NULL) return NULL;
    game->str = read_map(ac, av);
    if (game->str == NULL) return NULL;
    init_variables(&game);
    game->map = NULL;
    game->input = NULL;
    game->rows = calcul_row(game->str);
    game->cols = calcul_col(game->str);
    game->map = my_str_to_word_array_separator(game->str, '\n');
    game->ac = ac;
    game->av = av;
    if (game->map == NULL) return NULL;
    if (find_charact(&game) == 1) return NULL;
    return (game);
}