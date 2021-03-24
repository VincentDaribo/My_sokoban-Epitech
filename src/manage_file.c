/*
** EPITECH PROJECT, 2021
** open an manage a file
** File description:
** Made by Vincent Daribo
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int is_a_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        close(fd);
        return (84);
    }
    close(fd);
    return (0);
}

char *recup_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buff;
    struct stat info;

    stat(filepath, &info);
    buff = malloc(sizeof(char) * (info.st_size + 1));
    buff[info.st_size] = '\0';
    read(fd, buff, info.st_size);
    close(fd);
    return (buff);
}

int check_format(char *file, char *chars_allowed)
{
    int i = 0;
    int j = 0;

    for (i = 0; file[i] != '\0'; i++) {
        for (j = 0; chars_allowed[j] && file[i] != chars_allowed[j]; j++);
        if (!chars_allowed[j])
            return (-1);
    }
    return (0);
}
