/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf avec seulement certain parametre
*/

#include "include/my_struct.h"

int print_count_int(tab_param_t * param)
{
    int * i = va_arg(param->ap, int*);
    i[0] = param->count;
    return param->count;
}

int print_pointer(tab_param_t *param)
{
    int tot = 0;
    void* ptr = va_arg(param->ap, void *);
    long long int* addres = (long long int*)&ptr;
    my_putstr("0x");
    tot += 2;
    tot += my_putnbr_base(*addres, "0123456789abcdef");
    return tot;
}

int print_mod_nb(tab_param_t *param, int count)
{
    for (int i = 0; param->mod[i] != 0; i++) {
        count += param->mod[i] == '.' ? mod_print_char(param, count, '0') : 0;
        count += param->mod[i] == '0' ? mod_print_char(param, count, '0') : 0;
        if (param->mod[i] >= '0' && param->mod[i] <= '9' &&
            param->mod[i] == '-') {
            count += mod_print_char(param, count, ' ');
            break;
        }
    }
    return count;
}
