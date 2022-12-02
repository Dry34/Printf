/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** printf avec seulement certain parametre
*/

#include "include/my_struct.h"

int print_noprintable(tab_param_t * param)
{
    unsigned int count = 0 ;
    const char * c = va_arg(param->ap, char *);
    count = my_showstr(c, count);
    return count;
}

int print_hexa_maj(tab_param_t * param)
{
    unsigned int nb = va_arg(param->ap, unsigned int);
    int count = 0;
    char  table[] = "0123456789ABCDEF";
    for (int i = 0; param->mod[i] != 0; i++) {
        if (param->mod[i] == '#' && nb != 0)
            my_putstr("0X");
    }
    count = my_putnbr_base(nb, table);
    return count;
}

int print_hexa_min(tab_param_t * param)
{
    unsigned int nb = va_arg(param->ap, unsigned int);
    int count = 0;
    char  table[] = "0123456789abcdef";
    for (int i = 0; param->mod[i] != 0; i++) {
        if (param->mod[i] == '#' && nb != 0)
            my_putstr("0x");
    }
    count = my_putnbr_base(nb, table);
    return count;
}

int print_octa(tab_param_t * param)
{
    unsigned int nb = va_arg(param->ap, unsigned int);
    int count = 0;
    char  table[] = "01234567";
    for (int i = 0; param->mod[i] != 0;i++){
        if (param->mod[i] == '#' && nb != 0)
            count += my_putchar('0');
    }
    for (;nb / 8 != 0; count++)
        nb = nb / 8;
    print_mod_nb(param, count);
    count = my_putnbr_base(nb, table);
    for (int j = 0; param->mod[j] != 0;j++) {
        count += param->mod[j] == '-' ? mod_print_char(param, count, ' ') : 0;
    }
    return count;
}

int print_unsigned_int(tab_param_t * param)
{
    unsigned int nb = va_arg(param->ap, unsigned int);
    int count = 0;
    char  table[] = "0123456789";
    count = my_putnbr_base(nb, table);
    return count;
}
