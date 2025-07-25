 /*
** EPITECH PROJECT, 2025
** event2
** File description:
** event2
*/

#include "../include/my_radar.h"

void pix_tow(Defense **t, int x)
{
    Defense *tow = *t;

    while (tow != NULL) {
        if ((x % 2) == 0)
            tow->tower_text = sfTexture_createFromFile("ress/t2.png", NULL);
        else
            tow->tower_text = sfTexture_createFromFile("ress/t.png", NULL);
        tow = tow->next;
    }
}

radar_t pix_map(radar_t box, int x, Defense **t)
{
    if ((x % 2) == 0) {
        box.map_text = sfTexture_createFromFile("ress/map3.jpg", NULL);
        sfSprite_setTexture(box.map, box.map_text, sfTrue);
    } else {
        box.map_text = sfTexture_createFromFile("ress/map.jpg", NULL);
        sfSprite_setTexture(box.map, box.map_text, sfTrue);
    }
    pix_tow(t, x);
    return box;
}
