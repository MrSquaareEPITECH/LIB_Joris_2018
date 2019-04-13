/*
** EPITECH PROJECT, 2019
** lib.h
** File description:
** LIB_MyJSONC_2018
*/

#ifndef LIB_MYJSONC_2018_LIB_H
#define LIB_MYJSONC_2018_LIB_H

int str_count(char *str, char chr);
char *str_cpy(char *str);
char *str_cpy_range(const char *str, int from, int to);
int str_len(const char *str);
char **str_split(char *str, char *list);

#endif // LIB_MYJSONC_2018_LIB_H
