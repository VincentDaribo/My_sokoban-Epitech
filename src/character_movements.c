/*
** EPITECH PROJECT, 2021
** manage character movements
** File description:
** Made by Vincent Daribo
*/

#include"../includes/sokoban.h"

void move_up(pos_t *pos, char **map)
{
    (map[pos->y][pos->x] != 'O') ? mvaddch(pos->y, pos->x, ' ') :
    mvaddch(pos->y, pos->x, 'O');
    if (map[pos->y - 1][pos->x] == 'X' && map[(pos->y - 2)][pos->x] != 'X'
        && map[(pos->y - 2)][pos->x] != '#') {
        map[pos->y - 2][pos->x] = 'X';
        map[pos->y - 1][pos->x] = ' ';
        pos->y--;
    }
    else if (map[pos->y - 1][pos->x] != '#' && map[pos->y - 1][pos->x] != 'X' &&
            (map[pos->y - 2][pos->x] != 'X' || map[pos->y - 2][pos->x] != '#'))
        pos->y--;
    disp_map(map);
}

void move_down(pos_t *pos, char **map)
{
    (map[pos->y][pos->x] != 'O') ? mvaddch(pos->y, pos->x, ' ') :
    mvaddch(pos->y, pos->x, 'O');
    if (map[(pos->y + 1)][pos->x] == 'X' && map[(pos->y + 2)][pos->x] != 'X' &&
        map[(pos->y + 2)][pos->x] != '#') {
        map[pos->y +2][pos->x] = 'X';
        map[pos->y + 1][pos->x] = ' ';
        pos->y++;
    }
    else if (map[pos->y + 1][pos->x] != '#' && map[(pos->y + 1)][pos->x] != 'X'
    && (map[(pos->y + 2)][pos->x] != 'X' || map[(pos->y + 2)][pos->x] != '#'))
        pos->y++;
    disp_map(map);
}

void move_right(pos_t *pos, char **map)
{
    (map[pos->y][pos->x] != 'O') ? mvaddch(pos->y, pos->x, ' ') :
    mvaddch(pos->y, pos->x, 'O');
    if (map[(pos->y)][pos->x + 1] == 'X' && map[(pos->y)][pos->x + 2] != 'X' &&
        map[pos->y][pos->x + 2] != '#') {
        map[pos->y][pos->x + 2] = 'X';
        map[pos->y][pos->x + 1] = ' ';
        pos->x++;
    }
    else if (map[pos->y][pos->x + 1] != '#' && map[pos->y][pos->x + 1] != 'X' &&
            (map[pos->y][pos->x + 2] != 'X' || map[pos->y][pos->x + 2] != '#'))
        pos->x++;
    disp_map(map);
}

void move_left(pos_t *pos, char **map)
{
    (map[pos->y][pos->x] != 'O') ? mvaddch(pos->y, pos->x, ' ') :
    mvaddch(pos->y, pos->x, 'O');
    if (map[(pos->y)][pos->x - 1] == 'X' && map[(pos->y)][pos->x - 2] != 'X' &&
        map[pos->y][pos->x - 2] != '#') {
        map[pos->y][pos->x - 2] = 'X';
        map[pos->y][pos->x - 1] = ' ';
        pos->x--;
    }
    else if (map[pos->y][pos->x - 1] != '#' && map[pos->y][pos->x - 1] != 'X' &&
            (map[pos->y][pos->x - 2] != 'X' || map[pos->y][pos->x - 2] != '#'))
        pos->x--;
    disp_map(map);
}

int inputs_handling(int input, window_set_t *win)
{
    switch (input)
    {
    case ' ':
        reset_map(win->map, win->save, win->player);
        break;
    case KEY_UP:
        move_up(win->player, win->map);
        break;
    case KEY_DOWN:
        move_down(win->player, win->map);
        break;
    case KEY_RIGHT:
        move_right(win->player, win->map);
        break;
    case KEY_LEFT:
        move_left(win->player, win->map);
        break;
    }
    mvaddch(win->player->y, win->player->x, 'P');
    return 0;
}
