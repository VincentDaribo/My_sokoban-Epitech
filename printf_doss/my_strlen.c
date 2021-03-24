/*
** EPITECH PROJECT, 2020
** my_strlen
** File description:
** Made by Vincent Daribo
*/

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return (i);
}
