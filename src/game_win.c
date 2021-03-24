/*
** EPITECH PROJECT, 2021
** game window
** File description:
** Made by Vincent Daribo
*/

#include"../includes/sokoban.h"

int count_ch(char **str, char c)
{
    int i = 0;
    int count = 0;

    for (int j = 0; str[j]; j++)
        for (i = 0; str[j][i] != '\0'; i++)
            if (str[j][i] == c)
                count++;
    return count;
}

int find_max_width(char *str)
{
    int max_width = 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] != '\n' && str[i]) {
            count++;
            i++;
        }
        if (count > max_width)
            max_width = count;
        count = 0;
    }
    return (max_width);
}

pos_t *get_pos(char **str, char c)
{
    int i = 0;
    int j = 0;
    pos_t *obj = malloc(sizeof(pos_t));

    for (; str[j] != NULL; j++)
        for (i = 0; str[j][i] != '\0'; i++) {
            if (str[j][i] == c) {
                obj->x = i;
                obj->y = j;
                obj->init_x = i;
                obj->init_y = j;
            }
        }
    return obj;
}

char **remove_char_from(char **str, char to_remove)
{
    char **new_arr;
    int y = 0;
    int x = 0;

    new_arr = malloc(sizeof(char *) * (my_arrlen(str) + 1));
    for (y = 0; str[y] != NULL; y++) {
        new_arr[y] = malloc(sizeof(char) * (my_strlen(str[y]) + 1));
        for (x = 0; str[y][x]; x++) {
            if (str[y][x] == to_remove)
                new_arr[y][x] = ' ';
            else
                new_arr[y][x] = str[y][x];
        }
        new_arr[y][x] = '\0';
    }
    return (new_arr);
}

int main_window(char **map, int width, int height)
{
    window_set_t win = {width, height, 0, 0, remove_char_from(map, 'P'),
        remove_char_from(map, 'P'), get_pos(map, 'P'), count_ch(map, 'O'), 0};
    pos_t **o_pos = build_list(win.map, win.nbr_o, 'O');
    pos_t **x_pos = build_list(win.map, win.nbr_o, 'X');

    if (win.nbr_o != count_ch(map, 'X'))
        return 84;
    start(win.map, win.player);
    while (1) {
        x_pos = build_list(win.map, win.nbr_o, 'X');
        if ((win.e = w_l(win.map, x_pos, o_pos, count_ch(win.map, 'X'))) != -1) {
            end(&win);
            return (win.e);
        }
        move(win.player->y, win.player->x);
        inputs_handling(getch(), &win);
        put_o(o_pos, &win);
        refresh();
    }
    end(&win);
}
