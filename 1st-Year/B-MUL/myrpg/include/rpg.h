/*
** EPITECH PROJECT, 2020
** perso.h
** File description:
** perso.h
*/

#ifndef H_check
#define H_check

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <time.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <math.h>
#include <SFML/Audio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <grp.h>
#include <time.h>
#include <signal.h>
#include <string.h>
#include <pwd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <ncurses.h>
#include <dirent.h>
#include "my.h"

#define BLUE_SKIN "assets/png/util/character_blue.png"
#define YELLOW_SKIN "assets/png/util/character_yellow.png"
#define RED_SKIN "assets/png/util/character_red.png"
#define ENEMY_SKIN "assets/png/util/enemy.png"
#define ST_MSG "WAKE UP SOLDIER ! \
WAKE UP !"
#define ND_MSG "Yes you ! WAKE UP !"
#define RD_MSG "Can you hear me ?! "
#define FR_MSG "It's Captain Americus ! I took you out of your sleep because \
we need you."
#define FV_MSG "Alien ships are attacking us and they have sent virus that \
has made our crewmates completely mad."
#define SX_MSG "You're gonna have to get us out of here."
#define SV_MSG "Start by finding my access card, it will be used to access \
the center of the ship."
#define EG_MSG "Memorize the code that is written on it as well !"
#define NI_MSG "Make sure you reach the cockpit ! Once there, trigger the \
light transfer to escape the aliens !"
#define MEHDIK_ST "I'm Mehdik the doctor ! I need a doctor !"
#define MEHDIK_ND "Can you bring me water please ?! You can find it the room \
on top of the spaceship"
#define MEHDIK_RD "Thanks... Save us, go to the cockpit but be careful"
#define MEHDIK_FR "Don't stand on the red floor"
#define L_SAVE "assets/png/menu_load/save_button.png"
#define L_NEXT "assets/png/menu_load/next_button.png"
#define L_PREV "assets/png/menu_load/previous_button.png"
#define L_BACK "assets/png/menu_load/load_back.png"
#define L_CHARGE "assets/png/menu_load/load_charge.png"
#define L_WIN "assets/png/menu_load/load_window.png"
#define BS_BACK "assets/png/menu_param/button_param_back.png"
#define EX_S_WIN "assets/png/menu_skin/skin_window_extended.png"
#define S_WIN "assets/png/menu_skin/skin_window.png"
#define M_GIF "assets/png/menu/menu_anim.png"
#define BP_DIRECTION "assets/png/menu_param/directions.png"
#define BP_MAP "assets/png/menu_param/map.png"
#define BP_SWITCH "assets/png/menu_param/switch_weapon.png"
#define BP_INTERACT "assets/png/menu_param/interaction.png"
#define BP_INV "assets/png/menu_param/inventory.png"
#define BP_GM "assets/png/menu_param/game_menu.png"
#define B_HUNDRED "assets/png/menu_param/120fps_button.png"
#define B_SIXTY "assets/png/menu_param/60fps_button.png"
#define B_THIRTY "assets/png/menu_param/30fps_button.png"
#define BP_BACK "assets/png/menu_param/button_param_back.png"
#define P_WIN "assets/png/menu_param/param_window.png"
#define EX_P_WIN "assets/png/menu_param/param_window_extended.png"
#define DIR_WIN "assets/png/menu_param/directions_wind.png"
#define S_BAR "assets/png/menu_param/sound_bar.png"
#define M_BAR "assets/png/menu_param/music_bar.png"
#define EX_M_WIN "assets/png/menu/menu_window_extend.png"
#define M_WIN "assets/png/menu/menu_window.png"
#define B_PLAY "assets/png/menu/menu_button_play1.png"
#define B_LOAD "assets/png/menu/menu_button_load1.png"
#define B_QUIT "assets/png/menu/menu_button_quit1.png"
#define B_PARAM "assets/png/menu/menu_button_param1.png"
#define B_HELP "assets/png/menu/menu_button_help1.png"
#define BLUE_SKIN_MENU "assets/png/menu_skin/blue_rotate.png"
#define YELLOW_SKIN_MENU "assets/png/menu_skin/yellow_rotate.png"
#define RED_SKIN_MENU "assets/png/menu_skin/red_rotate.png"
#define BUTTON_SKIN_BLUE "assets/png/menu_skin/blue_skin.png"
#define BUTTON_SKIN_YELLOW "assets/png/menu_skin/yellow_skin.png"
#define BUTTON_SKIN_RED "assets/png/menu_skin/red_skin.png"
#define TRANS "assets/png/menu_skin/transgender.png"
#define GAY "assets/png/menu_skin/gay.png"
#define NON_BIN "assets/png/menu_skin/non_binary.png"
#define GUN "assets/png/game/bullet_charger.png"
#define HEALTH "assets/png/game/health_kit.png"
#define ICON "assets/png/game/gun_bag_icon.png"
#define ACCESS_CARD "assets/png/game/access_card.png"
#define SMALL_ACCESS_CARD "assets/png/game/small_access_card.png"
#define CARD_SCANNER "assets/png/game/card_scanner.png"
#define DIGIT "assets/png/game/digit_numbers.png"
#define PANNEL "assets/png/game/display_code.png"
#define SMALL_BIDON "assets/png/quete/small_bidon.png"
#define BIDON "assets/png/quete/bidon_quest.png"
#define HELP_DISPLAY "assets/png/menu_help/help.png"
#define HELP_TWO_DISPLAY "assets/png/menu_help/help_characters.png"
#define PAUSE_MENU "assets/png/game/menu_pause.png"
#define NEW_GAME 10
#define LOAD_EXISTENT_GAME 11
#define EAST_LEFT 80
#define EAST_TOP 47
#define NORTH_LEFT 72
#define NORTH_TOP 10
#define SOUTH_LEFT 17
#define SOUTH_TOP 80
#define WEST_LEFT 10
#define WEST_TOP 47
#define WALL_DANTE -1
#define WAY -4
#define RIGHT -10
#define WRONG -11

