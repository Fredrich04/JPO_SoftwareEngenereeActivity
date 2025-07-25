/*
** EPITECH PROJECT, 2024
** function_box2
** File description:
** function_box2
*/

#include "../include/my_printf.h"
#include "../include/my_radar.h"

void my_sterror(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        write(2, &str[a], 1);
}

int my_strlen(char const *str)
{
    int y = 0;

    for (int x = 0; str[x] != '\0'; x++) {
        y++;
    }
    return y;
}

char *my_revstr(char *str)
{
    int x = 0;
    int y = my_strlen(str) - 1;
    char c;

    while (x < y){
        c = str[x];
        str[x] = str[y];
        str[y] = c;
        x++;
        y--;
    }
    return str;
}

int error(double n, int c)
{
    if (isinf(n)) {
        my_print_str(c == 1 ? "inf" : "INF");
        return 0;
    }
    if (isnan(n)) {
        my_print_str(c == 1 ? "nan" : "NAN");
        return 0;
    }
    if (fabs(n) > 1e10) {
        my_print_str(c == 1 ? "error" : "ERROR");
        return 0;
    }
    return 1;
}

double my_print_float(double n, int c, int num)
{
    int x = n;
    double y = fabs(n - x);
    int z = y;

    if (error(n, c) == 0)
        return 0;
    my_print_int(x);
    my_print_char('.');
    for (int i = 0; i < num; i++) {
        y = y * 10;
        z = y;
        my_print_int(z);
        y = y - z;
    }
}
