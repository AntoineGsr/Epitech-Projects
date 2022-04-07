/*
** EPITECH PROJECT, 2021
** mouse_move_first_menu.c
** File description:
** my_defender
*/

#include "../include/my_defender.h"

void mouse_move_hitbox_start(sfEvent event, enum pages *state)
{
    if (event.mouseMove.x >= 269 && event.mouseMove.x <= 299) {
        if (event.mouseMove.y >= 478 && event.mouseMove.y <= 528)
            *state = START;
    }
    if (event.mouseMove.x >= 290 && event.mouseMove.x <= 426) {
        if (event.mouseMove.y >= 475 && event.mouseMove.y <= 514)
            *state = START;
    }
    if (event.mouseMove.x >= 294 && event.mouseMove.x <= 417) {
        if (event.mouseMove.y >= 439 && event.mouseMove.y <= 479)
            *state = START;
    }
    if (event.mouseMove.x >= 414 && event.mouseMove.x <= 452) {
        if (event.mouseMove.y >= 475 && event.mouseMove.y <= 551)
            *state = START;
    }
}

void mouse_move_hitbox_more(sfEvent event, enum pages *state)
{
    if (event.mouseMove.x >= 276 && event.mouseMove.x <= 410) {
        if (event.mouseMove.y >= 546 && event.mouseMove.y <= 617)
            *state = MORE;
    }
    if (event.mouseMove.x >= 321 && event.mouseMove.x <= 418) {
        if (event.mouseMove.y >= 614 && event.mouseMove.y <= 633)
            *state = MORE;
    }
    if (event.mouseMove.x >= 292 && event.mouseMove.x <= 389) {
        if (event.mouseMove.y >= 533 && event.mouseMove.y <= 558)
            *state = MORE;
    }
    if (event.mouseMove.x >= 397 && event.mouseMove.x <= 413) {
        if (event.mouseMove.y >= 552 && event.mouseMove.y <= 640)
            *state = MORE;
    }
    if (event.mouseMove.x >= 404 && event.mouseMove.x <= 426) {
        if (event.mouseMove.y >= 567 && event.mouseMove.y <= 638)
            *state = MORE;
    }
}

void mouse_move_hitbox_raven(sfEvent event, enum pages *state)
{
    if (event.mouseMove.x >= 375 && event.mouseMove.x <= 450) {
        if (event.mouseMove.y >= 341 && event.mouseMove.y <= 380)
            *state = RAVEN;
    }
    if (event.mouseMove.x >= 442 && event.mouseMove.x <= 512) {
        if (event.mouseMove.y >= 351 && event.mouseMove.y <= 465)
            *state = RAVEN;
    }
}

void mouse_move_hitbox_useless_buttons(sfEvent event, enum pages *state)
{
    if (event.mouseMove.x >= 9 && event.mouseMove.x <= 248) {
        if (event.mouseMove.y >= 506 && event.mouseMove.y <= 564)
            *state = SAVE;
    }
    if (event.mouseMove.x >= 32 && event.mouseMove.x <= 242) {
        if (event.mouseMove.y >= 709 && event.mouseMove.y <= 750)
            *state = ACHIEVEMENT;
    }
    if (event.mouseMove.x >= 60 && event.mouseMove.x <= 213) {
        if (event.mouseMove.y >= 671 && event.mouseMove.y <= 710)
            *state = ACHIEVEMENT;
    }
}

void mouse_move_menu(sfEvent event, enum pages *state)
{
    *state = MENU;
    mouse_move_hitbox_start(event, state);
    mouse_move_hitbox_more(event, state);
    mouse_move_hitbox_raven(event, state);
    mouse_move_hitbox_useless_buttons(event, state);
}