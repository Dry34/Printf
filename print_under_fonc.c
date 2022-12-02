/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf
*/
#include "include/my_struct.h"

void mem_set(tab_param_t * param, const char* format)
{
    for (int c = 0; format[c] != 0; c++){
        param ->mod[c] = '\0';
    }
}

void print_error(tab_param_t* param, const char * format,int i)
{
    my_putstr(param->mod);
    my_putchar(format[i + my_strlen(param->mod)]);
}
