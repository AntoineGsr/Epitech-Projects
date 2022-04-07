/*
** EPITECH PROJECT, 2021
** text_gestion.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void display_info_game(char *str, sfColor color, sfRenderWindow *window,
sfVector2f vect)
{
    sfFont *font = sfFont_createFromFile("./images/Ozye.ttf");
    sfText *text = sfText_create();
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, 28);
    sfText_setPosition(text, vect);
    sfText_setString(text, str);
    sfRenderWindow_drawText(window, text, NULL);
    sfFont_destroy(font);
    sfText_destroy(text);
}

void display_text(list ***gbl, l_list ***node, sfRenderWindow *window,
enum pages *state)
{
    display_info_game(my_getstr((*gbl)[0]->nb_sun),
    (sfColor){255, 255, 255, 255}, window, (sfVector2f){30, 85});
    display_info_game("Kill:", (sfColor){255, 255, 255, 255}, window,
    (sfVector2f){25, 640});
    display_info_game(my_getstr((*gbl)[0]->score),
    (sfColor){255, 255, 255, 255}, window, (sfVector2f){90, 640});
    display_info_game("Wave:", (sfColor){255, 255, 255, 255}, window,
    (sfVector2f){25, 680});
    display_info_game(my_getstr((*gbl)[1]->max_node),
    (sfColor){255, 255, 255, 255}, window, (sfVector2f){120, 680});
    display_info_game("Life:", (sfColor){255, 255, 255, 255}, window,
    (sfVector2f){25, 600});
    display_info_game(my_getstr((*gbl)[0]->life_house),
    (sfColor){255, 255, 255, 255}, window, (sfVector2f){100, 600});
    if ((*gbl)[1]->max_node - (*gbl)[0]->nb_entity ==  - (*gbl)[0]->nb_entity)
        *state = ENTITY_CREATION;
}