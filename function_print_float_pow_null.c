/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf avec seulement certain parametre
*/

#include "include/my_struct.h"

int print_float_pow_compte(double nb, long long int result, int tab_intpow);
int print_float_pow_scic(double *nb, long long int *result, int tab_intpow);
double print_float_pow_infe(double *nb, int tab_intpow);

int print_float_pow_null(tab_param_t * param, double nb)
{
    int tab_intpow[2] = {0,0};
    tab_intpow[0] = print_float_pow_infe(&nb, tab_intpow[0]);
    long long int result = nb;
    tab_intpow[1] += print_float_pow_scic(&nb, &result, tab_intpow[1]);
    tab_intpow[0] += 2;
    nb = nb - result;
    result = 0;
    tab_intpow[0] += print_float_pow_compte(nb, result, tab_intpow[0]);
    my_putstr("e-");
    tab_intpow[0] = tab_intpow[0] + 2;
    tab_intpow[1] < 10 ? my_putchar('0') : 0;
    my_put_nbr(tab_intpow[1]);
    tab_intpow[0] = tab_intpow[0] + 2;
    return tab_intpow[0];
}

int print_float_pow_compte(double nb, long long int result, int tab_intpow)
{
    int tot = 0;
    int approx = my_compute_power_rec(10, 6);
    for (int p = 0; p < 7; p++){
        nb = nb * 10;
        tot = tot * 10 + result;
        result = nb;
        nb = nb - result;
        tab_intpow++;
    }
    if (tot % 10 >= 5)
        tot += 1;
    my_put_nbr(tot);
    return tab_intpow;
}

int print_float_pow_scic(double *nb, long long int *result, int tab_intpow)
{
    while (*result * 10 == 0) {
        *nb = *nb * 10;
        *result = *nb;
        tab_intpow++;
    }
    *result = *nb;
    my_put_nbr(*result);
    my_putchar('.');
    return tab_intpow;
}

double print_float_pow_infe(double *nb, int tab_intpow)
{
    if (*nb < 0){
        my_putchar('-');
        *nb = *nb * -1;
        tab_intpow++;
    }
    return tab_intpow;
}
