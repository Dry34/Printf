/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf avec seulement certain parametre
*/

#include "include/my_struct.h"

int print_binary(tab_param_t * param)
{
    char table[] = "01";
    int nb = va_arg(param->ap, int);
    int count = 0;
    count = my_putnbr_base(nb, table);
    return count;
}

int print_float_pow(tab_param_t * param)
{
    double nb = va_arg(param->ap,double);
    int verif = nb;
    int count = 0;
    if (verif == 0)
        count = print_float_pow_null(param, nb);
    else
        count = print_float_pow_other(param, nb);
    return count;
}

int print_float_g(tab_param_t * param)
{
    double nb = va_arg(param->ap,double);
    int result = nb;
    int count = nb_count(result);
    if (count <= 5 && result != 0) {
        count = print_float_g_inf_5(param, nb);
    } else {
        if (result == 0) {
            my_putstr("0.");
            count = print_with_precision(6, nb, 0);
        } else {
            count = print_float_pow_other(param, nb);
        }
    }
    return count;
}

int print_float_g_inf_5(tab_param_t * param, double nb)
{
    int compteur = 0;
    int result = nb;
    int decimal = 0;
    int temp = nb_count(result);
    if (nb_count(result) <= 6) {
        my_put_nbr(result);
    } else {
        my_put_nbr(result);
        my_putchar('.');
        nb = nb - result;
        for (int p = 0; p < (nb + 3) ; p++){
            nb = nb * 10;
            decimal = decimal * 10 + nb;
            nb = nb - decimal % 10;
        }
        my_put_nbr(decimal);
    }

}
