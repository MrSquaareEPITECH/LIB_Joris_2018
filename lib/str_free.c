/*
** EPITECH PROJECT, 2019
** str_free.c
** File description:
** PSU_minishell2_2018
*/

#include <stdlib.h>
#include "lib.h"

void str_free(char *str)
{
    if (str)
        free(str);
}

void str_free_list(char **list)
{
    for (int i = 0; list && (list[i] != NULL); ++i)
        str_free(list[i]);
    free(list);
}