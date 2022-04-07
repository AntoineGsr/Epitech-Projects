/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** mysh
*/

#include <stddef.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <ncurses.h>

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLDBLACK "\033[1m\033[30m"
#define BOLDRED "\033[1m\033[31m"
#define BOLDGREEN "\033[1m\033[32m"
#define BOLDYELLOW "\033[1m\033[33m"
#define BOLDBLUE "\033[1m\033[34m"
#define BOLDMAGENTA "\033[1m\033[35m"
#define BOLDCYAN "\033[1m\033[36m"
#define BOLDWHITE "\033[1m\033[37m"

enum Keys
{
    UP,
    DOWN,
    ENTER,
    QUIT,
};

void my_putchar(char);
int my_strlen(char *);
void my_putstr(char *);
int is_same_str(char *, char *);
int my_getnbr(char const *);
char *my_strdup(char const *);
void my_puterr(char *);
char *my_strcat(char *, char *);
char *file_reader(char const *);
char *my_memset_char(int size);
char **my_memset_dchar(int size1, int size2);
int *my_memset_int(int size);

////////////////////////////////////////////////////////////

int error_handling(int, char **, char **);

////////////////////////////////////////////////////////////

typedef struct Cell
{
    char *data;
    struct Cell *next;
} list_t, cell_t;

int is_empty_list(list_t *);
long length_list(list_t *);
list_t *add_at(list_t *, char *, int);
char *get_at(list_t *, int);
void set_at(list_t *, char *, int);
list_t *free_at(list_t *, int);
list_t *free_list(list_t *);
void print_list(list_t *);

////////////////////////////////////////////////////////////

typedef struct history_node_s
{
    char *command;
    int index;
    struct history_node_s *previous;
    struct history_node_s *next;
} history_node_t;

typedef struct history_s
{
    history_node_t *history_ll;
    history_node_t *history_ll_first_ptr;
    history_node_t *history_ll_last_ptr;
    int total_command_nbr;
} history_t;

typedef struct alias_node_s
{
    char *arg_one;
    char *arg_two;
    struct alias_node_s *previous;
    struct alias_node_s *next;
} alias_node_t;

typedef struct alias_s
{
    alias_node_t *alias_ll;
    alias_node_t *alias_ll_first_ptr;
    alias_node_t *alias_ll_last_ptr;
    int total_alias_nbr;
    int alias_loop;
    int alias_error;
} alias_t;

typedef struct local_var_s
{
    char *var_name;
    char *content;
    struct local_var_s *next;
} local_var_t;

typedef struct storage
{
    char **env;
    char *oldpwd;
    char *line;
    int stored_nbr;
    int status;
    int exit;
    int execve_return;
    int ignoreeof;
    int prompt_change;
    char *prompt_color;
    char *prompt_text;
    history_t *history;
    alias_t *alias;
    local_var_t *local_var;
    list_t *jobs;
    list_t *commands;
} storage_t;

typedef struct ForLoops
{
    int i;
    int j;
} forl_t;

////////////////////////////////////////////////////////////

void my_sh(storage_t *);
void check_to_start(char *, storage_t *);
int is_line_valid(char *);
int are_quotations_valid(char *, storage_t *);
int are_parentheses_valid(char *, storage_t *);
int check_parentheses_position(char *, storage_t *);
int parenthese_error(char *, storage_t *, char *);
void define_commands(char *, storage_t *);
void execute_command(char *, storage_t *);
int is_command_a_job(char *);
void check_job(char *, storage_t *);
void store_command(storage_t *, char *, int);
void simple_command(char *, storage_t *);
void pipe_command(char *, storage_t *);
void redirection_command(char *, storage_t *);
void check_separator(char *, storage_t *, char);
void execute_subshell(char *, storage_t *);
char *define_subshell_command(char *);
int subshell_main(char **, char *);
void separate_command(char *, storage_t *, char);
void make_redirection(char *, storage_t *);
void simple_right_redirect(char *, storage_t *);
void double_right_redirect(char *, storage_t *);
void simple_left_redirect(char *, storage_t *);
char *find_file_to_redirect(char **);
char *delete_first_redirect(char *);
char *delete_file_path(char *, char *);
char *add_cat_and_pipe(char *, char *);
void double_left_redirect(char *, storage_t *);
char *define_file_name(char *, char);
char *redefine_command(char *, char *, char);
int is_pipe_correct(char *, storage_t *);
void make_pipe(char *, storage_t *);
void exec_pipe(char *, char *, storage_t *);
void display_prompt(storage_t *);
void change_text_prompt(char **, storage_t *);
void find_builtins(char **, storage_t *);
void make_cd(char **, storage_t *);
void make_command(char *, char **, storage_t *);
void make_fg(storage_t *);
void history_mode(storage_t *);
void make_repeat(char **, storage_t *);
void make_setenv(storage_t *, char **);
void make_unsetenv(storage_t *, char **);
int make_env(char **, char **);
int make_exit(char *, char **, storage_t *);
void make_exe(char *, char **, storage_t *);
int is_exe_file(char *file);
int is_command_found(char **path, int i, char *command);
int is_bin_command(char *command, char **env);
void unknown_command(char *command, storage_t *storage);

////////////////////////////DEMS////////////////////////////

void make_history(storage_t *storage, char **inputs);
history_node_t *save_command_into_history(storage_t *storage,
char *line, history_node_t *to_put);
void init_all(storage_t *storage);
void free_all(storage_t *storage);
void make_alias(char **inputs, storage_t *storage);
char **aplly_alias(storage_t *storage, char **inputs);
int check_error_arch(char **inputs, storage_t *storage);

////////////////////////////////////////////////////////////

char **alloc_env(char **, char **);
int is_variable_in_env(char **, char *);
void free_dbtab(char **);
int check_try_execute(char *);
int set_str_nbr(char **);
char **set_dirs(char **);
int count_paths_nbr(char *);
char *add_path(char *, char **);
char **define_inputs(char *);
char *segfault_char_star(void);
int change_quotation_status(int);
void def_new_env(storage_t *, char *, char *);

////////////////////////////////////////////////////////////

void make_set(char **inputs, storage_t *storage);
void make_set_no_arg(storage_t *storage);
char *handle_variable(char *line, storage_t *storage);
char *find_var_content(char **inputs);
char *is_variable_exist(char *var_name, storage_t *storage);
char *make_new_line(char *line, char *var_content);
void add_local_var(char *var_content, char *var_name, storage_t *storage);
char *get_line_my_sh(storage_t *storage);