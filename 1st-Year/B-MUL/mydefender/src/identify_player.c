/*
** EPITECH PROJECT, 2021
** my defender
** File description:
** file to insert input name player
*/

#include "../include/my_defender.h"

void input_name_init(game_object **sprite, sfColor color,
sfRenderWindow *window, sfVector2f vect)
{
    (*sprite)->fontpseudo = sfFont_createFromFile("./images/Ozye.ttf");
    (*sprite)->pseudotext = sfText_create();
    sfText_setFont((*sprite)->pseudotext, (*sprite)->fontpseudo);
    sfText_setColor((*sprite)->pseudotext, color);
    sfText_setCharacterSize((*sprite)->pseudotext, 28);
    sfText_setPosition((*sprite)->pseudotext, vect);
    sfText_setString((*sprite)->pseudotext, (*sprite)->pseudostring);
    sfRenderWindow_drawText(window, (*sprite)->pseudotext, NULL);
    sfFont_destroy((*sprite)->fontpseudo);
    sfText_destroy((*sprite)->pseudotext);
}

void input_name_handling(game_object ***sprite, enum pages *state,
sfRenderWindow *window, sfEvent event)
{
    if (event.text.unicode < 128) {
        if (*state == PSEUDO && my_strlen((*sprite)[0]->pseudostring) < 12) {
            (*sprite)[0]->pseudostring[my_strlen((*sprite)[0]->pseudostring)]
            = event.text.unicode;
        } else if (*state == PSEUDO) {
            *state += 1;
        }
    }
}

void print_player_name(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    sfText_setPosition((*sprite)[0]->pseudotext,
    (sfVector2f){(*sprite)[2]->pos.x + 522, (*sprite)[2]->pos.y});
    sfRenderWindow_drawText(window, (*sprite)[0]->pseudotext, NULL);
}

void print_player_name_ingame(game_object ***sprite, enum pages *state,
sfRenderWindow *window)
{
    if (*state >= MOVE_MORE) {
        input_name_init(&(*sprite)[0], (sfColor){255, 255, 255, 175}, window,
        (sfVector2f){(*sprite)[4]->pos.x -(248 + my_strlen
        ((*sprite)[0]->pseudostring) * 7), (*sprite)[2]->pos.y + 426});
    } else
        input_name_init(&(*sprite)[0], (sfColor){255, 255, 255, 175}, window,
        (sfVector2f){122 - my_strlen((*sprite)[0]->pseudostring) * 7, 426});
}