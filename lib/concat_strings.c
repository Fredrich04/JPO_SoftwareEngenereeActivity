/*
** EPITECH PROJECT, 2024
** concat_strings
** File description:
** concat_strings
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../include/my_printf.h"

char *concat_strings(char *dest, char *src)
{
    int i = 0;
    int j = my_strlen(dest) + 1;

    for (i = 0; src[i] != '\0'; i++)
        dest[j + i] = src[i];
    dest[j + i] = '\0';
    return dest;
}
