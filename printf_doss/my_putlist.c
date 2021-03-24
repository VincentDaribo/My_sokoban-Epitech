/*
** EPITECH PROJECT, 2020
** my_putlist
** File description:
** Made by Vincent Daribo
*/
#include"link_list.h"

int my_printf(const char *s, ...);

void my_putlist(List_t *list)
{
    while (list) {
        my_printf("%d ", list->nb);
        list = list->next;
    }
}

int len_list(List_t *list)
{
    int j = 0;

    while (list) {
        list = list->next;
        j++;
    }
    return (j);
}