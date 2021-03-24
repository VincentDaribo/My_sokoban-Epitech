/*
** EPITECH PROJECT, 2020
** conv_int
** File description:
** Made by Rayan et Vincent
*/

int my_strlen(char *str);

int my_compute_power_rec(int nb, int p)
{
    int tmp;

    tmp = nb;
    if (p == 0)
        return (1);
    if (p <= 0)
        return (0);
    while (p != 1){
        return (tmp * my_compute_power_rec(nb, p-1));
        if (nb >= 32766)
            return (0);
    }
    return (nb);
}

int conv_int(char *str)
{
    int i;
    int sign = 1;
    int nb = 0;
    int p = my_strlen(str) - 1;

    for (i = 0;str[i] != '\0'; i++) {
        if (str[i] == '-') {
            i += 1;
            p -= 1;
            sign = -1;
        }
        nb += (str[i] - 48) * my_compute_power_rec(10, p);
        p -= 1;
    }
    if (i == 0)
        return (84);
    return (nb * sign);
}
