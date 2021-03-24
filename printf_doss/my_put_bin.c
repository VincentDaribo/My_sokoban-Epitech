/*
** EPITECH PROJECT, 2020
** my_put_bin
** File description:
** Made by Vincent Daribo
*/

void my_putchar(char c);

int my_put_bin(unsigned int nb)
{
    unsigned int modulo = 0;

    if (nb < 2)
        my_putchar(48 + nb);
    if (nb >= 2) {
        modulo = nb % 2;
        nb = (nb - modulo) / 2;
        my_put_bin(nb);
        my_putchar(48 + modulo);
    }
}

