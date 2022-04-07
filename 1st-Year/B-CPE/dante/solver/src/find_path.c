/*
** EPITECH PROJECT, 2021
** B-CPE-200-NCY-2-1-dante-sebastien.raoult
** File description:
** find_path
*/

#include "../include/my.h"
#include "solver.h"

static void print_map(char **map, path_t *find)
{
    for (int i = 0; i < find->height - 1; i++)
        my_printf("%s\n", map[i]);
    my_printf("%s", map[find->height - 1]);
}

static void clean_map(char **map, path_t *find)
{
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == 'U')
                map[i][j] = '*';
        }
    }
    print_map(map, find);
    free(find);
}

static void go_back(path_t *pos, char **map)
{
    if ((pos->x - 1 >= 0 && map[pos->y][pos->x - 1] == 'o') ||
    (pos->y - 1 >= 0 && map[pos->y - 1][pos->x] == 'o'))
        back_left_or_up(pos, map);
    else if ((pos->x + 1 <= pos->width + 1 && map[pos->y][pos->x + 1] == 'o')
    || (pos->y + 1 <= pos->height && map[pos->y + 1][pos->x] == 'o'))
        back_right_or_down(pos, map);
}

void find_path(char **map)
{
    path_t *find = malloc(sizeof(path_t));

    find->y = 0;
    find->x = 0;
    find->width = my_strlen(map[0]);
    find->height = my_count_word_array(map);
    map[0][0] = 'o';
    while (map[find->y][find->x] != map[find->height - 1][find->width - 1]) {
        if ((find->x + 1 <= find->width && map[find->y][find->x + 1] == '*') ||
        (find->y + 1 <= find->height - 1 && map[find->y + 1][find->x] == '*'))
            right_or_down(find, map);
        else if ((find->x - 1 >= 0 && map[find->y][find->x - 1] == '*') ||
        (find->y - 1 >= 0 && map[find->y - 1][find->x] == '*'))
            left_or_up(find, map);
        else {
            go_back(find, map);
        }
        map[find->y][find->x] = 'o';
    }
    clean_map(map, find);
}
