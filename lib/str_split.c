/*
** EPITECH PROJECT, 2019
** str_split.c
** File description:
** LIB_MyJSONC_2018
*/

#include <stdlib.h>
#include "lib.h"

int str_split_words(char *str, char *list)
{
    int words = 0;

    if (str && list) {
        for (int i = 0; list[i] != '\0'; ++i)
            words += str_count(str, list[i]);
        words += (str[0] != '\0') ? 1 : 0;
    }
    return (words);
}

char **str_split(char *str, char *list)
{
    int words = str_split_words(str, list);
    char **array = malloc(sizeof(char *) * (words + 1));
    int from = 0;
    int to = 0;

    for (int i = 0; str && (i < words); ++i) {
        from = to;
        from += (str_count(list, str[from])) ? 1 : 0;
        for (to = from; !str_count(list, str[to]) && (str[to] != '\0'); ++to);
        array[i] = str_cpy_range(str, from, to);
    }
    array[words] = NULL;
    return (array);
}