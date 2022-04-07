/*
** EPITECH PROJECT, 2021
** history mode
** File description:
** history of commands
*/

#include "include/my.h"

int analyse_key(void)
{
    int key = getch();

    if (key == KEY_UP)
        return (UP);
    if (key == KEY_DOWN)
        return (DOWN);
    if (key == 'q')
        return (QUIT);
    if (key == 10)
        return (ENTER);
    return (analyse_key());
}

void init_ncurses(void)
{
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
}

int handle_keys(int pos, int key, int len, storage_t *storage)
{
    if (key == UP)
        pos++;
    if (key == DOWN)
        pos--;
    if (pos >= len || pos < 0)
        pos = 0;
    if (pos >= 1) {
        mvprintw(8, 21, get_at(storage->commands, pos));
    }
    if (key == ENTER) {
        refresh();
        curs_set(TRUE);
        endwin();
        if (pos == 0)
            return (-1);
        check_to_start(my_strdup(get_at(storage->commands, pos)), storage);
        return (-1);
    }
    return (pos);
}

void history_mode(storage_t *storage)
{
    int key = -1;
    int len = length_list(storage->commands);
    int pos = 0;

    if (len == 1)
        return (my_putstr("No history\n"));
    init_ncurses();
    do {
        erase();
        mvprintw(0, 0, "////////////////////////////////////////\n"
        "Press arrow up / arrow down to navigate,\n"
        "Enter for execute and Q to quit");
        mvprintw(8, 0, "command to execute: ");
        pos = handle_keys(pos, key, len, storage);
        if (pos == -1)
            return;
        refresh();
    }  while ((key = analyse_key()) != QUIT);
    curs_set(TRUE);
    endwin();
}