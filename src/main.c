/*
** EPITECH PROJECT, 2024
** main
** File description:
** main
*/

#include "../include/my_radar.h"
#include "../include/my_printf.h"

const char *end_5x5[] = {
    " #####  ####  #   #  #####   ####   ####  ##### #    # #      ####  ##### #####  ####  #   #  ##",
    "#      #    # ##  # #       #    # #    #   #   #    # #     #    #   #     #   #    # ##  #  ##",
    "#      #    # # # # #   ### #####  ######   #   #    # #     ######   #     #   #    # # # #  ##",
    "#      #    # #  ## #     # #   #  #    #   #   #    # #     #    #   #     #   #    # #  ##    ",
    " #####  ####  #   #  #####  #    # #    #   #    ####  ##### #    #   #   #####  ####  #   #  ##"
};

int radar(Defense **t, Missil **p) 
{
    radar_t box;
    radar_t *box_ptr = &box;
    animated_text_t *anim; 
    sfMusic *win;

    // A ordonner
    INIT_SIMULATION(t, p, box_ptr);
    MAIN_LOOP(box_ptr, t, p);
    SETUP_ANIMATION(anim, box_ptr, win);
    DISPLAY_ANIMATED_TEXT_LOOP(box, anim, t, p);
    CLEANUP(box, t, p, win, anim);
    
    
    return 0;
}

int main(int ac, char **av)
{
    Defense *l = NULL;
    Missil *p = NULL;

    radar(&l, &p);
    printf("\n");
    for (int i = 0; i < 5; i++) {
        printf("%s\n", end_5x5[i]);
    }
    printf("\n");
    return 0;
}
