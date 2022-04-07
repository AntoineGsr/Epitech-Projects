/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

void init_game_two(rpg_t *rpg_tab)
{
    rpg_tab->g->zoom_reach = (sfFloatRect) {7800, 900, 1100, 1100};
    rpg_tab->g->entity_count = 0;
    rpg_tab->g->game_music = get_my_music("assets/music/action.ogg", 1,
    rpg_tab->m->p_butt->button[1]->sprite_rect.width);
    rpg_tab->g->all_tiles->enum_save = 1;
    rpg_tab->g->all_tiles->tile_texture =
    sfTexture_createFromFile("assets/png/game/tile.png", NULL);
    rpg_tab->g->link_start_state = LINK_NOT_DONE;
    rpg_tab->g->perso->guy = get_my_sprite(rpg_tab,
    "assets/png/util/character_blue.png",
    (sfVector2f) {235, 1315}, (sfIntRect) {0, 0, 100, 100});
    rpg_tab->g->perso->guy_hitbox = (sfFloatRect)
    {0, 0, 0, 0};
    rpg_tab->g->link_start_sprite = get_my_sprite(rpg_tab,
    "assets/png/game/link_start-min.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 600, 338});
    rpg_tab->g->space_sprite = get_my_sprite(rpg_tab,
    "assets/png/game/space.png",
    (sfVector2f) {0, 0}, (sfIntRect) {0, 0, 1920, 1080});
}

void init_game_three(rpg_t *rpg_tab)
{
    sfSprite_setScale(rpg_tab->g->link_start_sprite->sprite,
    (sfVector2f){3.2, 3.2});
    create_spawn_area(rpg_tab);
    create_spawn_area_large(rpg_tab);
    create_spawn_area_solo(rpg_tab);
    create_spawn_area_end(rpg_tab);
    rpg_tab->g->play = 0;
    rpg_tab->g->nb_mob = 38;
    rpg_tab->g->pseudo = my_memset_char(26);
    rpg_tab->g->password_input = my_memset_char(26);
    rpg_tab->g->log_wind = malloc(sizeof(log_wind_t));
    init_log_wind(rpg_tab);
    init_game_variables(rpg_tab);
    rpg_tab->g->perso->slide_effect = (sfVector2f) {0, 0};
    rpg_tab->g->perso->hit = 0;
    rpg_tab->g->perso->speed = 300;
    rpg_tab->g->perso->weapon = 0;
    rpg_tab->g->perso->shooting = false;
    rpg_tab->g->perso->target = false;
    rpg_tab->g->perso->weapon_clock = sfClock_create();
}

void init_game_extra_two(rpg_t *rpg_tab)
{
    rpg_tab->g->skip = false;
    rpg_tab->g->can_end_game = false;
    rpg_tab->g->click_end_game = false;
    rpg_tab->g->tp_end = false;
    rpg_tab->g->statistics[0] = get_my_text("8",
    (sfVector2f){1290, 275}, sfWhite, 40);
    rpg_tab->g->statistics[1] = get_my_text("5",
    (sfVector2f){1290, 395}, sfWhite, 40);
    rpg_tab->g->statistics[2] = get_my_text("300",
    (sfVector2f){1290, 520}, sfWhite, 40);
    rpg_tab->g->pause_game = get_my_sprite(rpg_tab, PAUSE_MENU,
    (sfVector2f){0, 0}, (sfIntRect){0, 0, 1920, 1080});
}

void init_game_extra_one(rpg_t *rpg_tab)
{
    rpg_tab->g->mehdik_quest = (sfFloatRect){0, 0, 150, 150};
    rpg_tab->g->talk_mehdik = false;
    rpg_tab->g->can_talk_mehdik = false;
    rpg_tab->g->end_hitbox[0] = (sfFloatRect){15101, 1399, 100, 100};
    rpg_tab->g->end_hitbox[1] = (sfFloatRect){10102, 3518, 100, 100};
    rpg_tab->g->mehdik_quest_done = false;
    rpg_tab->g->talking_mehdik = false;
    rpg_tab->g->seconds_medhik = 0;
    rpg_tab->g->mehdik_txt[0] = get_my_text(MEHDIK_ST,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->mehdik_txt[1] = get_my_text(MEHDIK_ND,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->mehdik_txt[2] = get_my_text(MEHDIK_RD,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->mehdik_txt[3] = get_my_text(MEHDIK_FR,
    (sfVector2f){0, 0}, sfWhite, 40);
    rpg_tab->g->clock_medhik = sfClock_create();
}

void init_game(rpg_t *rpg_tab)
{
    init_game_two(rpg_tab);
    init_game_three(rpg_tab);
    init_enemy_one(rpg_tab);
    init_enemy_two(rpg_tab);
    init_enemy_three(rpg_tab);
    init_enemy_foor(rpg_tab);
    init_shoot_area(rpg_tab);
    init_bar(rpg_tab);
    init_inventory(rpg_tab);
    init_txt(rpg_tab);
    init_item(rpg_tab);
    init_door_quest(rpg_tab);
    init_start_txt(rpg_tab);
    init_game_extra_one(rpg_tab);
    init_game_extra_two(rpg_tab);
    rpg_tab->g->card->scanner->anim_clock = sfClock_create();
    rpg_tab->g->clock_msg = sfClock_create();
}