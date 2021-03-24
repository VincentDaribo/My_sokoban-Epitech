/*
** EPITECH PROJECT, 2021
** main
** File description:
** Made by Vincent Daribo
*/

#include"../includes/sokoban.h"

void usage(void)
{
    char *usage = recup_file("usage");

    my_putstr(usage);
    free(usage);
}

int error_handling(char *file)
{
    char *str;

    if (is_a_file(file) == 84) {
        return (84);
    }
    str = recup_file(file);
    if (check_format(str, "#XOP \n") == -1 ) {
        free(str);
        return 84;
    }
    if (my_strlen(str) < 2) {
        free(str);
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    char **map;
    int end = 0;
    char *str;

    if (ac != 2)
        return 84;
    if (my_strcmp(av[1], "-h") == 0) {
        usage();
        return 0;
    }
    if (error_handling(av[1]) == 84)
        return 84;
    str = recup_file(av[1]);
    map = arg_to_arr(recup_file(av[1]), '\n');
    end = main_window(map, find_max_width(str), my_arrlen(map));
    free(str);
    destroy_arr(map);
    my_printf("%s", (end == 1) ? "YOU LOSE" : "YOU WIN");
    return end;
}
