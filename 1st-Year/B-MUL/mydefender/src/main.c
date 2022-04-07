/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

int main(int ac, char **av)
{
    sfRenderWindow *window = create_my_window(512, 768);
    sfEvent event;
    game_object **sprite = malloc(sizeof(game_object *) * 21);
    enum pages state = PRESENTATION;
    l_list **node = malloc(sizeof(l_list *) * 4);
    list **gbl = malloc(sizeof(list *) * 4);

    create_all_objects(&sprite);
    modif_money_price(&sprite);
    create_lists(&gbl, &node, sprite);
    while (sfRenderWindow_isOpen(window) && state != QUIT) {
        analyse_events(window, event, &sprite, &state);
        gestion_page(&sprite, &state, window, gbl);
        entity_gestion(&gbl, &node, &sprite, &state);
        gestion_music(&sprite[0], &state);
        sprite[0]->sun_wallet = display_game(&gbl, &node, &state, window);
        sfRenderWindow_display(window);
    }
    destroy_all(&sprite, &gbl, &node, window);
    return (0);
}