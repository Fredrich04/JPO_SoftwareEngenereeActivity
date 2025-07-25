/*
** EPITECH PROJECT, 2024
** reader
** File description:
** reader
*/

#include "../include/my_radar.h"
#include "../include/my_printf.h"

sfVector2f continents[5] = {
    {1000, 200}, // Europe
    {1100, 550}, // Afrique
    {400, 250},  // Amérique
    {1450, 200}, // Asie
    {1700, 650}  // Océanie
};

sfVector2f dep[5] = {
    {1683.00, 986.00},
    {1577.00, 915.00},
    {1693.00, 935.00},
    {1686.00, 992.00},
    {1649.00, 921.00}
};

void add_tower_info(Defense **l, int x)
{
    Defense *tow = malloc(sizeof(*tow));

    tow->ai = tow->ac = continents[x];
    tow->af = dep[x];
    tow->id = x;
    tow->s = 1;
    tow->tower = sfSprite_create();
    tow->circle = sfCircleShape_create();
    tow->tower_text = sfTexture_createFromFile("ress/t.png", NULL);
    sfSprite_setTexture(tow->tower, tow->tower_text, sfTrue);
    sfSprite_setPosition(tow->tower, tow->ai);
    tow->bounds = sfSprite_getLocalBounds(tow->tower);
    tow->next = *l;
    *l = tow;
}

void add_plane_info(Missil **p, int x)
{
    Missil *plane = malloc(sizeof(*plane));

    plane->plane = sfSprite_create();
    plane->ai = plane->ac = dep[x];
    plane->af = continents[x];
    plane->id = x;
    plane->s = 1;
    plane->Missilext = sfTexture_createFromFile("ress/p.png", NULL);
    sfSprite_setTexture(plane->plane, plane->Missilext, sfTrue);
    sfSprite_setPosition(plane->plane, plane->ai);
    plane->rectangle = sfRectangleShape_create();
    sfRectangleShape_setSize(plane->rectangle, (sfVector2f){20, 20});
    sfRectangleShape_setFillColor(plane->rectangle, sfTransparent);
    sfRectangleShape_setOutlineThickness(plane->rectangle, 1.5);
    sfRectangleShape_setOutlineColor(plane->rectangle, sfGreen);
    plane->bounds = sfSprite_getLocalBounds(plane->plane);
    plane->next = *p;
    *p = plane;
}

int read_file(Defense **l, Missil **p)
{
    for (int x = 0; x < 5; x++) {
        add_plane_info(p, x);
        add_tower_info(l, x);
    }
}