typedef struct sprite_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f sprite_pos;
    sfIntRect sprite_rect;
    sfFloatRect sprite_frect;
    sfClock *anim_clock;
    sfTime anim_time;
} sprite_t;

typedef struct text_s
{
    sfText *text;
    sfFont *font;
    sfVector2f text_pos;
    char *ctrl;
    float x_dec;
} text_t;

typedef struct sound_s
{
    sfSoundBuffer *sound_buffer;
    sfSound *sound;
} sound_t;

typedef struct tile_s
{
    sprite_t *tile;
    int x_tile;
    int y_tile;
    enum {VOID, UNDER, UPPER, WALL, DOOR, OTHER} tile_type;
    int id;
} tile_t;

typedef struct all_tiles_s
{
    tile_t ***under_tiles;
    tile_t ***wall_tiles;
    tile_t ***upper_tiles;
    char *under_tiles_char;
    char *wall_tiles_char;
    char *upper_tiles_char;
    char ***under_tiles_char_tab;
    char ***wall_tiles_char_tab;
    char ***upper_tiles_char_tab;
    int map_width;
    int map_height;
    sfTexture *tile_texture;
    int enum_save;
} all_tiles_t;

typedef struct log_wind_s
{
    sprite_t *wind;
    text_t *name;
    text_t *password;
    char *nocrypt_password;
} log_wind_t;

typedef struct game_variables_s
{
    char *skin;
    int quest;
    int xp;
    int previous_xp;
    int hp;
    int previous_hp;
    int bandage;
    int previous_gun_charger;
    int gun_charger;
    int katana_dmg;
    int gun_dmg;
    char *helmet;
    char *body;
    char *pant;
    int weapon;
    int nb_mob;
    int space_bag;
    int previous_space_bag;
    int access_card;
    int water_bidon;
    int cut_dmg;
} game_variables_t;

typedef struct hitbox_tile_s
{
    sfFloatRect hitbox;
    sfFloatRect hitbox_saved;
    int x_tile;
    int y_tile;
    int id;
} hitbox_tile_t;

typedef struct shooting_area_s
{
    sfFloatRect *north;
    sfFloatRect *east;
    sfFloatRect *south;
    sfFloatRect *west;
    float orientation_left;
    float orientation_top;
} shooting_area_t;

typedef struct perso_s
{
    sprite_t *guy;
    sfVector2f guy_center;
    float previous_clock;
    int hit;
    int speed;
    int weapon;
    int shooting;
    int target;
    shooting_area_t *shoot_area;
    sfVector2f slide_effect;
    sfFloatRect guy_hitbox;
    sfClock *weapon_clock;
    sfClock *floor_damage_clock;
} perso_t;

