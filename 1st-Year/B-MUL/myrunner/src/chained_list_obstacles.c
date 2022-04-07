/*
** EPITECH PROJECT, 2021
** chained_list_obstacles.c
** File description:
** my_runner
*/

#include "my_runner.h"

l_list *create_sprite_obstacle(l_list *new, int obs, int pos)
{
    if (obs == 2) {
        new->texture = sfTexture_createFromFile("./image/obstacle1.png", NULL);
        new->sprite = sfSprite_create();
        new->pos = (sfVector2f){600, 986};
        new->rect = (sfIntRect){0, 0, 80, 35};
    }
    if (obs == 3) {
        new->texture = sfTexture_createFromFile("./image/coin.png", NULL);
        new->sprite = sfSprite_create();
        new->pos = (sfVector2f){600, 956};
        new->rect = (sfIntRect){0, 0, 40, 40};
    }
    if (obs == 4) {
        new->texture = sfTexture_createFromFile("./image/portal.png", NULL);
        new->sprite = sfSprite_create();
        new->pos = (sfVector2f){600, 866};
        new->rect = (sfIntRect){0, 0, 75, 145};
    }
    return (new);
}

l_list *add_to_list(list **gbl, l_list **obstacles, int nb)
{
    l_list *new = malloc(sizeof(l_list));

    if (new == NULL)
        return NULL;
    if ((*gbl)->first == NULL) {
        (*gbl)->first = new;
        (*gbl)->last = new;
        new->previous = NULL;
    } else {
        new->previous = *obstacles;
        (*obstacles)->next = new;
        (*gbl)->last = new;
    }
    (*gbl)->nb_obs += 1;
    new->obs = nb;
    new = create_sprite_obstacle(new, nb, (*gbl)->nb_obs);
    new->next = NULL;
    return (new);
}

list *create_obstacles(int ac, char **av, l_list **obstacles)
{
    char *map = open_game_map(ac, av);
    list *gbl = malloc(sizeof(list));

    if (gbl == NULL) return NULL;
    gbl->nb_obs = 0;
    gbl->first_pos = 0;
    gbl->speed = 0;
    gbl->ac = ac;
    gbl->av = malloc(sizeof(char) * my_strlen(av[1]));
    gbl->av = av[1];
    gbl->first = malloc(sizeof(l_list));
    gbl->last = malloc(sizeof(l_list));
    gbl->first = NULL;
    gbl->last = NULL;
    for (int i = 0; map[i] != '\0'; i++)
        (*obstacles) = add_to_list(&gbl, obstacles, map[i] - '0');
    (*obstacles) = add_to_list(&gbl, obstacles, 5);
    (*obstacles) = gbl->first;
    free(map);
    return (gbl);
}