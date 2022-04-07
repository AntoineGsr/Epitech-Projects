/*
** EPITECH PROJECT, 2021
** init_game_variables.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void create_objects_menu(game_object ***sprite)
{
    (*sprite)[0] = create_object("./images/presentation.png",
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 512, 768});
    (*sprite)[1] = create_object("./images/press_enter.png",
    (sfVector2f){202, 441}, (sfIntRect){0, 0, 135, 16});
    (*sprite)[2] = create_object("./images/main_menu.jpg",
    (sfVector2f){0, 0}, (sfIntRect){512, 0, 1024, 768});
    (*sprite)[3] = create_object("./images/falls_menu.png",
    (sfVector2f){0, 384}, (sfIntRect){512, 0, 512, 384});
    (*sprite)[4] = create_object("./images/raven.png",
    (sfVector2f){370, 337}, (sfIntRect){0, 0, 144, 156});
    (*sprite)[8] = create_object("./images/tutorial_part1.png",
    (sfVector2f){0, 768}, (sfIntRect){0, 0, 1300, 768});
    (*sprite)[9] = create_object("./images/menu_button.png",
    (sfVector2f){1182, 0}, (sfIntRect){0, 0, 95, 87});
    create_music("./sounds/musics/game_music.ogg", &(*sprite)[0]);
}

void create_objects_game(game_object ***sprite)
{
    (*sprite)[10] = create_object("./images/card_tournesol.png",
    (sfVector2f){119, 7}, (sfIntRect){0, 0, 107, 96});
    (*sprite)[11] = create_object("./images/card_shooter.png",
    (sfVector2f){226, 7}, (sfIntRect){0, 0, 102, 96});
    (*sprite)[12] = create_object("./images/card_carnivor.png",
    (sfVector2f){330, -1}, (sfIntRect){0, 0, 104, 104});
    (*sprite)[13] = create_object("./images/card_bomb.png",
    (sfVector2f){434, 3}, (sfIntRect){0, 0, 104, 104});
    (*sprite)[14] = create_object("./images/card_frozen.png",
    (sfVector2f){538, 15}, (sfIntRect){0, 0, 112, 84});
    (*sprite)[15] = create_object("./images/sun_wallet.png",
    (sfVector2f){28, 20}, (sfIntRect){0, 0, 64, 64});
    (*sprite)[16] = create_object("./images/pause_menu.png",
    (sfVector2f){500, 224}, (sfIntRect){0, 0, 300, 100});
    (*sprite)[17] = create_object("./images/pause_resume.png",
    (sfVector2f){500, 334}, (sfIntRect){0, 0, 300, 100});
    (*sprite)[18] = create_object("./images/pause_quit.png",
    (sfVector2f){500, 444}, (sfIntRect){0, 0, 300, 100});
    (*sprite)[19] = create_object("./images/obstacle.png",
    (sfVector2f){670, 0}, (sfIntRect){0, 0, 33, 114});
}

void create_all_objects(game_object ***sprite)
{
    create_objects_menu(sprite);
    create_objects_game(sprite);
    (*sprite)[20] = create_object("./images/tournesol.png",
    (sfVector2f){30, 100}, (sfIntRect){0, 0, 116, 128});
}

void modif_money_price(game_object ***sprite)
{
    (*sprite)[0]->pseudostring = my_memset_char(13);
    (*sprite)[10]->price = 50;
    (*sprite)[11]->price = 100;
    (*sprite)[12]->price = 150;
    (*sprite)[13]->price = 25;
    (*sprite)[14]->price = 175;
}

void create_lists(list ***gbl, l_list ***node, game_object **sprite)
{
    for (int i = 0; i < 4; i++) {
        (*gbl)[i] = create_global_list(sprite);
        (*node)[i] = NULL;
    }
}