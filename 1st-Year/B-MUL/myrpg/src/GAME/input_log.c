/*
** EPITECH PROJECT, 2021
** input_log.c
** File description:
** rpg
*/

#include "../../include/rpg.h"

void free_invalid_field(rpg_t *rpg_tab)
{
    free(rpg_tab->g->log_wind->password->ctrl);
    rpg_tab->g->log_wind->password->ctrl = my_memset_char(13);
    free(rpg_tab->g->log_wind->nocrypt_password);
    rpg_tab->g->log_wind->nocrypt_password = my_memset_char(13);
}

void valid_field(rpg_t *rpg_tab)
{
    if (my_strlen(rpg_tab->g->log_wind->name->ctrl) > 0
        && rpg_tab->g->link_start_state == LOG_NAME) {
        rpg_tab->g->link_start_state = LOG_PSWD;
    }
    if (my_strlen(rpg_tab->g->log_wind->password->ctrl) > 0
        && rpg_tab->g->link_start_state == LOG_PSWD
        && (rpg_tab->g->play != LOAD_EXISTENT_GAME
        || my_strcmp(rpg_tab->g->log_wind->nocrypt_password,
        rpg_tab->m->l_butt->parsing[0]) == 0)) {
        valid_field_nd(rpg_tab);
        valid_field_three(rpg_tab);
    }
    if (my_strlen(rpg_tab->g->log_wind->password->ctrl) > 0
        && rpg_tab->g->link_start_state == LOG_PSWD
        && (rpg_tab->g->play != LOAD_EXISTENT_GAME
        || my_strcmp(rpg_tab->g->log_wind->nocrypt_password,
        rpg_tab->m->l_butt->parsing[0]) != 0)) {
        free_invalid_field(rpg_tab);
    }
}

void delete_charact(rpg_t *rpg_tab)
{
    if  (rpg_tab->g->link_start_state == LOG_NAME) {
        rpg_tab->g->log_wind->name->ctrl[
        my_strlen(rpg_tab->g->log_wind->name->ctrl) - 1] = '\0';
    } else {
        rpg_tab->g->log_wind->password->ctrl[
        my_strlen(rpg_tab->g->log_wind->password->ctrl) - 1] = '\0';
        rpg_tab->g->log_wind->nocrypt_password[
        my_strlen(rpg_tab->g->log_wind->nocrypt_password) - 1] = '\0';
    }
}

void provide_field(rpg_t *rpg_tab)
{
    if (rpg_tab->event.text.unicode == 58)
        return;
    if (rpg_tab->g->link_start_state == LOG_NAME) {
        if (my_strlen(rpg_tab->g->log_wind->name->ctrl) < 12) {
            rpg_tab->g->log_wind->name->ctrl[
            my_strlen(rpg_tab->g->log_wind->name->ctrl)]
            = rpg_tab->event.text.unicode;
        }
    } else {
        if (my_strlen(rpg_tab->g->log_wind->password->ctrl) < 12) {
            rpg_tab->g->log_wind->password->ctrl[
            my_strlen(rpg_tab->g->log_wind->password->ctrl)]
            = '*';
            rpg_tab->g->log_wind->nocrypt_password[
            my_strlen(rpg_tab->g->log_wind->nocrypt_password)]
            = rpg_tab->event.text.unicode;
        }
    }
}

void input_log(rpg_t *rpg_tab)
{
    if (rpg_tab->event.text.unicode == 13) {
        valid_field(rpg_tab);
        return;
    }
    if (rpg_tab->event.text.unicode == 8) {
        delete_charact(rpg_tab);
        return;
    }
    if (rpg_tab->event.text.unicode < 128) {
        provide_field(rpg_tab);
    }
}