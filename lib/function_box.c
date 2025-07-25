/*
** EPITECH PROJECT, 2024
** function_box
** File description:
** function_box
*/

#include "../include/my_printf.h"
#include "../include/my_radar.h"

void my_print_str(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_print_char(str[a]);
}

void my_print_char(char c)
{
    write(1, &c, 1);
}

int my_print_int(int nb)
{
    if (nb >= 0 && nb < 10) {
        my_print_char(nb + '0');
    } else if (nb < 0) {
        my_print_char('-');
        my_print_int(nb = nb * (-1));
    } else {
        my_print_int(nb / 10);
        my_print_int(nb % 10);
    }
}

int my_low_print_int_base(int nb, int b)
{
    char buff[100];
    char lettre[] = "0123456789abcdefghijklmnopqrstuvwxyz";
    int n = 0;
    int x = 0;

    while (nb != 0) {
        n = nb % b;
        buff[x] = lettre[n];
        x++;
        nb = nb / b;
    }
    my_revstr(buff);
    my_print_str(buff);
}

int my_up_print_int_base(int nb, int b)
{
    char buff[100];
    char lettre[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = 0;
    int x = 0;

    while (nb != 0) {
        n = nb % b;
        buff[x] = lettre[n];
        x++;
        nb = nb / b;
    }
    my_revstr(buff);
    my_print_str(buff);
}
