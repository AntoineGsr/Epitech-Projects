/*
** EPITECH PROJECT, 2020
** get result
** File description:
** result get
*/

int my_getnbr(char const *str)
{
    int sign = 1;
    int result = 0;
    int i = 0;

    while (str[i] != '\0' && (str[i] == '+' || str[i] == '-' )) {
            sign = -sign;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = (result * 10);
        result = result + (str[i] - '0');
        i++;
    }
    return (sign * result);
}