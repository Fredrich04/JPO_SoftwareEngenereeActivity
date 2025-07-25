/*
** EPITECH PROJECT, 2025
** manage_tow
** File description:
** manage_tow
*/

#include "../include/my_radar.h"

void destroy_tow_list(Defense **t)
{
    Defense *tow = *t;
    Defense *next;

    while (tow != NULL) {
        next = tow->next;
        sfSprite_destroy(tow->tower);
        sfTexture_destroy(tow->tower_text);
        free(tow);
        tow = next;
    }
}

radar_t mouvment_manager2(radar_t box, Defense *def, float dt)
{
    double dx = def->af.x - def->ac.x;
    double dy = def->af.y - def->ac.y;
    float dist = hypot(dx, dy);

    if (dist < 1.0f)  // si proche de la cible, on arrête
        return box;

    sfVector2f direction = {dx / dist, dy / dist};
    float speed = (def->id == 0) ? 0.020 : (def->id == 1) ? 0.020 : (def->id == 2) ? 0.005 : (def->id == 3) ? 0.050 : (def->id == 4) ? 0.020 : 0.020;
    sfVector2f move = {direction.x * speed * dt, direction.y * speed * dt};

    sfSprite_move(def->tower, move);
    def->ac = sfSprite_getPosition(def->tower);
    return box;
}

radar_t disp_tow(radar_t box, Defense **t, float dt)
{
    Defense *tow = *t;
    sfVector2f pos_tow;
    sfVector2f c_pos;

    while (tow != NULL) {
        box = mouvment_manager2(box, tow, dt);
        if (tow->s == 1)
            sfRenderWindow_drawSprite(box.window, tow->tower, NULL);
        tow = tow->next;
    }
    return box;
}
