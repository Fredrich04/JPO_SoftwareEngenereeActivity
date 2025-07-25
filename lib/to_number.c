/*
** EPITECH PROJECT, 2024
** to_number
** File description:
** to_number
*/

#include <stdio.h>
#include "../include/my_radar.h"

int selector(int c, int i, int d, char const *str)
{
    if (str[i] >= 00 && str[i] <= 42 ||
        str[i] >= 72 && str[i] <= 127 ||
        str[i] == ',' || str[i] == '/' || str[i] == '.') {
        return (d * c);
    } else
        return 0;
}

int count(int c, int i, int d, char const *str)
{
    if (str[i] >= '0' && str[i] <= '9')
        d = d * 10 + str[i] - '0';
    return d;
}

int to_number(char const *str)
{
    int c = 1;
    int i = 0;
    int d = 0;

    while (str[i] != '\0') {
        if (str[i] == '-')
            c *= -1;
        if (str[i] == '+')
            c *= 1;
        d = count(c, i, d, str);
        if (d >= 2147483647 || d <= -214783648) {
            d = 0;
            return 0;
        }
        if (selector(c, i, d, str) != 0)
            return (d * c);
        i++;
    }
    return (d * c);
}
