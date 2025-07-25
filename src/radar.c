/*
** EPITECH PROJECT, 2024
** radar
** File description:
** radar
*/

#include "../include/my_radar.h"

void display(radar_t box)
{
    sfRenderWindow_display(box.window);
}

animated_text_t *create_animated_text(const char *str, radar_t intro, int size, sfVector2f pos) 
{
    animated_text_t *anim = malloc(sizeof(animated_text_t));

    anim->text = sfText_create();
    anim->full_string = strdup(str);
    anim->index = 0;
    anim->clock = sfClock_create();
    anim->delay = DELAY;
    sfText_setFont(anim->text, intro.font);
    sfText_setCharacterSize(anim->text, size);
    sfText_setPosition(anim->text, pos);
    return anim;
}

void typing_animation(animated_text_t *anim) 
{
    sfTime time;
    char *buffer = malloc(sizeof(char) * 1024);

    if (anim->index >= strlen(anim->full_string))
        return;
    time = sfClock_getElapsedTime(anim->clock);
    if (sfTime_asSeconds(time) >= anim->delay) {
        anim->index++;
        strncpy(buffer, anim->full_string, anim->index);
        sfText_setString(anim->text, buffer);
        sfText_setColor(anim->text, sfBlack);
        if (rand() % 10 == 0)
            sfText_setPosition(anim->text, (sfVector2f){100 + rand() % 10 - 1, 100 + rand() % 10 - 1});        
        sfClock_restart(anim->clock);
    }
    free(buffer);
    buffer = NULL;
}

void draw_animated_text(sfRenderWindow *window, animated_text_t *anim) {
    sfRenderWindow_drawText(window, anim->text, NULL);
}


void end_key_events(radar_t intro)
{
    switch (intro.event.key.code) {
    case sfKeyEscape:
        sfRenderWindow_close(intro.window);
        break;
    }
}

void end_events(radar_t intro)
{
    while (sfRenderWindow_pollEvent(intro.window, &intro.event)) {
        if (intro.event.type == sfEvtClosed)
            sfRenderWindow_close(intro.window);
        if (intro.event.type == sfEvtKeyReleased)
            end_key_events(intro);
    }
}

radar_t declared(void)
{
    char *n = "RADAR";
    radar_t box;

    box.font = sfFont_createFromFile("ress/Arialn.ttf");
    box.text = sfText_create();
    sfText_setFont(box.text, box.font);
    sfText_setCharacterSize(box.text, 50);
    box.pos2 = (sfVector2f){80000, 80000};
    box.sp = 1;
    box.gen = sfSprite_create();
    box.gen_text = sfTexture_createFromFile("ress/gen.png", NULL);
    sfSprite_setTexture(box.gen, box.gen_text, sfTrue);
    sfSprite_setPosition(box.gen, (sfVector2f){500, 0});
    box.mode = (sfVideoMode){1920, 1080, 32};
    box.window = sfRenderWindow_create(box.mode, n, sfResize | sfClose, NULL);
    box.rect_size = (sfVector2f){20, 20};
    box.time = 0;
    box.clock = sfClock_create();
    return box;
}

void destroy(radar_t box, Defense **t, Missil **p)
{
    destroy_tow_list(t);
    destroy_plane_list(p);
    sfSprite_destroy(box.map);
    sfClock_destroy(box.clock);
    sfRenderWindow_destroy(box.window);
}

radar_t start(radar_t box, Defense **t, Missil **p)
{
    box.elapsedTime = sfClock_getElapsedTime(box.clock);
    box.time = sfTime_asSeconds(box.elapsedTime);
    sfRenderWindow_drawSprite(box.window, box.map, NULL);
    box = disp_tow(box, t, box.time);
    box = disp_plane(box, p, box.time);
    Defense *def = *t;
    while (def) {
        Missil *en = *p;
        while (en) {
            if (def->id == en->id) {
                if (fabs(def->ac.y - en->ac.y) < 5) {
                    def->s = 0;
                    en->s = 0;
                }
            }
            en = en->next;
        }
        def = def->next;
    }
    return box;
}