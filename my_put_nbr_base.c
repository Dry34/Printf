/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** affiche le nombre donnée
*/

#include "include/my_struct.h"
#include<stdio.h>

int my_putnbr_base(long long int nb, char const *base)
{
    int test = 0;
    int count = 0;
    test = my_strlen(base);
    if (nb == 0x80000000) {
        my_putstr("-2147483648");
        return 11;
    }
    if (nb < 0){
        count += my_putchar('-');
        count += my_putnbr_base(-nb, base);
    }
    if (nb < test) {
        count += my_putchar(base[nb % test]);
        return count;
    } else {
    count += my_putnbr_base((nb / test), base);
    my_putchar(base[nb % test]);
    count++;
    return count;
    }
}
