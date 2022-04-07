/*
** EPITECH PROJECT, 2021
** find_builtins
** File description:
** mysh
*/

#include "include/my.h"

void find_builtins_pt2(char **inputs, storage_t *storage)
{
    if (is_same_str(inputs[0], "exit")) {
        storage->status = make_exit(inputs[0], inputs, storage);
        return;
    }
    if (is_same_str(inputs[0], "set"))
        return (make_set(inputs, storage));
    if (is_same_str(inputs[0], "fg"))
        return (make_fg(storage));
    if (is_same_str(inputs[0], "jobs"))
        return (print_list(storage->jobs));
    if (is_same_str(inputs[0], "history"))
        return (history_mode(storage));
    if (is_same_str(inputs[0], "repeat"))
        return (make_repeat(inputs, storage));
    if (is_exe_file(inputs[0]))
        return (make_exe(inputs[0], inputs, storage));
    if (is_bin_command(inputs[0], storage->env))
        return (make_command(inputs[0], inputs, storage));
    unknown_command(inputs[0], storage);
}

void find_builtins(char **inputs, storage_t *storage)
{
    if (inputs[0][0] == '!')
        return (make_history(storage, inputs));
    if (is_same_str(inputs[0], "cd"))
        return (make_cd(inputs, storage));
    if (is_same_str(inputs[0], "alias"))
        return (make_alias(inputs, storage));
    if (is_same_str(inputs[0], "setenv"))
        return (make_setenv(storage, inputs));
    if (is_same_str(inputs[0], "unsetenv"))
        return (make_unsetenv(storage, inputs));
    if (is_same_str(inputs[0], "env")) {
        storage->status = make_env(storage->env, inputs);
        return;
    }
    if (is_same_str(inputs[0], "prompt"))
        return (change_text_prompt(inputs, storage));
    find_builtins_pt2(inputs, storage);
}