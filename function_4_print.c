/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf avec seulement certain parametre
*/

#include "include/my_struct.h"
#include <stdarg.h>

int print_int_ll(tab_param_t * param)
{
    long long int nb = va_arg(param->ap, long long int);
    int count = 0;
    long long int nb_print = nb;
    if (nb < 0) {
        count++;
        nb = -nb;
    }
    while (nb > 9){
        nb = nb / 10;
        count++;
    }
    for (int i = 0; param->mod[i] != 0; i++) {
        if (param->mod[i] == '.')
            mod_print_char(param, count + 1, '0');
    }
    my_put_nbr_ll(nb_print);
    return (count + 1);
}

int mod_print_char(tab_param_t * param, int lo, char c)
{
    int nb = my_getnbr(param->mod);
    nb = nb < 0 ? -nb : nb;
    nb = nb - (lo + 1);
    int count;
    for (int i = 0; i < nb; i++) {
        my_putchar(c);
        count++;
    }
    return count;
}

int nb_count(long long int nb)
{
    int count = 0;
    if (nb < 0) {
        count++;
        nb = -nb;
    }
    while (nb > 9){
        nb = nb / 10;
        count++;
    }
    return count;
}

int print_with_precision ( int precision, double nb, int i)
{
    int count = 0;

    for (int p = 0; p < precision; p++) {
        nb = nb * 10;
        i = nb;
        count += my_putchar(i + '0');
        nb = nb - i;
    }
    return count;
}
