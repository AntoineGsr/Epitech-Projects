/*
** EPITECH PROJECT, 2021
** init_config.C
** File description:
** my_rpg
*/

#include "../../include/my.h"

int create_new_config(rpg_t *rpg_tab)
{
    int opn = 0;
    int write_fl = 0;
    int rv = 0;
    char *buff = create_arr_config(rpg_tab);
    char *path = my_memset_char(100);

    path = my_strcpy(path, "./config/config.txt");
    rv = remove(path);
    if (rv == -1)
        rv = 0;
    opn = open(path, O_CREAT | O_TRUNC | O_WRONLY, 00664);
    if (opn == -1) return (84);
    write_fl = write(opn, buff, my_strlen(buff));
    if (write_fl == -1) return (84);
    close(opn);
    free(buff);
    free(path);
    return (0);
}

static char *open_config(rpg_t *rpg_tab)
{
    int opn = 0;
    char *buff = my_memset_char(1000);
    char *path_load = my_memset_char(26);

    path_load = my_strcpy(path_load, "./config/config.txt");
    opn = open(path_load, O_RDONLY);
    if (opn == -1)
        return NULL;
    read(opn, buff, 999);
    close(opn);
    return (buff);
}

void default_config(rpg_t *rpg_tab)
{
    rpg_tab->config->win_x = 1920;
    rpg_tab->config->win_y = 1080;
    rpg_tab->config->bit_per_pixel = 32;
    rpg_tab->config->full_screen = false;
    rpg_tab->config->fps = 60;
    rpg_tab->config->music_vol = 185;
    rpg_tab->config->sound_vol = 185;
}

void update_config(rpg_t *rpg_tab)
{
    rpg_tab->config->win_x = my_getnbr(rpg_tab->config->parse_config[0]);
    rpg_tab->config->win_y = my_getnbr(rpg_tab->config->parse_config[1]);
    rpg_tab->config->bit_per_pixel = my_getnbr(rpg_tab->
    config->parse_config[2]);
    rpg_tab->config->full_screen = my_getnbr(rpg_tab->config->parse_config[3]);
    rpg_tab->config->fps = my_getnbr(rpg_tab->config->parse_config[4]);
    rpg_tab->config->music_vol = my_getnbr(rpg_tab->config->parse_config[5]);
    rpg_tab->config->sound_vol = my_getnbr(rpg_tab->config->parse_config[6]);
}

void init_config(rpg_t *rpg_tab)
{
    char *buff = open_config(rpg_tab);

    default_config(rpg_tab);
    if (buff != NULL) {
        rpg_tab->config->parse_config = save_to_word_array(buff, ':');
        update_config(rpg_tab);
    }
    rpg_tab->video_mode = (sfVideoMode) {rpg_tab->config->win_x,
    rpg_tab->config->win_y, rpg_tab->config->bit_per_pixel};
    rpg_tab->window = sfRenderWindow_create(rpg_tab->video_mode,
    "MEUPORG", sfClose | sfResize, NULL);
    rpg_tab->window_size = sfRenderWindow_getSize(rpg_tab->window);
    rpg_tab->view = sfView_create();
    sfView_setSize(rpg_tab->view, (sfVector2f) {1920, 1080});
    sfView_setCenter(rpg_tab->view, (sfVector2f) {960, 540});
    sfRenderWindow_setView(rpg_tab->window, rpg_tab->view);
    sfRenderWindow_setFramerateLimit(rpg_tab->window, rpg_tab->config->fps);
}