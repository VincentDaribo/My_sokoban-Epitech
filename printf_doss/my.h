/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** header
*/

#ifndef MY_H

#define MY_H

#include <unistd.h>

#include <stdarg.h>

int my_printf(const char *s, ...);

void my_putchar(char c);

int my_strlen(char const *str);

int my_putstr(char const *str);

int my_put_nbr(int nb);

int my_put_hex(int nb);

int my_put_bin(unsigned int nb);

int my_put_oct(unsigned int nb);

int signe(const char *s, va_list ap, int i);

int u(const char *s, va_list ap, int i);
#endif
