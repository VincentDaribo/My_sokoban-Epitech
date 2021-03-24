/*
** EPITECH PROJECT, 2021
** sokoban header
** File description:
** Made by Vincent Daribo
*/

#include<ncurses.h>
#include<unistd.h>
#include <fcntl.h>
#include"my.h"
#include <stdlib.h>
#include<stdio.h>

#ifndef SOKOBAN_H
#define SOKOBAN_H

typedef struct pos {
    int init_y;
    int init_x;
    int x;
    int y;
}pos_t;

typedef struct window_set {
    int width;
    int height;
    int scr_width;
    int scr_height;
    char **map;
    char **save;
    pos_t *player;
    int nbr_o;
    int e;

}window_set_t;

char *recup_file(char *filepath);

void start(char **virgin_map, pos_t *pos);

int find_max_width(char *str);

int count_ch(char **str, char c);

int check_format(char *file, char *chars_allowed);

int is_a_file(char *filepath);

int my_strcmp(char *s1, char *s2);

int main_window(char **map, int width, int height);

int inputs_handling(int input, window_set_t *win);

int my_arrlen(char **tab);

char **arg_to_arr(char *arg, char sep);

void destroy_arr(char **arr);

void my_put_tab(char **tab);

pos_t **build_list(char **map, int size, char to_get);

void free_win(window_set_t *win);

void putlist(pos_t **list);

void reset_map(char **virgin_map, char **save, pos_t *pos);

void disp_map(char **virgin_map);

void end(window_set_t *win);

int victory(char **map, pos_t **o_pos, int nb_x);

int w_l(char **map, pos_t **x_pos, pos_t **o_pos, int nb_x);

int lost(char **map, pos_t **x_pos, int nb_x);

void put_o(pos_t **list, window_set_t *win);
#endif