typedef struct enemy_s
{
    sprite_t *blop;
    int speed;
    int mv_right;
    int mv_left;
    int mv_up;
    int mv_down;
    float previous_clock;
    float clock_move;
    int hit;
    int nb_pressed;
    int area;
    int hp;
    int detected;
    sfClock *bomb;
    sfFloatRect explosion;
    sfFloatRect blop_hitbox;
} enemy_t;

typedef struct spawn_area_s
{
    sfVector2f area_pos_top;
    sfVector2f area_pos_bottom;
} spawn_area_t;

typedef struct case_s
{
    int inventory;
    sprite_t *inv_case;
    sfFloatRect hitbox_item;
} case_t;

typedef struct stat_s
{
    sprite_t *xp_bar;
    sprite_t *xp_color;
    text_t *xp_txt;
    sprite_t *hp_bar;
    sprite_t *hp_color;
    text_t *hp_txt;
} stat_t;

typedef struct inventory_s
{
    int inventory;
    sprite_t *skin;
    stat_t *stats;
    case_t **case_inv;
    sprite_t *inv_wind;
} inventory_t;

typedef struct player_info_s
{
    sprite_t *bag_icon;
    text_t *bag_space;
    sprite_t *gun_icon;
    text_t *bullet_charger;
} player_info_t;

typedef struct access_card_s
{
    sfFloatRect click_hitbox_big_card;
    sprite_t *big_card;
    sprite_t *scanner;
    sprite_t **digit_number;
    sprite_t *display_digit;
    text_t *code_door_two;
    int access_card_mission;
    int door_one;
    int door_two;
} access_card_t;

typedef struct water_bidon_s
{
    sprite_t **bidon_layer;
    sprite_t *button;
    sfFloatRect quest_reach;
    float seconds;
} water_bidon_t;

typedef struct node_t node_t;
struct node_t
{
    char *type_drop;
    sprite_t *button;
    text_t *save_name;
    sfVector2f speed_bullet;
    sfFloatRect hitbox_bullet;
    node_t *next;
    node_t *previous;
};

typedef struct list_s
{
    int nb_node;
    float previous_clock;
    node_t *first;
} list_t;

typedef struct game_s
{
    sprite_t *link_start_sprite;
    sprite_t *space_sprite;
    sprite_t *red_arrow;
    all_tiles_t *all_tiles;
    log_wind_t *log_wind;
    game_variables_t *var;
    perso_t *perso;
    hitbox_tile_t **hitbox_tile;
    enemy_t **enemy;
    spawn_area_t **spawn_area;
    spawn_area_t **spawn_area_large;
    spawn_area_t **spawn_area_solo;
    spawn_area_t **spawn_area_end;
    sfMusic *game_music;
    list_t *gunshot_list;
    node_t *gunshot_node;
    list_t *drop_list;
    node_t *drop_node;
    sfFloatRect zoom_reach;
    int play;
    int entity_count;
    char *pseudo;
    char *password_input;
    int nb_mob;
    int can_open_door;
    int open_door;
    int can_grab_water;
    int water_grab;
    int water_done;
    int can_grab;
    int grab_drop;
    int left_click;
    int right_click;
    int reloading;
    int nb_bullet;
    text_t *door_msg;
    text_t *drop_msg;
    text_t *reload_msg;
    stat_t *stats;
    inventory_t *inventory;
    player_info_t *player_info;
    access_card_t *card;
    water_bidon_t *bidon;
    sfClock *clock_msg;
    text_t **start_msg;
    sprite_t *captain;
    sprite_t *mehdik;
    sfFloatRect mehdik_quest;
    int talk_mehdik;
    int can_talk_mehdik;
    int mehdik_quest_done;
    int talking_mehdik;
    int load;
    int can_end_game;
    int click_end_game;
    int tp_end;
    sfClock *clock_medhik;
    float seconds_medhik;
    text_t **mehdik_txt;
    sfFloatRect *end_hitbox;
    int skip;
    text_t **statistics;
    sprite_t *pause_game;
    enum {LINK_NOT_DONE, LOG_NAME, LOG_PSWD, LOG_DONE} link_start_state;
} game_t;

