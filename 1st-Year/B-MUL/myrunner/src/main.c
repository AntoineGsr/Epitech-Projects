/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** my_runner
*/

#include "my_runner.h"

int main(int ac, char **av)
{
    sfRenderWindow *window = create_my_window(1920, 1080);
    sfEvent event;
    game_object **sprite = malloc(sizeof(game_object *) * 20);
    enum pages state = PRESS;
    l_list *obstacles = malloc(sizeof(l_list));
    list *gbl = NULL;

    if (error_gestion(ac, av) == -1) return (84);
    if (helper_gestion(ac, av) == -1) return (0);
    gbl = create_all_objects(&sprite, ac, av, &obstacles);
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, event, &sprite, &state);
        gestion_page(sprite, &state, window, &gbl);
        reaction_obstacles(&gbl, &obstacles, &state, &sprite);
        obstacles_gestion(&gbl, &obstacles, &state, window);
        sfRenderWindow_display(window);
    }
    destroy_all_objects(&sprite, &window, &gbl, &obstacles);
    return (0);
}