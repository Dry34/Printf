/*
** EPITECH PROJECT, 2022
** my getnbr
** File description:
** recupere le  premier nombre d'une chaine
*/

#include <unistd.h>
#include "include/my_struct.h"

int test_min(char const *str, int i, int n)
{
    if (str[i] == '-'){
        n++;
    }else if (str[i] != '-' && str[i] != '+'){
        n = 0;
    }
    return n;
}

int check(int nbr, char const *str, int i, int n)
{
    if (n % 2 != 0){
        if (nbr == 214748364 && (str[i]) == '8'){
            int neg = -2147483648;
            return neg;
        }
    }
    return nbr;
}

int my_getnbr(char const *str)
{
    int i = 0;
    int n = 0;
    int nbr = 0;

    if (*str == 0) return 0;
    while (!(str[i] - '0' >= 0 && str[i] - '0' <= 9)){
        n = test_min(str, i, n);
        i++;
    }
    while (str[i] - '0' >= 0 && str[i] - '0' <= 9){
        int p = check(nbr,str ,i ,n);
        if (p < 0) return p;
        nbr = nbr * 10 + (str[i] - '0');
        if (nbr < 0) return 0;
        i++;
    }
    if (n % 2 != 0) nbr = -nbr;
    return nbr;
}
