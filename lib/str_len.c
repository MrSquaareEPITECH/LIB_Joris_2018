/*
** EPITECH PROJECT, 2019
** str_len.c
** File description:
** PSU_minishell2_2018
*/

#include <stdlib.h>
#include "lib.h"

int str_len(const char *str)
{
    int len = 0;

    for (len = 0; str && (str[len] != '\0'); ++len) ;
    return (len);
}