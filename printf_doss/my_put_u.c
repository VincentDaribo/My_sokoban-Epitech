/*
** EPITECH PROJECT, 2020
** my_put_u
** File description:
** Made by Vincent Daribo
*/

#include<stdarg.h>

void my_putchar(char c);

int my_put_u(unsigned int nb)
{
    unsigned int modulo = 0;

    if (nb < 10)
        my_putchar(48 + nb);
    if (nb >= 10) {
        modulo = nb % 10;
        nb = (nb - modulo) / 10;
        my_put_u(nb);
        my_putchar(48 + modulo);
    }
}

int u(const char *s, va_list ap, int i)
{
    while (s[i] != '\0') {
        if (s[i] == '%' && s[i + 1] == 'u') {
            my_put_u(va_arg(ap, unsigned int));
            return (0);
        }else
            return (0);
        i++;
    }
}