typedef struct menu_button_s
{
    sprite_t **button;
    enum {MENU_BASE, MENU_PLAY, MENU_LOAD, MENU_END, MENU_PARAM, MENU_HELP, MENU_SKIN, CB_PLAY, CB_LOAD, CB_END, CB_PARAM, CB_HELP, CB_SKIN} button_state;
} menu_button_t;

typedef struct menu_button_param_s
{
    sprite_t **button;
    sprite_t **p_wind;
    text_t **key;
    int *offset;
    enum {PARAM_BASE, PARAM_SOUND, PARAM_MUSIC, PARAM_30FPS, PARAM_60FPS, PARAM_120FPS, PARAM_BACK, P_GM, P_INVENT, P_INTER, P_SWITCH, P_MAP, P_UP, P_DOWN, P_RIGHT, P_LEFT, CB_PARAM_SOUND, CB_PARAM_MUSIC, CB_PARAM_30FPS, CB_PARAM_60FPS, CB_PARAM_120FPS, CB_PARAM_BACK, CB_GM, CB_INVENT, CB_INTER, CB_SWITCH, CB_MAP, CB_UP, CB_DOWN, CB_RIGHT, CB_LEFT} button_state;
} menu_button_param_t;

typedef struct menu_button_load_s
{
    sprite_t **button;
    sprite_t *l_wind;
    list_t *list;
    node_t *node;
    int save_max;
    int save_move;
    int save_click;
    char **parsing;
    enum {LOAD_BASE, LOAD_CHARGE, LOAD_BACK, LOAD_PREV, LOAD_NEXT, LOAD_SAVE, CB_LOAD_CHARGE, CB_LOAD_BACK, CB_PREV, CB_NEXT, CB_SAVE} button_state;
} menu_button_load_t;

typedef struct menu_button_skin_s
{
    sprite_t **button;
    sprite_t **s_wind;
    sprite_t *skin_rotate;
    int color_button;
    enum {SKIN_BASE, SKIN_BLUE, SKIN_YELLOW, SKIN_RED, SKIN_TRANS, SKIN_GAY, SKIN_BIN, SKIN_BACK, CB_BLUE, CB_YELLOW, CB_RED, CB_TRANS, CB_GAY, CB_BIN, CB_SKIN_BACK} button_state;
} menu_button_skin_t;

typedef struct menu_paral_s
{
    sfSprite *sprite_at_index;
    sfVector2f sprite_pos;
} menu_paral_t;

typedef struct util_s
{
    sfClock *clock_coeff;
    sfVector2f c_pos;
    sfFloatRect c_box;
    sfVector2f c_pos_previous;
    sfFloatRect c_box_previous;
    sound_t *link_start;
    sound_t *click_sound;
    sprite_t *transi_black;
    sprite_t *cursor;
    enum {TRANSI_NO, TRANSI_YES} transi_state;
    float transi_x;
} util_t;

typedef struct menu_s
{
    sprite_t **m_wind;
    menu_button_t *m_butt;
    menu_button_param_t *p_butt;
    menu_button_load_t *l_butt;
    menu_button_skin_t *s_butt;
    menu_paral_t **paral_tab;
    sprite_t *menu_gif;
    sfMusic *menu_music;
} menu_t;

typedef struct keys_s
{
    int mv_right;
    int mv_left;
    int mv_up;
    int mv_down;
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode right;
    sfKeyCode left;
    sfKeyCode game_menu;
    sfKeyCode inventory;
    sfKeyCode interaction;
    sfKeyCode switch_weapon;
    sfKeyCode reload;
    int nb_pressed;
} keys_t;

typedef struct particle_obj_s
{
    sfFloatRect box;
    sfColor color;
    enum {PARTICLE_ON, PARTICLE_OFF} particle_state;
} particle_obj_t;

typedef struct one_particle_s
{
    particle_obj_t *obj;
    struct one_particle_s *previous;
    struct one_particle_s *next;
} one_particle_t;

typedef struct particles_s
{
    one_particle_t *m_particule;
    sfClock *m_refresh_clock;
    one_particle_t *g_particule;
    sfClock *g_refresh_clock;
} particles_t;

typedef struct help_s
{
    sprite_t **help_sprite;
    text_t *animate_txt;
    int page;
} help_t;

