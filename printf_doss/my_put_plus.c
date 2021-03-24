/*
** EPITECH PROJECT, 2020
** my_put_plus
** File description:
** Made by Vincent Daribo
*/

#include <stdarg.h>

int my_put_nbr(int nb);

void my_putchar(char c);

int my_put_soct(int nb);

int my_put_plus(int nb)
{
    int modulo = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }else
        my_putchar('+');
    if (nb < 10)
        my_putchar(48 + nb);
    if (nb >= 0) {
        if (nb >= 10) {
            modulo = nb % 10;
            nb = (nb - modulo) / 10;
            my_put_nbr(nb);
            my_putchar(48 + modulo);
        }
    }else
        my_putchar(48 + nb % 10);
}

int my_put_shortint(int nb)
{
    short int modulo = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb < 10)
        my_putchar(48 + nb);
    if (nb >= 0) {
        if (nb >= 10 && nb <= 4369) {
            modulo = nb % 10;
            nb = (nb - modulo) / 10;
            my_put_nbr(nb);
            my_putchar(48 + modulo);
        }
    }else {
        nb = 0;
        my_putchar(48 + nb % 10);
    }
}

int signe(const char *s, va_list ap, int i)
{
    while (s[i] != '\0') {
        if (s[i] == '%' && s[i + 1] == '+' &&
        (s[i + 2] == 'd' || s[i + 2] == 'i')) {
            my_put_plus(va_arg(ap, int));
            return (0);
        }
        if (s[i] == '%' && s[i + 1] == 'h' &&
        (s[i + 2] == 'd' || s[i + 2] == 'i')) {
            my_put_shortint(va_arg(ap, int));
            return (0);
        }if (s[i] == '%' && s[i + 1] == 'h' && s[i + 2] == 'u') {
            my_put_shortint(va_arg(ap, int));
            return (0);
        }else
            return (0);
        i++;
    }
}
