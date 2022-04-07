/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** isneg
*/

void my_putchar(char c);

void my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
}
