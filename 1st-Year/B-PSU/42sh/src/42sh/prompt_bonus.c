/*
** EPITECH PROJECT, 2021
** prompt_bonus.c
** File description:
** 42sh
*/

#include "include/my.h"

static void display_msg_prompt(char **inputs, storage_t *storage,
int count_args)
{
    if (count_args == 1 || count_args > 3) {
        fprintf(stderr, "Help: prompt -h to see the usage\n");
        storage->status = 1;
    }
    if (count_args == 2) {
        if (is_same_str(inputs[1], "-h")) {
            my_putstr("prompt [COLOR] [TEXT]\nprompt reset\n\nCOLOR:\n");
            my_putstr("  -BLACK\tRED\tGREEN\n  -YELLOW\tBLUE\t");
            my_putstr("MAGENTA\t\n  -CYAN\t\tWHITE\tBOLD[COLOR]\n");
        } else if (is_same_str(inputs[1], "reset")) {
            storage->prompt_change = 0;
            free(storage->prompt_color);
            free(storage->prompt_text);
            storage->prompt_color = NULL;
            storage->prompt_text = NULL;
        } else
            storage->status = 1;
    }
}

static char *verif_macro_bold_color(char *input)
{
    if (is_same_str(input, "BOLDBLACK"))
        return (BOLDBLACK);
    if (is_same_str(input, "BOLDRED"))
        return (BOLDRED);
    if (is_same_str(input, "BOLDGREEN"))
        return (BOLDGREEN);
    if (is_same_str(input, "BOLDYELLOW"))
        return (BOLDYELLOW);
    if (is_same_str(input, "BOLDBLUE"))
        return (BOLDBLUE);
    if (is_same_str(input, "BOLDMAGENTA"))
        return (BOLDMAGENTA);
    if (is_same_str(input, "BOLDCYAN"))
        return (BOLDCYAN);
    if (is_same_str(input, "BOLDWHITE"))
        return (BOLDWHITE);
    return "\0";
}

static char *verif_macro_classic_color(char *input)
{
    if (is_same_str(input, "BLACK"))
        return (BLACK);
    if (is_same_str(input, "RED"))
        return (RED);
    if (is_same_str(input, "GREEN"))
        return (GREEN);
    if (is_same_str(input, "YELLOW"))
        return (YELLOW);
    if (is_same_str(input, "BLUE"))
        return (BLUE);
    if (is_same_str(input, "MAGENTA"))
        return (MAGENTA);
    if (is_same_str(input, "CYAN"))
        return (CYAN);
    if (is_same_str(input, "WHITE"))
        return (WHITE);
    return "\0";
}

static void check_color(char *input, storage_t *storage)
{
    char *stock_color = my_memset_char(16);

    if (storage->prompt_color != NULL) {
        stock_color = strcpy(stock_color, storage->prompt_color);
        free(storage->prompt_color);
    }
    storage->prompt_color = my_memset_char(16);
    storage->prompt_color = strcpy(storage->prompt_color,
    verif_macro_classic_color(input));
    if (storage->prompt_color[0] == '\0') {
        storage->prompt_color = strcpy(storage->prompt_color,
        verif_macro_bold_color(input));
    }
    if (storage->prompt_color[0] == '\0') {
        fprintf(stderr, "Wrong [COLOR]\n");
        storage->status = 1;
        storage->prompt_color = strcpy(storage->prompt_color, stock_color);
    } else
        storage->prompt_change = 1;
    free(stock_color);
}

void change_text_prompt(char **inputs, storage_t *storage)
{
    int count_args = 0;

    for (int i = 0; inputs[i] != NULL; i++)
        count_args += 1;
    display_msg_prompt(inputs, storage, count_args);
    if (count_args == 3) {
        check_color(inputs[1], storage);
        if (storage->status == 1)
            return;
        if (storage->prompt_text != NULL)
            free(storage->prompt_text);
        storage->prompt_text = malloc(sizeof(char) * my_strlen(inputs[2]) + 2);
        storage->prompt_text[0] = '\0';
        storage->prompt_text = strcpy(storage->prompt_text, inputs[2]);
        storage->prompt_text = my_strcat(storage->prompt_text, " ");
    }
    return;
}