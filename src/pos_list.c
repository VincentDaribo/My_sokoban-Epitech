/*
** EPITECH PROJECT, 2021
** create a list of positions
** File description:
** Made by Vincent Daribo
*/

#include"../includes/sokoban.h"

pos_t *new_block(int x, int y)
{
    pos_t *block = malloc(sizeof(pos_t *));

    block->y = y;
    block->x = x;
    return block;
}

pos_t **build_list(char **map, int size, char to_get)
{
    pos_t **arr = malloc(sizeof(pos_t *) * (size + 1));
    int i = 0;

    arr[size] = NULL;
    for (int y = 0; map[y]; y++)
        for (int x = 0; map[y][x]; x++) {
            if (map[y][x] == to_get) {
                arr[i] = new_block(x, y);
                i++;
            }
        }
    return arr;
}

void putlist(pos_t **list)
{
    for (int i = 0; list[i]; i++)
        my_printf("x : %d y : %d\n", list[i]->x, list[i]->y);
}

void put_o(pos_t **list, window_set_t *win)
{
    for (int i = 0; list[i] != NULL; i++)
        if (win->map[list[i]->y][list[i]->x] == ' ')
            win->map[list[i]->y][list[i]->x] = 'O';
    disp_map(win->map);
    mvaddch(win->player->y, win->player->x, 'P');
}
void free_win(window_set_t *win)
{
    destroy_arr(win->map);
    destroy_arr(win->save);
    free(win->player);
}
