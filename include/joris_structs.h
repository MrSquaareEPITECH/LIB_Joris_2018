/*
** EPITECH PROJECT, 2018
** joris_structs.h
** File description:
** No description
*/

#ifndef LIB_JORIS_2018_JORIS_STRUCTS_H
#define LIB_JORIS_2018_JORIS_STRUCTS_H

#include "json.h"

typedef struct array_type_s {
    int type;
    void (*function)(json_object *obj, char *value);
} array_type_t;

#endif //LIB_JORIS_2018_JORIS_STRUCTS_H
