/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Made by Vincent Daribo
*/

#include <stdio.h>

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (i = 0; s2[i] == s1[i] && s1[i] && s2[i]; i++);
    if (s1[i] == '\0' && s2[i] == '\0') {
        return (0);
    }
    return (1);
}

int my_strncmp(char *s1, char *s2)
{
    int i = 0;

    for (i = 0; s2[i] == s1[i] && s1[i] && s2[i]; i++);
    if (s1[i] == '\0') {
        return (0);
    }
    return (1);
}
