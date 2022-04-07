/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** affiche_map
*/

#include "navy.h"

void display_ennemi(list *player)
{
    for (int i = 0; i < 8; i++) {
        my_putstr_fast(my_getstr(i + 1));
        my_putchar('|');
        for (int j = 0; j < 8; j++) {
            my_putchar(player->map_ennemi[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}

void display_me(list *player)
{
    for (int i = 0; i < 8; i++) {
        my_putstr_fast(my_getstr(i + 1));
        my_putchar('|');
        for (int j = 0; j < 8; j++) {
            my_putchar(player->map_me[i][j]);
            my_putchar(' ');
        }
        my_putchar('\n');
    }
}

void display_map(list *player)
{
    my_putstr_fast("my positions:\n");
    my_putstr_fast(" |A B C D E F G H\n");
    my_putstr_fast("-+---------------\n");
    display_me(player);
    my_putchar('\n');
    my_putstr_fast("enemy's positions:\n");
    my_putstr_fast(" |A B C D E F G H\n");
    my_putstr_fast("-+---------------\n");
    display_ennemi(player);
    my_putchar('\n');
}