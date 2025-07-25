/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** my_strstr
*/

#include "../include/my_printf.h"
#include "../include/my_radar.h"

int my_str_true_cmp(char *s1, char *s2)
{
    int x = 0;
    int y = 0;

    if (my_strcmp(s1, s2) != 0)
        return 0;
    while (s1[x] && s2[y]) {
        if (s1[x] != s2[y])
            return 0;
        x++;
        y++;
    }
    return 1;
}
