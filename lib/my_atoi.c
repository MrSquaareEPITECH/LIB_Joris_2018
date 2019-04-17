/*
** EPITECH PROJECT, 2018
** my_atoi
** File description:
** my_atoi
*/

int my_atoi(char const *tab)
{
    int pows = 1;
    int raws = 0;
    int j = 0;

    for (int i = 0; tab[i] >= '0' && tab[i] <= '9'; i++)
        pows = pows * 10;
    pows = pows / 10;
    for (j = 0; tab[j] >= '0' && tab[j] <= '9'; j++) {
        raws = raws + (tab[j] - 48) * pows;
        pows = pows / 10;
    }
    return (raws);
}