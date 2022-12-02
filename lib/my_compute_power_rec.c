/*
** EPITECH PROJECT, 2022
** my compute power rec
** File description:
** met un nombre a sa puissance en recusrsive
*/

int my_compute_power_rec (int nb, int p)
{
    if (p == 0){
        return 1;
    }
    return (nb * my_compute_power_rec(nb,p - 1));
}
