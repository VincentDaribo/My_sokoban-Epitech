/*
** EPITECH PROJECT, 2021
** manage tab
** File description:
** Made by Vincent Daribo
*/

#include<stdlib.h>
#include<unistd.h>

int my_strlen(char *str);

int my_arrlen(char **tab)
{
    int i;

    for (i = 0; tab[i]; i++);
    return (i);
}

void destroy_arr(char **arr)
{
    int i;

    for (i = 0; arr[i]; i++)
        free(arr[i]);
    free(arr);

}

void my_put_tab(char **tab)
{
    int i = 0;
    int j = 0;

    for (i = 0; tab[i]; i++) {
        for (j = 0; tab[i][j] != 0; j++)
            write(1, &tab[i][j], 1);
        write(1, "\n", 1);
    }
}

char **conv_arr(char *str)
{
    int i;
    char **key ;

    key = malloc(sizeof(char *) * my_strlen(str) + 1);
    for (i = 0; str[i]; i++){
        key[i] = malloc(sizeof(char) * 2);
        key[i][0] = str[i];
        key[i][1] = '\0';
    }
    return (key);
}
