/*
** EPITECH PROJECT, 2022
** my_put_nbr.c
** File description:
** affiche le nombre donnée
*/

#include<unistd.h>
#include "include/my_struct.h"

int my_put_nbr(int nb)
{
    if (nb == 0x80000000) {
        my_putstr("-2147483648");
        return 0;
    }
    if (nb < 0){
        my_putchar('-');
        return (my_put_nbr(-1 *nb));
    }
    if (nb <= 9){
        my_putchar(nb + '0');
        return 0;
    }
    my_put_nbr(nb / 10);
    my_putchar((nb % 10) + '0');
    return 0;
}
