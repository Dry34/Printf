/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** struct miniprintf
*/

#ifndef B_CPE_101_MPL_1_1_MINIPRINTF_THOMAS_JANIAUT_STRUCT_H
    #define B_CPE_101_MPL_1_1_MINIPRINTF_THOMAS_JANIAUT_STRUCT_H

    #include <stdarg.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <limits.h>

typedef struct tab_param_s {
    const char * format;
    va_list ap;
    char * mod;
    int count;
} tab_param_t;

int my_putchar(char c);
int my_put_nbr(int nb);
int my_put_nbr_ll(long long int nb);
int my_putstr(char const *str);
int my_strlen (char const *str);
int my_showstr (char const * str,unsigned int count);
int print_ascii(char const * str, int count, int i,char * table);
int my_putnbr_base(long long int nb, char const *base);
int my_strcmp(char const * s1, char const * s2);
char * my_strcat(char *dest, char const * src);
int my_getnbr(char const *str);
int my_compute_power_rec (int nb, int p);
int nb_count(long long int nb);

void mem_set(tab_param_t * param, const char* format);
int mod_print_char(tab_param_t * param, int lenght, char c);
int print_with_precision (int precision, double nb, int i);
int print_mod_nb(tab_param_t* param, int count);
void print_error(tab_param_t* param, const char * format, int i);

int print_percent(tab_param_t *);
int print_int(tab_param_t*);
int print_char(tab_param_t*);
int print_binary(tab_param_t*);
int print_str(tab_param_t*);
int print_float_pow(tab_param_t* param);
int print_float_pow_other(tab_param_t * param, double nb);
int print_float_pow_null(tab_param_t * param, double nb);
int print_float(tab_param_t*);
int print_float_g(tab_param_t * param);
int print_float_g_inf_5(tab_param_t * param, double nb);
int my_printf ( const char * format , ...);
int print_noprintable(tab_param_t*);
int print_hexa_maj(tab_param_t*);
int print_hexa_min(tab_param_t*);
int print_octa(tab_param_t*);
int print_unsigned_int(tab_param_t*);
int print_int_ll(tab_param_t*);
int print_count_int(tab_param_t * param);
int print_pointer(tab_param_t *param);

typedef struct tab_fonction_s {
    char c;
    int (*ptrf)(tab_param_t*);
}tab_fonction_t;

#endif
