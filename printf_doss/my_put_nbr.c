/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** Made by Vincent Daribo
*/

void my_putchar(char c);

int my_put_nbr(int nb)
{
    int modulo = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10)
        my_putchar(48 + nb);
    if (nb >= 10) {
        modulo = nb % 10;
        nb = (nb - modulo) / 10;
        my_put_nbr(nb);
        my_putchar(48 + modulo);
    }
}
