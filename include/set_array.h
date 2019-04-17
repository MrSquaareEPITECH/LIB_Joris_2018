/*
** EPITECH PROJECT, 2018
** set_array.h
** File description:
** No description
*/

#ifndef LIB_JORIS_2018_SET_ARRAY_H
#define LIB_JORIS_2018_SET_ARRAY_H

#include <json.h>

typedef struct array_type_s {
    char *type;
    void (*function)(char *value, json_object *child);
} array_type_t;

#endif //LIB_JORIS_2018_SET_ARRAY_H
