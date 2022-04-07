/*
** EPITECH PROJECT, 2021
** parse_save.c
** File description:
** my_rpg
*/

#include "../../include/rpg.h"

int create_new_save(rpg_t *rpg_tab)
{
    int opn = 0;
    int write_fl = 0;
    int rv = 0;
    char *buff = create_arr_save(rpg_tab);
    char *path = my_memset_char(100);

    path = my_strcpy(path, "./save/");
    path = my_strcat(path, rpg_tab->g->log_wind->name->ctrl);
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

static char *open_savefile(rpg_t *rpg_tab)
{
    int opn = 0;
    char *buff = my_memset_char(2000);
    char *path_load = my_memset_char(26);

    path_load = my_strcpy(path_load, "./save/");
    path_load = my_strcat(path_load, rpg_tab->g->pseudo);
    opn = open(path_load, O_RDONLY);
    if (opn == -1)
        return NULL;
    read(opn, buff, 1999);
    close(opn);
    return (buff);
}

void parse_save(rpg_t *rpg_tab)
{
    char *buff = NULL;

    free(rpg_tab->g->pseudo);
    rpg_tab->g->pseudo = my_memset_char(my_strlen(
    rpg_tab->m->l_butt->node->save_name->ctrl) + 1);
    rpg_tab->g->pseudo = my_strcpy(rpg_tab->g->pseudo,
    rpg_tab->m->l_butt->node->save_name->ctrl);
    rpg_tab->m->l_butt->node = rpg_tab->m->l_butt->list->first;
    buff = open_savefile(rpg_tab);
    if (buff == NULL)
        return;
    rpg_tab->m->l_butt->parsing = save_to_word_array(buff, ':');
    free(rpg_tab->g->log_wind->name->ctrl);
    rpg_tab->g->log_wind->name->ctrl = my_memset_char(
    my_strlen(rpg_tab->g->pseudo) + 1);
    rpg_tab->g->log_wind->name->ctrl = my_strcpy(rpg_tab->g->log_wind->name->
    ctrl, rpg_tab->g->pseudo);
    update_var_game(rpg_tab);
    rpg_tab->g->load = true;
}