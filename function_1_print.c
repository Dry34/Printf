/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf avec seulement certain parametre
*/

#include "include/my_struct.h"

#include <stdarg.h>

int print_percent(tab_param_t * param)
{
    my_putchar('%');
    return 1;
}

int print_int(tab_param_t * param)
{
    int count = 0;
    int nb = 0;
    int test = 0;

    for (int i = 0; param->mod[i] != 0; i++) {
        if (param->mod[i] == 'l') {
            count = print_int_ll(param);
            return count;
        }
    }
    nb = va_arg(param->ap, int);
    int nb_print = nb;
    count = nb_count(nb);
    print_mod_nb(param, count);
    my_put_nbr(nb_print);

    for (int j = 0; param->mod[j] != 0;j++) {
        count += param->mod[j] == '-' ? mod_print_char(param, count, ' ') : 0;
    }
    return (count + 1);
}

int print_char(tab_param_t * param)
{
    char c = (char)va_arg(param->ap, int);
    my_putchar(c);
    return 1;
}

int print_str(tab_param_t * param)
{
    char * str = va_arg(param->ap, char*);
    int c = my_putstr(str);
    return c;
}

int print_float(tab_param_t * param)
{
    double nb = va_arg(param->ap, double);
    int i = nb;
    int precision = 6;
    int count = 0;
    my_put_nbr(i);
    for (int c = nb; c > 9; count++)
        c = c / 10;
    count++;
    for (int i = 0; param->mod[i] != 0; i++) {
        if (param->mod[i] == '.')
            precision = my_getnbr(param->mod);
    }
    nb = nb - i;
    count += my_putchar('.');
    long int approx = my_compute_power_rec(10, precision);
    nb = nb + (1 / approx);
    count += print_with_precision(precision, nb, i);
    return count;
}
