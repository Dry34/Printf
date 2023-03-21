/*
** EPITECH PROJECT, 2022
** show str
** File description:
** ecrit une chaine de carac en hexa
*/
#include "include/my_struct.h"
#include <stdio.h>

int my_showstr (char const * str, unsigned int count)
{
    char * table = "01234567";
    if (*str == 0)
        return count;
    if (*str >= 32 && *str <= 126){
        my_putchar(*str++);
        count = count + 1;
    }else{
        int i = *str;
        my_putchar('\\');
        if (i < 8)
            my_putstr("00");
        if (i >= 8 && i != 127)
            my_putchar('0');
        my_putnbr_base(i, table);
        count = count + 4;
        str++;
    }
    return my_showstr(str, count);
}
