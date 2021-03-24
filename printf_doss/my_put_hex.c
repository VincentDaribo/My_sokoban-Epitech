/*
** EPITECH PROJECT, 2020
** my_put_hex
** File description:
** Made by Vincent Daribo
*/

void my_putchar	(char c);

int letter(unsigned int nb)
{
    if (nb == 10)
        my_putchar('a');
    if (nb == 11)
        my_putchar('b');
    if (nb == 12)
        my_putchar('c');
    if (nb == 13)
        my_putchar('d');
    if (nb == 14)
        my_putchar('e');
    if (nb == 15)
        my_putchar('f');
    else
        return (0);
}

int my_put_hex(unsigned int nb)
{
    unsigned int modulo = 0;

    if (nb < 10)
        my_putchar(nb + 48);
    if (nb >= 10) {
        modulo = nb % 16;
        nb = (nb - modulo) / 16;
        my_put_hex(nb);
        if (modulo >= 10 && modulo <= 15)
            letter(modulo);
        else
            my_putchar(48 + modulo);
    }
}
