/*
** EPITECH PROJECT, 2019
** str_cpy.c
** File description:
** PSU_minishell2_2018
*/

#include <stdlib.h>
#include "lib.h"

char *str_cpy(char *str)
{
    char *cpy = NULL;
    int len = str_len(str);

    if (str) {
        cpy = malloc(sizeof(char) * (len + 1));
        for (int i = 0; i < len; ++i)
            cpy[i] = str[i];
        cpy[len] = '\0';
    }
    return (cpy);
}

char *str_cpy_range(const char *str, int from, int to)
{
    char *cpy = NULL;
    int len = to - from;

    if (str) {
        cpy = malloc(sizeof(char) * (len + 1));
        for (int i = 0, j = from; j < to; ++i, ++j)
            cpy[i] = str[j];
        cpy[len] = '\0';
    }
    return (cpy);
}