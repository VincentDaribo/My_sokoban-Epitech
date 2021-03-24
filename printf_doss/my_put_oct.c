/*
** EPITECH PROJECT, 2020
** test octale
** File description:
** Made by Vincent DAribo
*/

void my_putchar(char c);

int my_put_oct(unsigned int nb)
{
    unsigned int modulo = 0;

    if (nb < 8)
        my_putchar(48 + nb);
    if (nb >= 8) {
        modulo = nb % 8;
        nb = (nb - modulo) / 8;
        my_put_oct(nb);
        my_putchar(48 + modulo);
    }
}
