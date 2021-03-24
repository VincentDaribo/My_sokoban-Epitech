/*
** EPITECH PROJECT, 2021
** win or lose
** File description:
** Made by Vincent Daribo
*/

#include "../includes/sokoban.h"

int victory(char **map, pos_t **o_pos, int nb_x)
{
    int count = 0;

    for (int i = 0; o_pos[i]; i++)
        if (map[o_pos[i]->y][o_pos[i]->x] == 'X')
            count++;
    if (count == nb_x)
        return 0;
    else
        return -1;
}

int is_blocked(char **map, pos_t *pos)
{
    int blocked = 0;

    if ((map[pos->y - 1][pos->x] == 'X' || map[pos->y - 1][pos->x] == '#') &&
        (map[pos->y][pos->x + 1] == 'X' || map[pos->y][pos->x + 1] == '#'))
        blocked++;
    if ((map[pos->y + 1][pos->x] == 'X' || map[pos->y + 1][pos->x] == '#') &&
        (map[pos->y][pos->x - 1] == 'X' || map[pos->y][pos->x - 1] == '#'))
        blocked++;
    if ((map[pos->y][pos->x - 1] == 'X' || map[pos->y][pos->x - 1] == '#') &&
        (map[pos->y - 1][pos->x] == 'X' || map[pos->y - 1][pos->x] == '#'))
        blocked++;
    if ((map[pos->y][pos->x + 1] == 'X' || map[pos->y][pos->x + 1] == '#') &&
        (map[pos->y + 1][pos->x] == 'X' || map[pos->y + 1][pos->x] == '#'))
        blocked++;
    if (blocked >= 1)
        return 1;
    return 0;
}

int lost(char **map, pos_t **x_pos, int nb_x)
{
    int count = 0;

    for (int i = 0; x_pos[i]; i++)
        count += is_blocked(map, x_pos[i]);
    if (nb_x == count)
        return 1;
    else
        return -1;
}

int w_l(char **map, pos_t **x_pos, pos_t **o_pos, int nb_x)
{
    if (victory(map, o_pos, nb_x) == 0) {
        clear();
        return 0;
    }
    if (lost(map, x_pos, nb_x) == 1) {
        clear();
        return 1;
    }
    return -1;
}