typedef struct config_s
{
    unsigned int win_x;
    unsigned int win_y;
    unsigned int bit_per_pixel;
    unsigned int fps;
    int full_screen;
    int sound_vol;
    int music_vol;
    char **parse_config;
} config_t;

typedef struct end_game_s
{
    sprite_t *end_anim;
} end_game_t;

typedef struct icon_s
{
    int index;
    sfImage **icon;
    sfClock *icon_clock;
} icon_t;

typedef struct rpg_s
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    sfEvent event;
    sfView *view;
    sfView *min_map_view;
    menu_t *m;
    util_t *u;
    game_t *g;
    help_t *h;
    icon_t *icons;
    end_game_t *eg;
    keys_t *keys;
    particles_t *particles;
    sfVector2f main_cam_pos;
    sfClock *gbl_clock;
    config_t *config;
    double coeff;
    sfVector2u window_size;
    int int_coeff;
    int mouse_left_click;
    int load_game;
    sfVector2f mouse_pos;
    char **maze_dante;
    enum {INTRO, MENU,  GAME, LOAD, END, END_GAME, PARAM, HELP, SKIN, GAME_PARAM} step;
} rpg_t;

char *my_memset_char(int size);

void init_base(rpg_t *rpg_tab);

void malloc_struct(rpg_t *rpg_tab);

void init_menu(rpg_t *rpg_tab);

sprite_t *get_my_sprite(rpg_t *rpg_tab, char *path,
sfVector2f sprite_pos, sfIntRect sprite_rect);

void game_loop(rpg_t *rpg_tab);

void init_utils(rpg_t *rpg_tab);

void init_keys(rpg_t *rpg_tab);

void handle_coeff(rpg_t *rpg_tab);

void handle_cursor(rpg_t *rpg_tab);

void background_defil(rpg_t *rpg_tab);

void game_loop(rpg_t *rpg_tab);

void handle_menu(rpg_t *rpg_tab);

void menu_buttons_click(rpg_t *rpg_tab);

void menu_move(rpg_t *rpg_tab);

void menu_buttons_released(rpg_t *rpg_tab);

sfMusic *get_my_music(char *path, int boolean_loop, int volume);

text_t *get_my_text(char *str, sfVector2f pos, sfColor color, int size);

void show_hitbox(rpg_t *rpg_tab, sfFloatRect rect);

void menu_param(rpg_t *rpg_tab);
void param_move_verif_click(rpg_t *rpg_tab, int i);
void param_move(rpg_t *rpg_tab);
void param_buttons_click(rpg_t *rpg_tab);
void param_buttons_released(rpg_t *rpg_tab);

void menu_load(rpg_t *rpg_tab);
void load_move(rpg_t *rpg_tab);
void load_buttons_click(rpg_t *rpg_tab);
void load_buttons_released(rpg_t *rpg_tab);

void game(rpg_t *rpg_tab);
void init_game(rpg_t *rpg_tab);
void decal_rect_generic(sfIntRect *rect, sfVector2f dec, sfVector2f max);
void link_start_handling(rpg_t *rpg_tab);
sound_t *get_new_sound(char *path, int volume);
void start_transition(rpg_t *rpg_tab);
void handle_transition(rpg_t *rpg_tab);
void destroy_all(rpg_t *rpg_tab);

void menu_skin(rpg_t *rpg_tab);
void skin_move_verif_click(rpg_t *rpg_tab, int i);
void skin_move(rpg_t *rpg_tab);
void skin_buttons_click(rpg_t *rpg_tab);
void skin_buttons_released(rpg_t *rpg_tab);
void parse_save(rpg_t *rpg_tab);

node_t *add_node_firstpos(list_t **list, node_t **node);
char **save_to_word_array(char *av, char sep);
void clean_log_text(rpg_t *rpg_tab);
void input_log(rpg_t *rpg_tab);
int create_new_save(rpg_t *rpg_tab);

void create_tile(rpg_t *rpg_tab);

int count_sep(char *str, char sep);

char ***map_to_tab(char *str);

void create_tile_from_map(rpg_t *rpg_tab, sfVector2i tab_pos, char ***tab_char,
tile_t ****tiles);

int format_ypos(rpg_t *rpg_tab, sfVector2i tab_pos, char ***tab_char);

void display_tiles(rpg_t *rpg_tab);

void game_display(rpg_t *rpg_tab);

