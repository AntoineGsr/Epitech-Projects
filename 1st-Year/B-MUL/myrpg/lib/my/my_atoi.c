/*
** EPITECH PROJECT, 2020
** my ato i
** File description:
** bistromatic
*/

int my_atoi(char const *str)
{
    int result = 0;
    int i = 0;
    for (int i = 0 ; str[i] >= '0' && str[i] <= '9'; i++) {
        result = str[i] - '0' + result * 10;
    }
    return result;
}