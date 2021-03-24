/*
** EPITECH PROJECT, 2020
** display_stdargs
** File description:
** Made by Vincent Daribo
*/

#include<stdarg.h>

#include"my.h"

int format(const char *s, va_list ap, int i)
{
    for (i ;s[i] == '%'; i += 2) {
        if (s[i + 1] == '#' && s[i + 2] == 'o') {
            my_put_nbr(0);
            my_put_oct(va_arg(ap, unsigned int));
            return (0);
        }
        if (s[i + 1] == '#' && s[i + 2] == 'x') {
            write(1, "0x", 2);
            my_put_hex(va_arg(ap, unsigned int));
            return (0);
        }
    }return (0);
}

int conv(const char *s, va_list ap, int i)
{
    while (s[i] != '\0') {
        if (s[i] == '%' && s[i + 1] == 'o') {
            my_put_oct(va_arg(ap, unsigned int));
            return (0);
        }
        if (s[i] == '%' && s[i + 1] == 'x') {
            my_put_hex(va_arg(ap, unsigned int));
            return (0);
        }
        if (s[i] == '%' && s[i + 1] == 'b') {
            my_put_bin(va_arg(ap, unsigned int));
            return (0);
        } return (0);
        i++;
    }
}

int disp(const char *s, va_list ap, int i)
{
    while (s[i] != '\0') {
        if (s[i] == '%' && s[i + 1] == 'c') {
            my_putchar(va_arg(ap, int));
            return (0);
        }
        if (s[i] == '%' && (s[i + 1] == 's' || s[i + 1] == 'S')) {
            my_putstr(va_arg(ap, char *));
            return (0);
        }
        if (s[i] == '%' && (s[i + 1] == 'i' || s[i + 1] == 'd')){
            my_put_nbr(va_arg(ap, int));
            return (0);
        } else
            return (0);
        i++;
    }
}

int my_printf(const char *s, ...)
{
    int i;
    va_list ap;

    va_start(ap, s);
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%' && (s[i + 1] == '#' ||
        s[i + 1] == '+' || s[i + 1] == 'h')) {
            format(s, ap, i);
            signe(s, ap, i);
            i += 2;
        }
        else if (s[i] == '%') {
            disp(s, ap, i);
            conv(s, ap, i);
            u(s, ap, i);
            i += 1;
        }else
            my_putchar(s[i]);
    }va_end(ap);
}
