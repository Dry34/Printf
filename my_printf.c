/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf
*/

#include"include/my_struct.h"
#include <stdarg.h>
#include <stdlib.h>

tab_fonction_t tab_struct_f[] = {
        {'%', print_percent},
        {'d', print_int},
        {'i', print_int},
        {'c', print_char},
        {'s', print_str},
        {'f', print_float},
        {'F', print_float},
        {'S', print_noprintable},
        {'X', print_hexa_maj},
        {'x', print_hexa_min},
        {'b', print_binary},
        {'o', print_octa},
        {'u', print_unsigned_int},
        {'n', print_count_int},
        {'p', print_pointer},
        {'e', print_float_pow},
        {'E', print_float},
        {'g', print_float_g},
        {'G', print_float_g},
        {0, 0}
};

int travel_tab(const char * format, tab_fonction_t * tab_struct_f, int i, int j)
{
    char * lenght_mod = "hlLjzt-+ .#0123456789";

    for (int l = 0; lenght_mod[l] != 0; l++) {
        if (format[i + j + 1] == lenght_mod[l])
            return 2;
    }

    for (int k = 0; tab_struct_f[k].c != 0; k++){
        if (format[i + j + 1] == tab_struct_f[k].c)
            return 1;
    }
    return 0;
}

int p_par_param(tab_fonction_t *tab_struct_f, int* tab_in,
                tab_param_t *param, const char * format)
{
    int ret_tab;
    int j = 0;
    do {
        ret_tab = travel_tab(format, tab_struct_f, tab_in[0], j);
        param->mod[j] = format[tab_in[0] + j];
        j++;
    } while (ret_tab == 2);
    if (ret_tab == 0) {
        print_error(param, format,tab_in[0]);
        return -tab_in[1];
    }
    for ( int k = 0; tab_struct_f[k].c != 0; k++) {
        if (format[tab_in[0] + j] == tab_struct_f[k].c)
            tab_in[1] = tab_struct_f[k].ptrf(param);
        if (tab_in[1] < 0){
            print_error(param, format,tab_in[0]);
            return -tab_in[1];
        }
    }
    return tab_in[1];
}

int print_sentence(const char * format, tab_param_t *param)
{
    int tab_in[5] = {0, param->count, 0, 0, 0};
    param->mod = malloc((sizeof(const char) *my_strlen(format)));
    mem_set(param, format);

    for (int i = 0; format[i] != 0; i++){
        if (format[i] == '%') {
            tab_in[0] = i; tab_in[1] = param->count;
            tab_in[3] = p_par_param(tab_struct_f, tab_in, param, format);
            tab_in[4] = tab_in[3] < 0 ? tab_in[3] : 0;
            param->count = param->count + tab_in[3];
            i += my_strlen(param->mod);
            mem_set(param, format);
        } else {
            my_putchar(format[i]);
            param->count++;
        }
    }
    param->count = tab_in[4] < 0 ? tab_in[4] : param->count;
    return param->count;
}

int my_printf ( const char * format , ...)
{
    tab_param_t param;
    va_start(param.ap, format);
    param.format = format;
    param.count = 0;

    param.count = print_sentence(format, &param);

    free(param.mod);
    va_end(param.ap);

    if (param.count < 0)
        return 84;
    return param.count;
}
