/*
** EPITECH PROJECT, 2021
** text_gestion.c
** File description:
** my_runner
*/

#include "my_runner.h"

char *my_memset_char(int size)
{
    char *str = malloc(sizeof(char) * size);

    str[0] = '\0';
    return (str);
}

char *complete_buff_valgrind(int size)
{
    char *str = malloc(sizeof(char) * size);

    str[0] = '\0';
    for (int i = 0; i < size; i++)
        str[i] = 'z';
    str[size - 1] = '\0';
    return (str);
}

void set_text_high(sfFont **font_hs, sfText **text_hs, sfVector2f pos_txt_hs,
char *path)
{
    *font_hs = sfFont_createFromFile("./text/Ozye.ttf");
    *text_hs = sfText_create();
    sfText_setFont(*text_hs, *font_hs);
    sfText_setColor(*text_hs, (sfColor){0, 0, 0, 100});
    sfText_setCharacterSize(*text_hs, 28);
    sfText_setPosition(*text_hs, pos_txt_hs);
    sfText_setString(*text_hs, path);
}

void update_high_score(sfFont **font, sfText **text,
sfVector2f pos, game_object **sprite)
{
    char *buff = complete_buff_valgrind(11);
    char *high_score = my_memset_char(25);
    int opn = open("high_score.txt", O_RDONLY);
    int i = 0;

    high_score = my_strcat(high_score, "HIGH SCORE: ");
    if (opn != -1) {
        read(opn, buff, 10);
        for (i = 0; buff[i] != 'z'; i++);
        buff[i] = '\0';
        if (my_getnbr(buff) < sprite[16]->case_map) {
            opn = open("high_score.txt", O_WRONLY | O_TRUNC);
            write(opn, my_getstr(sprite[16]->case_map),
            my_strlen(my_getstr(sprite[16]->case_map)));
        }
        set_text_high(font, text, pos, my_strcat(high_score, buff));
    }
    close(opn);
    free(high_score);
    free(buff);
}

void update_score(sfFont **font, sfText **text, sfVector2f pos_txt,
char *str)
{
    *font = sfFont_createFromFile("./text/Ozyi.ttf");
    *text = sfText_create();
    sfText_setFont(*text, *font);
    sfText_setCharacterSize(*text, 50);
    sfText_setPosition(*text, pos_txt);
    sfText_setString(*text, str);
}