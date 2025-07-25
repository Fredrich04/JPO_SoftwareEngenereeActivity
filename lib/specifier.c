/*
** EPITECH PROJECT, 2024
** specifier.c
** File description:
** specifier
*/

#include "../include/my_printf.h"

int specifier1(char spfr, va_list ap)
{
    switch (spfr) {
        case '%':
            my_print_char('%');
            break;
        case 'c':
            my_print_char(va_arg(ap, int));
            break;
        case 's':
            my_print_str(va_arg(ap, char *));
            break;
        case 'i':
        case 'd':
            my_print_int(va_arg(ap, int));
            break;
    }
}

int specifier2(char spfr, va_list ap)
{
    switch (spfr) {
        case 'o':
            my_up_print_int_base(va_arg(ap, int), 8);
            break;
        case 'b':
            my_up_print_int_base(va_arg(ap, int), 2);
            break;
        case 'x':
            my_low_print_int_base(va_arg(ap, int), 16);
            break;
        case 'X':
            my_up_print_int_base(va_arg(ap, int), 16);
            break;
    }
}

int specifier(char spfr, va_list ap)
{
    specifier1(spfr, ap);
    specifier2(spfr, ap);
}
