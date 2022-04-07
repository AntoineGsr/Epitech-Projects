/*
** EPITECH PROJECT, 2020
** str_capitalize
** File description:
** capitalize first car of word
*/

int check_start(char *str)
{
    int start = 0;

    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] -= 32;
        start = 1;
    }

    return (start);
}

char *my_strcapitalize(char *str)
{
    int in_a_word = 0;
    int start = check_start (str);
    for (int i = start; str[i] != '\0'; i++)
    {
        if (in_a_word == 1 && ((str[i] < 'A' && str[i] > 'Z') ||
        str[i - 1] == ' ' || str[i - 1] == '-' || str[i - 1] == '+'))
            in_a_word = 0;
        if (str[i] > 'A' && str[i] < 'Z' && in_a_word == 1)
            str[i] += 32;
        while ((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
        && (str[i] >= 'A' && str[i] <= 'Z')) {
            str[i] += 32;
            i++;
        } if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' '
        || str[i - 1] == '-' || str[i - 1] == '+') && in_a_word == 0)
            str[i] -= 32;
            in_a_word = 1;
    } return (str);
}