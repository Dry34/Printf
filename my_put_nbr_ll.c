/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** affiche le nombre donnée
*/

#include<unistd.h>
#include "include/my_struct.h"

int my_put_nbr_ll(long long int nb)
{
    if (nb == LLONG_MIN) {
        my_putstr("-9223372036854775808");
        return 0;
    }
    if (nb < 0){
        my_putchar('-');
        return (my_put_nbr_ll(-1 *nb));
    }
    if (nb <= 9){
        my_putchar(nb + '0');
        return 0;
    }
    my_put_nbr_ll(nb / 10);
    my_putchar((nb % 10) + '0');
    return 0;
}
