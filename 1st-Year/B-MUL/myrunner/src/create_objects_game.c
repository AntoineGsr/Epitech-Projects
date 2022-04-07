/*
** EPITECH PROJECT, 2021
** create_objects_game.c
** File description:
** my_runner
*/

#include "my_runner.h"

void create_objects_game(game_object ***sprite)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 1920, 1080};
    sfVector2f pos2 = {200, 940};
    sfIntRect rect2 = {0, 0, 81, 81};
    sfVector2f pos3 = {593, 0};
    sfIntRect rect3 = {0, 0, 735, 1040};
    sfVector2f pos4 = {860, 925};
    sfIntRect rect4 = {0, 0, 200, 22};
    sfVector2f pos5 = {100, 970};
    sfIntRect rect5 = {0, 0, 80, 35};

    for (int i = 0; i < 8; i++) {
        (*sprite)[i] = create_object(filepath_bck(i), pos, rect);
        (*sprite )[i + 8] = create_object(filepath_bck(i), pos, rect);
    }
    (*sprite)[16] = create_object("./image/character.png", pos2, rect2);
    (*sprite)[17] = create_object("./image/bck_charact.jpg", pos3, rect3);
    (*sprite)[18] = create_object("./image/press_to_start.png", pos4, rect4);
    (*sprite)[19] = create_object("./image/pause.png", pos4, rect4);
}

list *create_all_objects(game_object ***sprite, int ac, char **av,
l_list **obstacles)
{
    list *gbl = create_obstacles(ac, av, obstacles);

    create_objects_game(sprite);
    create_music(sprite);
    return (gbl);
}
