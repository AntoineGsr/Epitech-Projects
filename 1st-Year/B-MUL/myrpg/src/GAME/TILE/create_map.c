/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../../include/my.h"

char *get_map(rpg_t *rpg_tab, char *path)
{
    int fd;
    int read_len = 0;
    struct stat stats;
    char *to_return;
    fd = open(path, O_RDONLY);
    if (fd <= -1) return (NULL);
    if (stat(path, &stats) != 0) return (NULL);
    if (S_ISDIR(stats.st_mode)) return (NULL);
    to_return = malloc(sizeof(char) *
    (stats.st_size + 10));
    if (to_return == NULL) return (NULL);
    read_len = read(fd, to_return, stats.st_size);
    if (read_len < 0) return (NULL);
    if (read_len == 0) return (NULL);
    close(fd);
    to_return[stats.st_size] = '\0';
    return (to_return);
}

void malloc_and_create_tile(rpg_t *rpg_tab, tile_t ****tiles, char ***tab_char)
{
    *tiles = malloc(sizeof(tile_t **) *
    (rpg_tab->g->all_tiles->map_height + 1));
    (*tiles)[rpg_tab->g->all_tiles->map_height] = NULL;
    for (int i = 0; i < rpg_tab->g->all_tiles->map_height; i++) {
        (*tiles)[i] = malloc(sizeof(tile_t *) *
        (rpg_tab->g->all_tiles->map_width + 1));
        (*tiles)[i][rpg_tab->g->all_tiles->map_width] = NULL;
        for (int j = 0; j < rpg_tab->g->all_tiles->map_width; j++) {
            create_tile_from_map(rpg_tab, (sfVector2i) {i, j}, tab_char,
            tiles);
        }
    }
}

void get_tile_map_info(rpg_t *rpg_tab, char *str)
{
    rpg_tab->g->all_tiles->map_width = 0;
    rpg_tab->g->all_tiles->map_height = 0;
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] == ';')
            rpg_tab->g->all_tiles->map_width++;
    } rpg_tab->g->all_tiles->map_width++;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            rpg_tab->g->all_tiles->map_height++;
    }
}

void create_tile_two(rpg_t *rpg_tab)
{
    rpg_tab->g->all_tiles->under_tiles_char =
    get_map(rpg_tab, "assets/tile_map/my_rpg_under_map.csv");
    rpg_tab->g->all_tiles->upper_tiles_char =
    get_map(rpg_tab, "assets/tile_map/my_rpg_upper_map.csv");
    rpg_tab->g->all_tiles->wall_tiles_char =
    get_map(rpg_tab, "assets/tile_map/my_rpg_wall_map.csv");
    rpg_tab->g->all_tiles->under_tiles_char_tab =
    map_to_tab(rpg_tab->g->all_tiles->under_tiles_char);
    rpg_tab->g->all_tiles->upper_tiles_char_tab =
    map_to_tab(rpg_tab->g->all_tiles->upper_tiles_char);
    rpg_tab->g->all_tiles->wall_tiles_char_tab =
    map_to_tab(rpg_tab->g->all_tiles->wall_tiles_char);
}

void create_tile(rpg_t *rpg_tab)
{
    create_tile_two(rpg_tab);
    get_tile_map_info(rpg_tab, rpg_tab->g->all_tiles->under_tiles_char);
    malloc_and_create_tile(rpg_tab, &rpg_tab->g->all_tiles->under_tiles,
    rpg_tab->g->all_tiles->under_tiles_char_tab);
    rpg_tab->g->all_tiles->enum_save = 2;
    malloc_and_create_tile(rpg_tab, &rpg_tab->g->all_tiles->upper_tiles,
    rpg_tab->g->all_tiles->upper_tiles_char_tab);
    rpg_tab->g->all_tiles->enum_save = 3;
    malloc_and_create_tile(rpg_tab, &rpg_tab->g->all_tiles->wall_tiles,
    rpg_tab->g->all_tiles->wall_tiles_char_tab);
    create_maze(rpg_tab);
    gen_hitbox_tile(rpg_tab);
}