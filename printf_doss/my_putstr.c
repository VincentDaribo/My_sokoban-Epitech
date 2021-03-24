/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** Made by Vincent Daribo
*/

#include<unistd.h>

int my_putstr(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    write(1, str, len);
}
