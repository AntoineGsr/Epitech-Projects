/*
** EPITECH PROJECT, 2020
** 104intersection.h
** File description:
** minishell
*/

#ifndef MINI_H_
#define MINI_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include "../lib/my/my.h"

typedef struct global_list global_list;
struct global_list
{
    char *input;
    char *input_modif;
    char **input_sort;
    char **sort;
    char **history;
    char **env;
    char *memory_pwd;
    char *oldpwd;
    int ac;
    int pid;
    int child_pid;
    int exit;
    int exit_null;
    int exit_child;
    int old_cd;
    int step;
};

typedef struct l_list l_list;
struct l_list
{
    char *value_env;
    l_list *previous;
    l_list *next;
};

typedef struct list list;
struct list
{
    int total_env;
    int nb_path;
    char **paths;
    char *home;
    char *pwd;
    int pwd_create;
    int home_create;
    int path_create;
    l_list *first;
    l_list *last;
};

global_list *create_father(char **av, char **env);
list *create_env(char **av, char **env);
l_list *add_to_list(list **gbl, l_list **l_a, char *str);
l_list *add_first(list **gbl, l_list **l_a, char *str);
l_list *add_last(list **gbl, l_list **l_a, char *str);
int create_array_env(global_list **father, list **my_env, l_list **node_env);
void create_shell(global_list **father, list **my_env, l_list **node_env,
char **env);
void create_nodes(list **my_env, l_list **node_env, char **env);
void destroy_func(global_list **father);
void ctrl_c_gestion(int i, char **av, char **env);
int fork_gestion(global_list **father, list **my_env, l_list **node_env);
int exec_input_child(global_list **father, list **my_env, l_list **node_env);
int exec_input_father(global_list **father, list **my_env, l_list **node_env);
char *my_memset_char(int size);
void child_gestion(global_list **father, list **my_env, l_list **node_env);
void father_gestion(global_list **father, list **my_env, l_list **node_env);
void handler_sigint(int sig);
void print_prompt(void);
int my_putstr_fast_zero(char const *str);
int compare_cmd_system(global_list **father, list **my_env, l_list **node_env);
int compare_exit(global_list **father, list **my_env, l_list **node_env);
int compare_cd_fth(global_list **father, list **my_env, l_list **node_env);
int compare_setenv_fth(global_list **father, list **my_env, l_list **node_env);
int compare_exit_fth(global_list **father, list **my_env, l_list **node_env);
int compare_env(global_list **father, list **my_env, l_list **node_env);
void register_input(global_list **father, char *str);
char **my_memset_dchar(int size1, int size2);
char *my_memset_char(int size);
int compare_cd_fth_pth(global_list **father, list **my_env, l_list **node_env);
int compare_unsetenv_fth_loop(global_list **father, list **my_env,
l_list **node_env);
void destroy_list(list **gbl, l_list **elem);
l_list *verif_env_exist(list **gbl, l_list **l_a, char *str);
void value_ex_ret(global_list **father, list **my_env, l_list **node_env);
int error_arguments(global_list **father, char *str, int nb);
int verif_ctrl_d(global_list **father, int line_size);
void analyse_exit_child(global_list **father, int state);
int compare_echo_dollar(global_list **father, list **my_env,
l_list **node_env);
void change_pwd_env(list **gbl, l_list **l_a, char *str);
void save_pwd(global_list **father);
void unsetenv_del_node(global_list **father, list **my_env, l_list **node_env);
void unsetenv_fth_last_var(global_list **father, list **my_env,
l_list **node_env);
int compare_unsetenv_oldpwd(global_list **father, list **my_env,
l_list **node_env, char *str);
int compare_cd_arg(global_list **father, list **my_env, l_list **node_env);
void compare_cd_oldpwd(global_list **father, list **my_env, l_list **node_env,
int dir);
void create_value_env(global_list **father, list **my_env, l_list **node_env,
int total_size);
int unvalid_setenv_val(global_list **father, list **my_env, l_list **node_env);
int unvalid_unsetenv_val(global_list **father, list **my_env,
l_list **node_env);
int my_putstr_fast_error(char const *str);
char *display(l_list *l_a);
char **my_str_to_word_array_separator_struct(char *av, char sep, list **my_env);
void verif_env_created(list **my_env, l_list **node_env);
void update_env(list **my_env, l_list **node_env);
int verif_env_major_var(list **my_env, char **env, int i);

#endif /* MINI_H_ */