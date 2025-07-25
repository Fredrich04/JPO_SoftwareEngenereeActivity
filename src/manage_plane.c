/*
** EPITECH PROJECT, 2025
** manage_plane
** File description:
** manage_plane
*/

#include "../include/my_radar.h"

sfVector2f rotate_around(sfVector2f center, float radius, float angle_deg) {
    float rad = angle_deg * M_PI / 180.0f;
    return (sfVector2f){
        center.x + radius * cosf(rad),
        center.y + radius * sinf(rad)
    };
}

void update_missile(Missil *m, float dt)
{
    float speed = 0.05; // degrés par seconde

    if (m->total_angle <= 0)
        return;

    m->angle += speed * dt;

    if (m->angle >= m->total_angle)
        m->angle = m->total_angle;

    sfVector2f pos = rotate_around(m->center, m->radius, m->angle);
    m->ai = pos;

    sfSprite_setPosition(m->plane, m->ai);
}

void destroy_plane_list(Missil **p)
{
    Missil *plane = *p;
    Missil *next;

    while (plane != NULL) {
        next = plane->next;
        sfSprite_destroy(plane->plane);
        sfTexture_destroy(plane->Missilext);
        sfRectangleShape_destroy(plane->rectangle);
        free(plane);
        plane = next;
    }
}

radar_t mouvment_manager(radar_t box, Missil *plane, float dt)
{
    double dx = plane->af.x - plane->ac.x;
    double dy = plane->af.y - plane->ac.y;
    float dist = hypot(dx, dy);

    if (dist < 1.0f)  // si proche de la cible, on arrête
        return box;

    sfVector2f direction = {dx / dist, dy / dist};
    float speed = 0.015f;
    sfVector2f move = {direction.x * speed * dt, direction.y * speed * dt};

    sfSprite_move(plane->plane, move);
    plane->ac = sfSprite_getPosition(plane->plane);
    sfRectangleShape_setPosition(plane->rectangle, plane->ac);

    return box;
}

radar_t disp_plane(radar_t box, Missil **p, float dt)
{
    Missil *plane = *p;

    while (plane != NULL) {
        box = mouvment_manager(box, plane, dt);
        if (plane->s == 1)
            sfRenderWindow_drawSprite(box.window, plane->plane, NULL);
        plane = plane->next;
    }
    return box;
}

