/*
** EPITECH PROJECT, 2025
** box3
** File description:
** box3
*/

#include "../include/my_radar.h"

char *alloc_str(int nb, char *res)
{
    int d = 1;

    if (nb < 0)
        d++;
    while (nb >= 10) {
        nb = nb / 10;
        d += 1;
    }
    res = malloc(sizeof(char) * d + 1);
    memset(res, 0, d);
    return res;
}

char *my_int_in_str(int nb)
{
    int nbr = nb;
    int numb = 1;
    char *res = alloc_str(nb, res);
    int i = 0;

    if (nb == 0) {
        res[i] = '0';
        i++;
        return res;
    }
    while (numb < nbr)
        numb *= 10;
    numb = numb / 10;
    while (numb) {
        res[i] = (nbr / numb) % 10 + '0';
        i++;
        numb = numb / 10;
    }
    res[i] = '\0';
    return res;
}

char *all(int nb)
{
    char *r;
    int x = 1;

    while (nb >= 10) {
        x++;
        nb /= 10;
    }
    r = malloc(sizeof(char) * x + 1);
    memset(r, 0, x);
    return r;
}

char *my_print_int_str(int nb)
{
    static int i = 0;
    char *res = all(nb);

    if (nb >= 0 && nb < 10) {
        res[i] = nb + '0';
        i++;
    } else if (nb < 0) {
        res[i] = '-';
        i++;
        my_print_int_str(nb * (-1));
    } else {
        my_print_int_str(nb / 10);
        my_print_int_str(nb % 10);
    }
    return res;
}