void view_stat_handling(rpg_t *rpg_tab);

sfVector2f sfview_my_getpos(rpg_t *rpg_tab, sfView *view);

void key_move_event(rpg_t *rpg_tab);

void gen_hitbox_tile(rpg_t *rpg_tab);

float previous_time(sfTime time);
float speed_coeff(float seconds, int speed);
void move_guy(rpg_t *rpg_tab, int coeff, int top, int x_y);
void animate_guy(rpg_t *rpg_tab);
void display_tile_hitboxes(rpg_t *rpg_tab);
void game_stat_refresh(rpg_t *rpg_tab);
void check_guy_hit_wall(rpg_t *rpg_tab, sfVector2f previous_pos);
void check_guy_hit_mob(rpg_t *rpg_tab, sfVector2f previous_pos);
void check_guy_drop(rpg_t *rpg_tab);
void gestion_entity(rpg_t *rpg_tab);
void move_guy(rpg_t *rpg_tab, int coeff, int top, int x_y);
void get_seed(void);
void game_stat_refresh_mob(rpg_t *rpg_tab);
void animate_mob_blop(rpg_t *rpg_tab, int i);
sfVector2f spawn_blop(rpg_t *rpg_tab, int i, spawn_area_t **spawn_area,
int mod);
void move_bullet(rpg_t *rpg_tab);
void game_stat_refresh_bullet(rpg_t *rpg_tab);
void destroy_node_noloop(list_t **list, node_t **node, int *pos);
void display_min_map(rpg_t *rpg_tab);

void gestion_door(rpg_t *rpg_tab);

void animate_generic(sfIntRect *rect, int dec, int max, int base_mv);

void animate_door_open(sfIntRect *rect, sfVector3f param, rpg_t *rpg_tab);

void animate_door_close(sfIntRect *rect, sfVector3f param, rpg_t *rpg_tab);

void change_door_hitbox(rpg_t *rpg_tab, tile_t *tile);

void init_min_map(rpg_t *rpg_tab);

float coeff_window(float window_size, float nb, float div);
int add_inventory(rpg_t *rpg_tab);
sfVector2f pos_case_inventory(rpg_t *rpg_tab, int box, int width, int height);
void game_stat_refresh_inventory(rpg_t *rpg_tab);
void gestion_hitbox_inventary(rpg_t *rpg_tab);
void drop_item_mob_kill(rpg_t *rpg_tab, int i);
void game_stat_refresh_door(rpg_t *rpg_tab);
void gestion_door_quest(rpg_t *rpg_tab);
void game_stat_refresh_water(rpg_t *rpg_tab);
void menu_help(rpg_t *rpg_tab);
void init_config(rpg_t *rpg_tab);
int create_new_config(rpg_t *rpg_tab);
void gestion_end_game(rpg_t *rpg_tab);

void game_param(rpg_t *rpg_tab);

void animate_text(rpg_t *rpg_tab, text_t *text, int refresh_rate, int *col);

void init_quest(rpg_t *rpg_tab);

void gestion_water_quest(rpg_t *rpg_tab);

void gestion_damage_floor(rpg_t *rpg_tab);

void create_maze(rpg_t *rpg_tab);

sprite_t *get_my_tile(rpg_t *rpg_tab, sfTexture *texture,
sfVector2f sprite_pos, sfIntRect sprite_rect);

void differ_tile(rpg_t *rpg_tab, tile_t **tmp, int xpos, int ypos);

void zoom_maze_handling(rpg_t *rpg_tab);

void init_end_game(rpg_t *rpg_tab);

void end_menu(rpg_t *rpg_tab);

void init_particle(rpg_t *rpg_tab);

void particle_handling_m(rpg_t *rpg_tab);

void init_icon(rpg_t *rpg_tab);

void icon_handling(rpg_t *rpg_tab);

void particle_handling_g(rpg_t *rpg_tab);

typedef struct cellule cellule;
struct cellule
{
    int type;
    int value;
};

typedef struct generator generator;
struct generator
{
    int av1;
    int av2;
    int ac;
    int count;
    int zero_link;
    int prev_val;
    int perfect_first;
    int *cell;
    char *maze;
    int verif_pos;
    int verif_neg;
    int last;
    int print_last;
};

