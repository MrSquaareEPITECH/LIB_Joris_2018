/*
** EPITECH PROJECT, 2019
** str_count.c
** File description:
** PSU_minishell2_2018
*/

#include "lib.h"

int str_count(char *str, char chr)
{
    int count = 0;
    int len = str_len(str);

    for (int i = 0; str && (i < len); ++i)
        count += (str[i] == chr) ? 1 : 0;
    return (count);
}