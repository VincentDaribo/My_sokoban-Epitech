/*
** EPITECH PROJECT, 2021
** step3
** File description:
** Made by Vincent Daribo
*/

#include "../includes/sokoban.h"

#include <stdlib.h>

char **str_to_arr(char *arg, char sep)
{
    int i = 0;
    int space = 1;
    int compt = 0;
    int len = 0;
    char **arr;

    for (i = 0; arg[i] != '\0'; i++)
        if (arg[i] == sep)
            space++;
    arr = malloc(sizeof(char *) * (space + 2));
    for (i = 0; i != space; i++) {
        for (; arg[len] != sep && arg[len] != '\0'; len++)
            compt++;
        len++;
        arr[i] = malloc(sizeof(char) * compt + 1);
        arr[i][compt] = '\0';
        compt = 0;
    }
    arr[i] = NULL;
    return (arr);
}

char **arg_to_arr(char *arg, char sep)
{
    char **arr = str_to_arr(arg, sep);
    int i = 0;
    int j = 0;
    int k = 0;

    for (i = 0; arr[i]; i++) {
        for (k = 0; arg[j] != sep && arg[j] && arg[j] != '\n'; j++, k++) {
            arr[i][k] = arg[j];
        }
        if (arg[j])
            j++;
    }
    return (arr);
}
