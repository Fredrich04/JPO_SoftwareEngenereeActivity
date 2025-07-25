/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
  #define MY_PRINTF_H_

    #include <stdarg.h>
    #include <dirent.h>
    #include <stdint.h>

char *my_print_int_str(int nb);
char *my_int_in_str(int nb);
char *concat_strings(char *dest, char *src);
void my_sterror(char const *str);
int my_printf(const char *format, ...);
int error_case_ls(struct dirent *fd, DIR *dir, const char *p);
int my_ls(const char *path_name, char *option, int ac);
double my_print_exp2(double n);
double my_print_exp1(double c);
void specifier_n(int *p);
unsigned int my_print_unsigned_int(unsigned int nb);
void my_print_pointer(void *phr);
void make_base(unsigned long u);
void print_pointer_in_base(unsigned long u);
double my_print_float(double n, int c, int num);
int my_low_print_int_base(int nb, int b);
int specifier3(char spfr, va_list ap);
int specifier2(char spfr, va_list ap);
int specifier1(char spfr, va_list ap);
int specifier(char spfr, va_list ap);
char *my_strlowcase(char *str);
char *my_revstr(char *str);
int my_up_print_int_base(int nbr, int base);
int my_strlen(char const *str);
void my_print_str(char const *str);
void my_print_char(char c);
char *my_print_int_mod(int nb);
int my_print_int(int nb);

#endif
