/*
** EPITECH PROJECT, 2021
** lauch and end the game screen
** File description:
** Made by Vincent Daribo
*/

#include "../includes/sokoban.h"

void disp_map(char **virgin_map)
{
    int i = 0;

    for (i = 0; virgin_map[i] != NULL; i++)
        mvprintw(i, 0, virgin_map[i]);
}

void reset_map(char **virgin_map, char **save, pos_t *pos)
{
    int i = 0;
    char **tmp = save;

    for (i = 0; tmp[i] != NULL; i++)
        for (int j = 0; tmp[i][j]; j++)
            virgin_map[i][j] = tmp[i][j];
    pos->x = pos->init_x;
    pos->y = pos->init_y;
    for (i = 0; virgin_map[i] != NULL; i++)
        mvprintw(i, 0, virgin_map[i]);
    mvaddch(pos->y, pos->x, 'P');
}

void start(char **virgin_map, pos_t *pos)
{
    initscr();
    noecho();
    keypad(stdscr, true);
    disp_map(virgin_map);
    mvaddch(pos->y, pos->x, 'P');
}

void end(window_set_t *win)
{
    free_win(win);
    endwin();
}
