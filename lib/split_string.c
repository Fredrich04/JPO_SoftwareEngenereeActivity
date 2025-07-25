/*
** EPITECH PROJECT, 2024
** take_array
** File description:
** take_array
*/

#include "../include/my_radar.h"

int check_charac(char c)
{
    if ((c >= 48 && c <= 57)
        || (c >= 65 && c <= 90)
        || (c >= 97 && c <= 122) || c == '.')
        return 1;
    return 0;
}

int count_seperator(char const *str)
{
    int y = 0;
    int x = 0;

    while (str[x] != '\0') {
        if (check_charac(str[x]) == 0 && check_charac(str[x + 1]) == 1)
            y++;
        x++;
    }
    return y;
}

int count_column(char const *str)
{
    int y = 0;
    int z = 0;

    for (int x = 0; str[x] != '\0'; x++) {
        if (y > z)
            z = y;
        if (check_charac(str[x]) == 0) {
            y = 0;
            continue;
        }
        y++;
    }
    return z;
}

char **alloc_me_in_array(char const *str)
{
    int x = count_seperator(str);
    int y = count_column(str);
    char **s = malloc(sizeof(char *) * (x + 2));

    for (int a = 0; a < x + 2; a++)
        s[a] = malloc(sizeof(char) * (y + 1));
    return s;
}

char **split_string(char const *str)
{
    char **s = alloc_me_in_array(str);
    int a = 0;
    int b = 0;

    for (int i = 0; str[i]; i++) {
        if (check_charac(str[i]) == 0)
            continue;
        s[a][b] = str[i];
        b++;
        if (check_charac(str[i + 1]) == 0) {
            s[a][b] = '\0';
            a++;
            b = 0;
        }
    }
    s[a] = NULL;
    return s;
}
