/*
** EPITECH PROJECT, 2021
** create_arr_config.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

char *create_arr_config_three(rpg_t *rpg_tab)
{
    char *buff = my_memset_char(50);

    buff = my_strcat(buff, my_getstr(rpg_tab->keys->down));
    buff = my_strcat(buff, "\nleft:");
    buff = my_strcat(buff, my_getstr(rpg_tab->keys->left));
    buff = my_strcat(buff, "\nright:");
    buff = my_strcat(buff, my_getstr(rpg_tab->keys->right));
    buff = my_strcat(buff, "\ngame_menu:");
    return (buff);
}

char *create_arr_config_two(rpg_t *rpg_tab)
{
    char *buff = my_memset_char(50);

    buff = my_strcpy(buff, "window_size_x:");
    buff = my_strcat(buff, my_getstr(rpg_tab->window_size.x));
    buff = my_strcat(buff, "\nwindow_size_y:");
    buff = my_strcat(buff, my_getstr(rpg_tab->window_size.y));
    buff = my_strcat(buff, "\nbit_per_pixel:");
    buff = my_strcat(buff, my_getstr(rpg_tab->window_size.y));
    buff = my_strcat(buff, "\nfull_screen_mod:");
    buff = my_strcat(buff, my_getstr(rpg_tab->config->full_screen));
    buff = my_strcat(buff, "\nfps:");
    buff = my_strcat(buff, my_getstr(rpg_tab->config->fps));
    buff = my_strcat(buff, "\nmusic_vol:");
    buff = my_strcat(buff, my_getstr(rpg_tab->config->music_vol));
    buff = my_strcat(buff, "\nsound_vol:");
    buff = my_strcat(buff, my_getstr(rpg_tab->config->sound_vol));
    buff = my_strcat(buff, "\nup:");
    buff = my_strcat(buff, my_getstr(rpg_tab->keys->up));
    buff = my_strcat(buff, "\ndown:");
    return (buff);
}

char *create_arr_config(rpg_t *rpg_tab)
{
    char *buff = my_memset_char(300);

    if (rpg_tab->window_size.x < 200 || rpg_tab->window_size.y < 200)
        rpg_tab->window_size = (sfVector2u){1920, 1080};
    buff = my_strcpy(buff, create_arr_config_two(rpg_tab));
    buff = my_strcat(buff, create_arr_config_three(rpg_tab));
    buff = my_strcat(buff, my_getstr(rpg_tab->keys->game_menu));
    buff = my_strcat(buff, "\ninventory:");
    buff = my_strcat(buff, my_getstr(rpg_tab->keys->interaction));
    buff = my_strcat(buff, "\ninteraction:");
    buff = my_strcat(buff, my_getstr(rpg_tab->keys->interaction));
    buff = my_strcat(buff, "\nswitch_weapon:");
    buff = my_strcat(buff, my_getstr(rpg_tab->keys->switch_weapon));
    buff = my_strcat(buff, "\nreload:");
    buff = my_strcat(buff, my_getstr(rpg_tab->keys->reload));
    return (buff);
}