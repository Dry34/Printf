/*
** EPITECH PROJECT, 2022
** my_putstr.c
** File description:
** affiche une suite de caractere
*/

void my_putchar(char c);

int my_putstr (char const *str)
{
    int count = 0;
    for (int i = 0; str[i] != 0; i++){
        my_putchar(str[i]);
        count++;
    }
    return count;
}