generator *create_struct(int ac, char **av);
void destroy_struct(generator *gen);
int error_input(int ac, char **av);
char **create_map(int x, int y, generator *gen);
void first_line(int j, generator *gen);
void horizontal_links(int j, generator *gen);
void vertical_links(int i, int j, generator *gen);
void last_line(int j, generator *gen);
int mob_rd_move(rpg_t *rpg_tab, float seconds_move, int restart_clock,
int i);
sfVector2f mob_speed(rpg_t *rpg_tab, int speed, int i,
sfVector2f movement_mob);
sfVector2f mob_speed_nd(rpg_t *rpg_tab, int speed, int i,
sfVector2f movement_mob);
void mob_hit(rpg_t *rpg_tab, int i, sfVector2f previous_pos);
void mob_verif_action(rpg_t *rpg_tab, int i, sfVector2f movement_mob);
int mob_gestion_call(rpg_t *rpg_tab, int i, int restart_clock);
void gestion_guy(rpg_t *rpg_tab);
void gestion_bullet(rpg_t *rpg_tab);
int weapon_two_wall(rpg_t *rpg_tab, int j, int *destroyed);
int weapon_two_mob(rpg_t *rpg_tab, int j);
void reaload_gun(rpg_t *rpg_tab);
void gestion_event_game(rpg_t *rpg_tab);
void kill_mob_del(rpg_t *rpg_tab, int i);
void swh_foor(rpg_t *rpg_tab);
void swh_five(rpg_t *rpg_tab);
void swh_six(rpg_t *rpg_tab);
void swh_two(rpg_t *rpg_tab);
void swh_three(rpg_t *rpg_tab);
void events_log(rpg_t *rpg_tab);
void valid_field_nd(rpg_t *rpg_tab);
void valid_field_three(rpg_t *rpg_tab);
void gestion_click_inv_two(rpg_t *rpg_tab, int i);
void gestion_click_inv(rpg_t *rpg_tab, int i);
void gestion_click_inv_three(rpg_t *rpg_tab, int i);
void gestion_click_inv_foor(rpg_t *rpg_tab, int i);
void quest_door_one(rpg_t *rpg_tab);
void game_stat_refresh_shoot_area(rpg_t *rpg_tab);
void game_five(rpg_t *rpg_tab, float seconds);
void game_one(rpg_t *rpg_tab);
void game_two(rpg_t *rpg_tab);
void game_three(rpg_t *rpg_tab, float seconds);
void game_foor(rpg_t *rpg_tab, float seconds);
void gm_six(rpg_t *rpg_tab);
void gm_sv(rpg_t *rpg_tab);
void gm_eg(rpg_t *rpg_tab);
void gm_nince(rpg_t *rpg_tab);
void gm_ten(rpg_t *rpg_tab);
void gd_three(rpg_t *rpg_tab);
void decal_rect_bg(sfIntRect *rect, int dec, int max);
void gm_el(rpg_t *rpg_tab);
void gd_one(rpg_t *rpg_tab);
void gd_two(rpg_t *rpg_tab);
void gm_twelve(rpg_t *rpg_tab);
void gd_five(rpg_t *rpg_tab);
void gd_six(rpg_t *rpg_tab);
void gd_sv(rpg_t *rpg_tab);
void gd_eight(rpg_t *rpg_tab);
void gd_nine(rpg_t *rpg_tab);
void gd_eleven(rpg_t *rpg_tab);
void gd_twelve(rpg_t *rpg_tab, float seconds);
void gd_thirt(rpg_t *rpg_tab, float seconds);
void gd_fort(rpg_t *rpg_tab, float seconds);
void background_defil_param(rpg_t *rpg_tab);
void update_skin_button_color(rpg_t *rpg_tab);
void call_back_buttons(rpg_t *rpg_tab);
void display_param_buttons(rpg_t *rpg_tab);
void check_controls_txt(rpg_t *rpg_tab);
void check_controls_mod(rpg_t *rpg_tab);
char *create_arr_save(rpg_t *rpg_tab);
char *create_arr_save_five(rpg_t *rpg_tab, char *buff);
char *create_arr_save_six(rpg_t *rpg_tab, char *buff);
void update_var_game(rpg_t *rpg_tab);
void update_var_game_six(rpg_t *rpg_tab);
void update_var_game_seven(rpg_t *rpg_tab, int i, int z);
void update_var_game_eight(rpg_t *rpg_tab, int i);
void update_var_game_nine(rpg_t *rpg_tab, int i, int z);
void update_var_game_ten(rpg_t *rpg_tab, int i, int z);
void update_var_game_eleven(rpg_t *rpg_tab);
void update_var_game_twelve(rpg_t *rpg_tab);
void update_var_game_zero(rpg_t *rpg_tab, sfVector2f pos_item);
void update_var_game_two(rpg_t *rpg_tab);
void update_var_game_three(rpg_t *rpg_tab);
void update_var_game_four(rpg_t *rpg_tab, int i, sfVector2f *pos_item);
void update_var_game_five(rpg_t *rpg_tab, int i, sfVector2f *pos_item);
void smooth_effect(rpg_t *rpg_tab);
void animate_explose(rpg_t *rpg_tab, int i, float seconds);
void animate_mob_blop(rpg_t *rpg_tab, int i);
void decal_rect_guy(sfIntRect *rect, int dec, int max, int reset);
void animate_guy_six(rpg_t *rpg_tab, sfIntRect knife);
void animate_guy_seven(rpg_t *rpg_tab, sfIntRect knife);
void animate_guy_eight(rpg_t *rpg_tab, float seconds_weapon);
void animate_guy_nine(rpg_t *rpg_tab, sfIntRect *bullet);
void animate_guy_ten(rpg_t *rpg_tab);
void animate_guy_eleven(rpg_t *rpg_tab, float seconds_weapon);
void animate_guy_twelve(rpg_t *rpg_tab, float seconds_weapon);
void animate_guy_thirteen(rpg_t *rpg_tab, float seconds);
int animate_guy_two(rpg_t *rpg_tab, int i);
int animate_guy_three(rpg_t *rpg_tab, int i);
void animate_guy_four(rpg_t *rpg_tab);
void animate_guy_five(rpg_t *rpg_tab);
void init_game_six(rpg_t *rpg_tab);
void init_game_eight(rpg_t *rpg_tab);
void init_game_ten(rpg_t *rpg_tab);
void init_game_twelve(rpg_t *rpg_tab);
void init_game_thirteen(rpg_t *rpg_tab);
void init_game_fourteen(rpg_t *rpg_tab);
void init_game_fifteen(rpg_t *rpg_tab);
void init_game_sixteen(rpg_t *rpg_tab);
void init_game_seventeen(rpg_t *rpg_tab);
void check_controls_mod_two_ex(rpg_t *rpg_tab, int i);
void check_controls_txt_three(rpg_t *rpg_tab, int i);
void check_controls_txt_two_ex(rpg_t *rpg_tab, int i);
void load_move_ex(rpg_t *rpg_tab, int i);
char *create_arr_config(rpg_t *rpg_tab);
sfVector2f spawn_blop(rpg_t *rpg_tab, int i, spawn_area_t **spawn_area,
int mod);
void create_spawn_area_end(rpg_t *rpg_tab);
void create_spawn_area_solo(rpg_t *rpg_tab);
void create_spawn_area_large(rpg_t *rpg_tab);
void create_spawn_area(rpg_t *rpg_tab);
void init_log_wind(rpg_t *rpg_tab);
void init_game_variables(rpg_t *rpg_tab);
void init_enemy_one(rpg_t *rpg_tab);
void init_enemy_two(rpg_t *rpg_tab);
void init_enemy_three(rpg_t *rpg_tab);
void init_enemy_foor(rpg_t *rpg_tab);
void init_shoot_area(rpg_t *rpg_tab);
void init_bar(rpg_t *rpg_tab);
void init_inventory(rpg_t *rpg_tab);
void init_txt(rpg_t *rpg_tab);
void init_item(rpg_t *rpg_tab);
void init_door_quest(rpg_t *rpg_tab);
void init_start_txt(rpg_t *rpg_tab);
void init_menu_buttons(rpg_t *rpg_tab);
void init_sprite_param(rpg_t *rpg_tab);
void init_sprite_param_two(rpg_t *rpg_tab);
void init_txt_keys(rpg_t *rpg_tab);
void init_load_buttons(rpg_t *rpg_tab);
void verif_multiple_input(rpg_t *rpg_tab);
void init_param_buttons(rpg_t *rpg_tab);

#endif