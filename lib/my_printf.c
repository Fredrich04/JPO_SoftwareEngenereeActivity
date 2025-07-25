/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#include "../include/my_printf.h"

int my_printf(const char *format, ...)
{
    va_list ap;

    va_start(ap, format);
    for (int x = 0; format[x] != '\0'; x++) {
        if (format[x] != '%')
            my_print_char(format[x]);
        if (format[x] == '%') {
            specifier(format[x + 1], ap);
            x++;
        }
    }
    va_end(ap);
}
