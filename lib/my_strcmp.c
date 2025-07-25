/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** a function
*/

#include "../include/my_printf.h"
#include "../include/my_radar.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = my_strlen(s1);
    int j = my_strlen(s2);

    if ((i - j) < 0)
        return (-1);
    else if ((i - j) > 0)
        return 1;
    else
        return 0;
}
