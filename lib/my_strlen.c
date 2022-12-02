/*
** EPITECH PROJECT, 2022
** my strlen
** File description:
** donne le nombre de caractere d'une chaine
*/

void my_putchar(char c);

int my_strlen (char const *str)
{
    int r = 0;
    for (int i = 0; str[i] != 0; i++){
        r++;
    }
    return r;
}
