/*
** EPITECH PROJECT, 2021
** B-CPE-200-NCY-2-1-dante-sebastien.raoult
** File description:
** select_way
*/

#include "../include/my.h"
#include "solver.h"

void right_or_down(path_t *pos, char **map)
{
    if (pos->x + 1 <= pos->width + 1 && map[pos->y][pos->x + 1] == '*')
        pos->x += 1;
    else if (pos->y + 1 <= pos->height && map[pos->y + 1][pos->x] == '*')
        pos->y += 1;
}

void left_or_up(path_t *pos, char **map)
{
    if (pos->x - 1 >= 0 && map[pos->y][pos->x - 1] == '*')
        pos->x -= 1;
    else if (pos->y - 1 >= 0 && map[pos->y - 1][pos->x] == '*')
        pos->y -= 1;
}

void back_left_or_up(path_t *pos, char **map)
{
    if (pos->x - 1 >= 0 && map[pos->y][pos->x - 1] == 'o') {
        map[pos->y][pos->x] = 'U';
        pos->x -= 1;
    }
    else if (pos->y - 1 >= 0 && map[pos->y - 1][pos->x] == 'o') {
        map[pos->y][pos->x] = 'U';
        pos->y -= 1;
    }
}

void back_right_or_down(path_t *pos, char **map)
{
    if (pos->x + 1 <= pos->width + 1 && map[pos->y][pos->x + 1] == 'o') {
        map[pos->y][pos->x] = 'U';
        pos->x += 1;
    }
    else if (pos->y + 1 <= pos->height && map[pos->y + 1][pos->x] == 'o') {
        map[pos->y][pos->x] = 'U';
        pos->y += 1;
    }
}