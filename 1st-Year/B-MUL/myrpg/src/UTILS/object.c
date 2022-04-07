/*
** EPITECH PROJECT, 2021
** usage
** File description:
** my_rpg
*/

#include "../../include/my.h"

text_t *get_my_text(char *str, sfVector2f pos, sfColor color, int size)
{
    text_t *txt = malloc(sizeof(text_t));

    txt->ctrl = my_memset_char(my_strlen(str) + 1);
    txt->ctrl = my_strcpy(txt->ctrl, str);
    txt->font = sfFont_createFromFile
    ("./assets/font/arial.ttf");
    txt->text = sfText_create();
    sfText_setFont(txt->text, txt->font);
    sfText_setColor(txt->text, color);
    sfText_setCharacterSize(txt->text, size);
    txt->text_pos = pos;
    txt->text_pos.x -= my_strlen(str) * 6;
    sfText_setPosition(txt->text, txt->text_pos);
    sfText_setString(txt->text, txt->ctrl);
    txt->x_dec = 0;
    return (txt);
}

sound_t *get_new_sound(char *path, int volume)
{
    sound_t *tmp = malloc(sizeof(sound_t));
    tmp->sound = sfSound_create();
    tmp->sound_buffer = sfSoundBuffer_createFromFile(path);
    sfSound_setBuffer(tmp->sound, tmp->sound_buffer);
    sfSound_setVolume(tmp->sound, volume);
    return (tmp);
}

sfMusic *get_my_music(char *path, int boolean_loop, int volume)
{
    sfMusic *obj;
    obj = sfMusic_createFromFile(path);
    if (boolean_loop == 1)
        sfMusic_setLoop(obj, sfTrue);
    sfMusic_setVolume(obj, volume);
    return (obj);
}

sprite_t *get_my_sprite(rpg_t *rpg_tab, char *path,
sfVector2f sprite_pos, sfIntRect sprite_rect)
{
    sprite_t *obj = malloc(sizeof(sprite_t));
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    obj->sprite_pos = sprite_pos;
    sfSprite_setPosition(obj->sprite, obj->sprite_pos);
    obj->sprite_rect = sprite_rect;
    sfSprite_setTextureRect(obj->sprite, obj->sprite_rect);
    obj->anim_clock = sfClock_create();
    return (obj);
}