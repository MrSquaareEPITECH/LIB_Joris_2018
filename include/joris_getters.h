/*
** EPITECH PROJECT, 2019
** joris_getters.h
** File description:
** LIB_Joris_2018
*/

#ifndef LIB_JORIS_2018_JORIS_GETTERS_H
#define LIB_JORIS_2018_JORIS_GETTERS_H

#include "json.h"

array_list *joris_object_get_array(json_object *object, char *target);
double joris_object_get_double(json_object *object, char *target);
int joris_object_get_int(json_object *object, char *target);
json_object *joris_object_get_object(json_object *object, char **items);
char *joris_object_get_string(json_object *object, char *target);

#endif // LIB_JORIS_2018_JORIS_GETTERS_H
