/*
** EPITECH PROJECT, 2021
** B-CPE-200-NCY-2-1-dante-sebastien.raoult
** File description:
** solver
*/

#ifndef SOLVER_H_
#define SOLVER_H_

typedef struct path_s {
    int x;
    int y;
    int width;
    int height;
} path_t;

void right_or_down(path_t *pos, char **map);
void left_or_up(path_t *pos, char **map);
void back_left_or_up(path_t *pos, char **map);
void back_right_or_down(path_t *pos, char **map);
void find_path(char **map);

#endif /* !SOLVER_H_ */
