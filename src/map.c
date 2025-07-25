/*
** EPITECH PROJECT, 2025
** map
** File description:
** map
*/

#include "../include/my_radar.h"

radar_t make_map(char *jp, radar_t box)
{
    box.map = sfSprite_create();
    box.map_text = sfTexture_createFromFile(jp, NULL);
    sfSprite_setTexture(box.map, box.map_text, sfTrue);
    return box;
}
