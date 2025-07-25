/*
** EPITECH PROJECT, 2024
** event
** File description:
** event
*/

#include "../include/my_radar.h"

void hitbox(Defense **t, Missil **p, int x)
{
    Defense *tow = *t;
    Missil *plane = *p;

    while (tow != NULL) {
        if ((x % 2) == 0)
            sfCircleShape_setOutlineColor(tow->circle, sfTransparent);
        else
            sfCircleShape_setOutlineColor(tow->circle, sfBlue);
        tow = tow->next;
    }
    while (plane != NULL) {
        if ((x % 2) == 0)
            sfRectangleShape_setOutlineColor(plane->rectangle, sfTransparent);
        else
            sfRectangleShape_setOutlineColor(plane->rectangle, sfGreen);
        plane = plane->next;
    }
}

radar_t map(radar_t box, int x)
{
    if ((x % 2) == 0) {
        box.map_text = sfTexture_createFromFile("ress/map2.jpg", NULL);
        sfSprite_setTexture(box.map, box.map_text, sfTrue);
    } else {
        box.map_text = sfTexture_createFromFile("ress/map.jpg", NULL);
        sfSprite_setTexture(box.map, box.map_text, sfTrue);
    }
    return box;
}

radar_t key_event2(radar_t box, Defense **t)
{
    static int y = 0;
    static int x = 0;

    switch (box.event.key.code) {
    case sfKeyR:
        box = map(box, x);
        x++;
        break;
    case sfKeyP:
        pix_map(box, y, t);
        y++;
        break;
    }
    return box;
}

radar_t key_event(radar_t box, Defense **t, Missil **p)
{
    static int x = 0;
    static int y = 0;

    switch (box.event.key.code) {
    case sfKeyL:
        hitbox(t, p, x);
        x++;
        break;
    case sfKeyS:
        box.sp = (y % 2);
        y++;
        break;
    case sfKeyEscape:
        sfRenderWindow_close(box.window);
        break;
    }
    box = key_event2(box, t);
    return box;
}

radar_t analyse_events(radar_t box, Defense **t, Missil **p)
{
    while (sfRenderWindow_pollEvent(box.window, &box.event)) {
        if (box.event.type == sfEvtClosed)
            sfRenderWindow_close(box.window);
        if (box.event.type == sfEvtKeyReleased)
            box = key_event(box, t, p);
    }
    return box;
}
