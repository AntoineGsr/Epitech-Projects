/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_skin_buttons_two(rpg_t *rpg_tab)
{
    rpg_tab->m->s_butt->color_button = 0;
    rpg_tab->m->s_butt->button_state = SKIN_BASE;
    rpg_tab->m->s_butt->s_wind[0] = get_my_sprite(rpg_tab, S_WIN,
    (sfVector2f) {1275, 125}, (sfIntRect) {0, 0, 565, 925});
    rpg_tab->m->s_butt->s_wind[1] = get_my_sprite(rpg_tab, EX_S_WIN,
    (sfVector2f) {20, 30}, (sfIntRect) {0, 0, 565, 925});
    rpg_tab->m->s_butt->skin_rotate = get_my_sprite(rpg_tab, BLUE_SKIN_MENU,
    (sfVector2f) {rpg_tab->m->s_butt->s_wind[1]->sprite_pos.x + 164, rpg_tab->
    m->s_butt->s_wind[1]->sprite_pos.y + 104}, (sfIntRect) {0, 0, 200, 200});
    rpg_tab->m->s_butt->button[0] = get_my_sprite(rpg_tab, BUTTON_SKIN_BLUE,
    (sfVector2f){rpg_tab->m->s_butt->s_wind[0]->sprite_pos.x + 100, rpg_tab->m->
    s_butt->s_wind[0]->sprite_pos.y + 300}, (sfIntRect){216, 0, 72, 78});
    rpg_tab->m->s_butt->button[1] =  get_my_sprite(rpg_tab, BUTTON_SKIN_YELLOW,
    (sfVector2f){rpg_tab->m->s_butt->s_wind[0]->sprite_pos.x + 240, rpg_tab->m->
    s_butt->s_wind[0]->sprite_pos.y + 300}, (sfIntRect){0, 0, 72, 78});
    rpg_tab->m->s_butt->button[2] =  get_my_sprite(rpg_tab, BUTTON_SKIN_RED,
    (sfVector2f){rpg_tab->m->s_butt->s_wind[0]->sprite_pos.x + 380, rpg_tab->m->
    s_butt->s_wind[0]->sprite_pos.y + 300}, (sfIntRect){0, 0, 72, 78});
}

void init_skin_buttons_three(rpg_t *rpg_tab)
{
    rpg_tab->m->s_butt->button[3] =  get_my_sprite(rpg_tab, TRANS,
    (sfVector2f) {rpg_tab->m->s_butt->s_wind[0]->sprite_pos.x + 77, rpg_tab->
    m->s_butt->s_wind[0]->sprite_pos.y + 422}, (sfIntRect) {0, 0, 126, 113});
    rpg_tab->m->s_butt->button[4] =  get_my_sprite(rpg_tab, GAY,
    (sfVector2f) {rpg_tab->m->s_butt->s_wind[0]->sprite_pos.x + 303, rpg_tab->
    m->s_butt->s_wind[0]->sprite_pos.y + 431}, (sfIntRect) {0, 0, 161, 129});
    rpg_tab->m->s_butt->button[5] =  get_my_sprite(rpg_tab, NON_BIN,
    (sfVector2f) {rpg_tab->m->s_butt->s_wind[0]->sprite_pos.x + 168, rpg_tab->
    m->s_butt->s_wind[0]->sprite_pos.y + 570}, (sfIntRect) {450, 0, 150, 140});
    rpg_tab->m->s_butt->button[6] =  get_my_sprite(rpg_tab, BS_BACK,
    (sfVector2f) {rpg_tab->m->s_butt->s_wind[0]->sprite_pos.x + 181, rpg_tab->
    m->s_butt->s_wind[0]->sprite_pos.y + 738}, (sfIntRect) {0, 0, 124, 60});
}

void init_skin_buttons(rpg_t *rpg_tab)
{
    init_skin_buttons_two(rpg_tab);
    init_skin_buttons_three(rpg_tab);
    for (int i = 0; i < 7; i++) {
        rpg_tab->m->s_butt->button[i]->sprite_frect = (sfFloatRect) {
        rpg_tab->m->s_butt->button[i]->sprite_pos.x,
        rpg_tab->m->s_butt->button[i]->sprite_pos.y,
        rpg_tab->m->s_butt->button[i]->sprite_rect.width,
        rpg_tab->m->s_butt->button[i]->sprite_rect.height};
    }
    rpg_tab->m->s_butt->skin_rotate->anim_clock = sfClock_create();
}

void init_help(rpg_t *rpg_tab)
{
    rpg_tab->h->help_sprite[0] = get_my_sprite(rpg_tab, HELP_DISPLAY,
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    rpg_tab->h->help_sprite[1] = get_my_sprite(rpg_tab, HELP_TWO_DISPLAY,
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
    rpg_tab->h->animate_txt = get_my_text("Press ENTER to skip",
    (sfVector2f){900, 1020}, sfWhite, 35);
    rpg_tab->h->page = 0;
}

void init_menu(rpg_t *rpg_tab)
{
    rpg_tab->mouse_left_click = 0;
    rpg_tab->load_game = 0;
    rpg_tab->step = MENU;
    rpg_tab->m->menu_gif = get_my_sprite(rpg_tab, M_GIF,
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1280, 720});
    sfSprite_setScale(rpg_tab->m->menu_gif->sprite, (sfVector2f) {1.5, 1.5});
    init_menu_buttons(rpg_tab);
    init_param_buttons(rpg_tab);
    init_load_buttons(rpg_tab);
    init_skin_buttons(rpg_tab);
    init_help(rpg_tab);
    rpg_tab->m->menu_music = get_my_music("assets/music/menu_music.ogg", 1,
    rpg_tab->m->p_butt->button[1]->sprite_rect.width);
    sfMusic_play(rpg_tab->m->menu_music);
}