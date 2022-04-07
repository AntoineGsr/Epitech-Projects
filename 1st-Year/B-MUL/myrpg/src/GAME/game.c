/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

float coeff_window(float window_size, float nb, float div)
{
    float coeff = (nb / div) * window_size;

    return (coeff);
}

void events_log(rpg_t *rpg_tab)
{
    if (rpg_tab->event.type == sfEvtClosed)
        sfRenderWindow_close(rpg_tab->window);
    if (rpg_tab->event.type == sfEvtKeyReleased
        && (rpg_tab->event.key.code == sfKeyEscape
        || rpg_tab->event.key.code == sfKeySpace)
        && rpg_tab->g->link_start_state == LINK_NOT_DONE) {
        rpg_tab->g->link_start_sprite->sprite_rect.top = 6422;
        rpg_tab->g->link_start_sprite->sprite_rect.left = 1800;
        sfSprite_setTextureRect(rpg_tab->g->link_start_sprite->sprite,
        rpg_tab->g->link_start_sprite->sprite_rect);
        if (rpg_tab->g->play == LOAD_EXISTENT_GAME) {
            rpg_tab->g->link_start_state = LOG_PSWD;
        } else
            rpg_tab->g->link_start_state = LOG_NAME;
        sfSound_stop(rpg_tab->u->link_start->sound);
    }
    if (rpg_tab->event.type == sfEvtTextEntered
    && rpg_tab->g->link_start_state >= LOG_NAME
    && rpg_tab->g->link_start_state <= LOG_PSWD)
        input_log(rpg_tab);
}

void game_quests_call(rpg_t *rpg_tab)
{
    if (rpg_tab->g->open_door == true) {
        gestion_door_quest(rpg_tab);
    } else if (rpg_tab->g->card->door_one == false) {
        rpg_tab->g->card->scanner->sprite_rect.left = 0;
        rpg_tab->g->card->access_card_mission = false;
    }
}

void game(rpg_t *rpg_tab)
{
    link_start_handling(rpg_tab);
    game_display(rpg_tab);
    if (rpg_tab->g->open_door == false && rpg_tab->g->water_grab == false)
        rpg_tab->g->left_click = false;
    rpg_tab->g->right_click = false;
    while (sfRenderWindow_pollEvent(rpg_tab->window, &(rpg_tab->event)))
        gestion_event_game(rpg_tab);
    if (rpg_tab->step == GAME_PARAM)
        return;
    if (rpg_tab->g->link_start_state >= LOG_DONE) {
        gestion_entity(rpg_tab);
        game_quests_call(rpg_tab);
        if (rpg_tab->g->water_grab == true
        && rpg_tab->g->water_done == false) {
            gestion_water_quest(rpg_tab);
        } else
            rpg_tab->g->water_grab = false;
    }
}