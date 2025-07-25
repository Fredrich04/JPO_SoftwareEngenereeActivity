/*
** EPITECH PROJECT, 2025
** time
** File description:
** time
*/

#include "../include/my_radar.h"

radar_t up_time_find(radar_t box)
{
    sfText_setString(box.text, my_int_in_str(box.time));
    sfText_setPosition(box.text, (sfVector2f){1700, 0});
    sfRenderWindow_drawText(box.window, box.text, NULL);
    return box;
}
