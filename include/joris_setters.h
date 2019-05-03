/*
** EPITECH PROJECT, 2019
** joris_setters.h
** File description:
** LIB_Joris_2018
*/

#ifndef LIB_JORIS_2018_JORIS_SETTERS_H
#define LIB_JORIS_2018_JORIS_SETTERS_H

#include "json.h"
#include "joris_structs.h"

enum JORIS_ARRAY_TYPE {
    JORIS_ARR_DOUBLE = 1,
    JORIS_ARR_INT,
    JORIS_ARR_STR
};

void joris_object_set_array(json_object *object, char *target,
        char *value, int type);
void joris_object_set_array_double(json_object *object, char *value);
void joris_object_set_array_int(json_object *object, char *value);
void joris_object_set_array_string(json_object *object, char *value);
void joris_object_set_double(json_object *object, char *target, double value);
void joris_object_set_int(json_object *object, char *target, int value);
void joris_object_set_object(json_object *object, char *target);
void joris_object_set_string(json_object *object, char *target, char *value);

static const array_type_t ARRAY_TYPE[] = {
        {JORIS_ARR_DOUBLE, &joris_object_set_array_double},
        {JORIS_ARR_INT, &joris_object_set_array_int},
        {JORIS_ARR_STR, &joris_object_set_array_string},
        {0, NULL}
};

#endif // LIB_JORIS_2018_JORIS_SETTERS_H
