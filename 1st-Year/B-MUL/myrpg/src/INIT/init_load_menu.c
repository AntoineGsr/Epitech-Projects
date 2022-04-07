/*
** EPITECH PROJECT, 2021
** init_load_menu.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

void init_sprite_load(rpg_t *rpg_tab)
{
    rpg_tab->m->l_butt->l_wind = get_my_sprite(rpg_tab, L_WIN,
    (sfVector2f) {642, 110}, (sfIntRect) {0, 0, 635, 860});
    rpg_tab->m->l_butt->button[0] =  get_my_sprite(rpg_tab, L_CHARGE,
    (sfVector2f) {rpg_tab->m->l_butt->l_wind->sprite_pos.x + 105, rpg_tab->m->
    l_butt->l_wind->sprite_pos.y + 764}, (sfIntRect) {0, 0, 202, 61});
    rpg_tab->m->l_butt->button[1] =  get_my_sprite(rpg_tab, L_BACK,
    (sfVector2f) {rpg_tab->m->l_butt->l_wind->sprite_pos.x + 330, rpg_tab->m->
    l_butt->l_wind->sprite_pos.y + 764}, (sfIntRect) {0, 0, 202, 61});
    rpg_tab->m->l_butt->button[2] =  get_my_sprite(rpg_tab, L_PREV,
    (sfVector2f) {rpg_tab->m->l_butt->l_wind->sprite_pos.x + 284, rpg_tab->m->
    l_butt->l_wind->sprite_pos.y + 714}, (sfIntRect) {0, 0, 32, 42});
    rpg_tab->m->l_butt->button[3] =  get_my_sprite(rpg_tab, L_NEXT,
    (sfVector2f) {rpg_tab->m->l_butt->l_wind->sprite_pos.x + 322, rpg_tab->m->
    l_butt->l_wind->sprite_pos.y + 714}, (sfIntRect) {0, 0, 32, 42});
}

void init_rect_load_butt(rpg_t *rpg_tab)
{
    for (int i = 0; i < 4; i++) {
        rpg_tab->m->l_butt->button[i]->sprite_frect = (sfFloatRect) {
        rpg_tab->m->l_butt->button[i]->sprite_pos.x,
        rpg_tab->m->l_butt->button[i]->sprite_pos.y,
        rpg_tab->m->l_butt->button[i]->sprite_rect.width,
        rpg_tab->m->l_butt->button[i]->sprite_rect.height};
    }
    rpg_tab->m->l_butt->list->first = NULL;
    rpg_tab->m->l_butt->list->nb_node = 0;
    rpg_tab->m->l_butt->save_move = 0;
    rpg_tab->m->l_butt->save_click = -1;
}

void init_save_name_txt(rpg_t *rpg_tab, struct dirent *dir)
{
    rpg_tab->m->l_butt->node->save_name =
    get_my_text(dir->d_name, (sfVector2f){
    rpg_tab->m->l_butt->node->button->sprite_pos.x +
    rpg_tab->m->l_butt->node->button->sprite_rect.width / 2,
    rpg_tab->m->l_butt->node->button->sprite_pos.y + 8}, sfWhite, 25);
}

int init_txt_keys_box(rpg_t *rpg_tab, struct dirent *dir, int i)
{
    if (my_strcmp(dir->d_name, ".") == 0
    || my_strcmp(dir->d_name, "..") == 0) {
        i -= 1;
        return (i);
    }
    rpg_tab->m->l_butt->node = add_node_firstpos(&rpg_tab->m->
    l_butt->list, &rpg_tab->m->l_butt->node);
    rpg_tab->m->l_butt->node->button = get_my_sprite(rpg_tab,
    L_SAVE, (sfVector2f) {rpg_tab->m->l_butt->l_wind->
    sprite_pos.x + 181, rpg_tab->m->l_butt->l_wind->sprite_pos.y
    + 226 + 104 * (i % 5)}, (sfIntRect) {0, 0, 273, 48});
    rpg_tab->m->l_butt->node->button->sprite_frect = (sfFloatRect) {
    rpg_tab->m->l_butt->node->button->sprite_pos.x,
    rpg_tab->m->l_butt->node->button->sprite_pos.y,
    rpg_tab->m->l_butt->node->button->sprite_rect.width,
    rpg_tab->m->l_butt->node->button->sprite_rect.height};
    init_save_name_txt(rpg_tab, dir);
    return (i);
}

void init_load_buttons(rpg_t *rpg_tab)
{
    DIR *d;
    struct dirent *dir;

    rpg_tab->m->l_butt->button_state = LOAD_BASE;
    init_sprite_load(rpg_tab);
    init_rect_load_butt(rpg_tab);
    d = opendir("./save");
    if (d) {
        for (int i = 0; (dir = readdir(d)) != NULL; i++) {
            i = init_txt_keys_box(rpg_tab, dir, i);
        }
        closedir(d);
    }
    rpg_tab->m->l_butt->save_max = 0;
}