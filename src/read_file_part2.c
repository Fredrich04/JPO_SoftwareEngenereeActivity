/*
** EPITECH PROJECT, 2025
** part2
** File description:
** part2
*/

#include "../include/my_radar.h"

void add_plane2(Missil *plane, char **s, int x)
{
    plane->ai.x = to_number(s[x + 1]);
    plane->ai.y = to_number(s[x + 2]);
    plane->af.x = to_number(s[x + 3]);
    plane->af.y = to_number(s[x + 4]);
    plane->va = to_number(s[x + 5]);
    plane->d = to_number(s[x + 6]);
}
