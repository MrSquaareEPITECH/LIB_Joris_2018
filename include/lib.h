/*
** EPITECH PROJECT, 2019
** lib.h
** File description:
** LIB_Joris_2018
*/

#ifndef LIB_JORIS_2018_LIB_H
#define LIB_JORIS_2018_LIB_H

int str_count(char *str, char chr);
char *str_cpy(char *str);
char *str_cpy_range(const char *str, int from, int to);
int str_len(const char *str);
int str_len_list(char **list);
char **str_split(char *str, char *list);
void str_free_list(char **list);
int my_atoi(char const *tab);

#endif // LIB_JORIS_2018_LIB_H
