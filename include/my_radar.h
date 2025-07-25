/*
** EPITECH PROJECT, 2024
** my_hunter
** File description:
** my_hunter
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef MY_RADAR_H_
  #define MY_RADAR_H_

    #define DELAY 0.1
    #define COLLISION 10
    #define STORY "Congratulations!!\nA step for the E-vengers in\nthe liberation of the digital world"

    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <string.h>
    #include <math.h>
    #include "../include/my_printf.h"
    #include <sys/stat.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>

typedef struct radar_t {
    sfRenderWindow *window;
    sfVector2f rect_size;
    char *s;
    int time;
    sfFont *font;
    sfText *text;
    sfSprite *sprite, *gen;
    sfVideoMode mode;
    sfRectangleShape *rectangle;
    sfSprite *map;
    sfVector2f pos;
    sfVector2f pos2;
    float frameTime;
    sfTime elapsedTime;
    sfClock *clock;
    sfTexture *map_text, *gen_text;
    sfEvent event;
    //animated_text_t *anim;
    int sp;
} radar_t;

typedef struct {
    sfText *text;
    char *full_string;
    size_t index;
    sfClock *clock;
    float delay;
} animated_text_t;

typedef struct Missil {
    sfVector2f ai;
    sfVector2f af;
    sfVector2f ac;
    float va;
    float d;
    int rev;
    sfRectangleShape *rectangle;
    sfTexture *Missilext;
    sfSprite *plane;
    float angle;
    float total_angle;
    sfVector2f center;
    sfFloatRect bounds;
    float radius;
    int id, s;
    struct Missil *next;
} Missil;

typedef struct Defense {
    sfVector2f ai, ac, af;
    sfSprite *tower;
    sfCircleShape *circle;
    sfTexture *tower_text;
    sfFloatRect bounds;
    struct Defense *next;
    int id, s;
} Defense;

typedef struct explosion_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    float frame_duration;
    int total_frames;
    int current_frame;
    int is_active;
} explosion_t;

radar_t sound(radar_t box, Missil *plane);
radar_t pix_map(radar_t box, int x, Defense **t);
radar_t up_time_find(radar_t box);
int to_number(char const *str);
void add_plane2(Missil *plane, char **s, int x);
void destroy_plane_list(Missil **p);
void destroy_tow_list(Defense **t);
radar_t disp_plane(radar_t box, Missil **p, float);
radar_t mouvment_manager(radar_t box, Missil *plane, float);
radar_t disp_tow(radar_t box, Defense **t, float);
radar_t make_tower(char *jp, radar_t box, Defense *tower);
radar_t make_map(char *jp, radar_t box);
radar_t make_plane(char *jp, radar_t box);
radar_t start(radar_t box, Defense **t, Missil **p);
radar_t make_tower_area(radar_t box, Defense *t);
radar_t make_plane_hitbox(radar_t box, Missil *p);
int radar(Defense **l, Missil **p);
void display(radar_t box);
int my_strcmp(char const *s1, char const *s2);
int my_str_true_cmp(char *s1, char *s2);
radar_t tow_ma(Defense *tow, radar_t box);
radar_t make_sprite(char *jp, radar_t box);
radar_t analyse_events(radar_t box, Defense **t, Missil **p);
int read_file(Defense **l, Missil **p);
char **split_string(char const *str);
void disp2(Missil *p);
void disp1(Defense *l);
radar_t declared(void);
void end_events(radar_t intro);
void end_key_events(radar_t intro);
animated_text_t *create_animated_text(const char *str, radar_t intro, int size, sfVector2f pos);
void typing_animation(animated_text_t *anim);
void draw_animated_text(sfRenderWindow *window, animated_text_t *anim);
void destroy(radar_t box, Defense **t, Missil **p);



 #define INIT_SIMULATION(t, p, box_ptr)                 \
    read_file(t, p);                                   \
    *(box_ptr) = declared();                           \
    if (!(box_ptr)->window)                            \
        return 84;                                     \
    *(box_ptr) = make_map("ress/map.jpg", *(box_ptr)); \
    sfClock_restart((box_ptr)->clock);


#define MAIN_LOOP(box_ptr, t, p)                              \
    while (sfRenderWindow_isOpen((box_ptr)->window)) {        \
        end_events(*(box_ptr));                               \
        sfRenderWindow_clear((box_ptr)->window, sfBlack);     \
        *(box_ptr) = start(*(box_ptr), t, p);                 \
        display(*(box_ptr));                                  \
        Missil *en = *p;                                      \
        int i = 0;                                            \
        while (en) {                                          \
            if (en->s == 0)                                   \
                i++;                                          \
            en = en->next;                                    \
        }                                                     \
        if (i == 5)                                           \
            break;                                            \
    }

#define SETUP_ANIMATION(anim, box_ptr)                                       \
    sfClock_restart((box_ptr)->clock);                                      \
    anim = create_animated_text(STORY, *(box_ptr), 50, (sfVector2f){100, 100});


#define PLAY_SUCCESS_MUSIC(win)                        \
    do {                                               \
        win = sfMusic_createFromFile("ress/succes.mp3");\
        sfMusic_play(win);                             \
    } while (0)

#define DISPLAY_ANIMATED_TEXT_LOOP(box, anim, t, p)    \
    do {                                               \
        while (sfRenderWindow_isOpen(box.window)) {    \
            box = analyse_events(box, t, p);           \
            sfRenderWindow_clear(box.window, sfBlack); \
            sfRenderWindow_drawSprite(box.window, box.map, NULL); \
            sfRenderWindow_drawSprite(box.window, box.gen, NULL); \
            typing_animation(anim);                    \
            draw_animated_text(box.window, anim);      \
            display(box);                              \
        }                                              \
    } while (0)

#define CLEANUP(box, t, p)                             \
    do {                                               \
        destroy(box, t, p);                            \
    } while (0)

#define CHECK_SIMULATION_END(p, should_break)          \
    do {                                               \
        Missil *en = *(p);                             \
        int count = 0;                                 \
        while (en) {                                   \
            if (en->s == 0)                            \
                count++;                               \
            en = en->next;                             \
        }                                              \
        if (count == 5)                                \
            should_break = 1;                          \
    } while (0)

#define DRAW_ALL(box)                                  \
    do {                                               \
        sfRenderWindow_drawSprite(box.window, box.map, NULL); \
        sfRenderWindow_drawSprite(box.window, box.gen, NULL); \
        display(box);                                  \
    } while (0)

#endif















/*
INIT_SIMULATION(t, p, box_ptr);
MAIN_LOOP(box_ptr, t, p);
SETUP_ANIMATION(anim, box_ptr);
PLAY_SUCCESS_MUSIC(win);
DISPLAY_ANIMATED_TEXT_LOOP(box, anim, t, p);
CLEANUP(box, t, p);
*/














