/*
** EPITECH PROJECT, 2020
** my_isneg.c
** File description:
** lib
*/

void my_putchar(char c);

int my_isneg(int n)
{
    char c;
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return (0);
}
