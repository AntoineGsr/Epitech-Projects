/*
** EPITECH PROJECT, 2021
** mouse_move_minigames_click.c
** File description:
** mydefender
*/

#include "../include/my_defender.h"

void mouse_move_mg_choose(sfEvent event, enum pages *state)
{
    if (*state < PLANT_CHOSE_CLICK && event.mouseMove.x >= 129
        && event.mouseMove.x <= 249) {
        if (event.mouseMove.y >= 306 && event.mouseMove.y <= 343)
            *state = PLANT_CHOSE;
    }
    if (*state < PLANT_CHOSE_CLICK && event.mouseMove.x >= 264
        && event.mouseMove.x <= 387) {
        if (event.mouseMove.y >= 308 && event.mouseMove.y <= 340)
            *state = ZOMBIE_CHOSE;
    }
    if (event.mouseMove.x >= 156 && event.mouseMove.x <= 356) {
        if (event.mouseMove.y >= 433 && event.mouseMove.y <= 468)
            *state = MINI_GAMES_OK;
    }
}

void mouse_move_mg_plant(sfEvent event, enum pages *state)
{
    if (*state >= PLANT_CHOSE_CLICK && *state < MINI_GAMES_OK) {
        *state = PLANT_EXIT;
        if ((event.mouseMove.x >= 102 && event.mouseMove.x <= 156)
            && (event.mouseMove.y >= 315 && event.mouseMove.y <= 346))
            *state = SUN_FLOWER_PRESENT;
        if ((event.mouseMove.x >= 166 && event.mouseMove.x <= 224)
        && (event.mouseMove.y >= 302 && event.mouseMove.y <= 346))
            *state = GREEN_FLOWER_PRESENT;
        if ((event.mouseMove.x >= 237 && event.mouseMove.x <= 295)
        && (event.mouseMove.y >= 297 && event.mouseMove.y <= 344))
            *state = BLUE_FLOWER_PRESENT;
        if ((event.mouseMove.x >= 307 && event.mouseMove.x <= 362)
        && (event.mouseMove.y >= 303 && event.mouseMove.y <= 345))
            *state = CARNIVORE_FLOWER_PRESENT;
        if ((event.mouseMove.x >= 371 && event.mouseMove.x <= 427)
        && (event.mouseMove.y >= 301 && event.mouseMove.y <= 349))
            *state = MINE_FLOWER_PRESENT;
    }
}

void mouse_move_minigames_click(sfEvent event, enum pages *state)
{
    if (!(*state >= PLANT_CHOSE_CLICK && *state <= ZOMBIE_EXIT))
        *state = MINI_GAMES_CLICK;
    mouse_move_mg_choose(event, state);
    mouse_move_mg_plant(event, state);
}