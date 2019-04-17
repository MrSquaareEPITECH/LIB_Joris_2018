/*
** EPITECH PROJECT, 2019
** joris.h
** File description:
** LIB_Joris_2018
*/

#ifndef LIB_JORIS_2018_JORIS_H
#define LIB_JORIS_2018_JORIS_H

#include <json.h>
#include "set_array.h"

// File
json_object *joris_file_create(char *path);
json_object *joris_file_get(char *path);
void joris_file_set(char *path, json_object *json);

// Getters
array_list *joris_object_get_array(json_object *file, char *target);
double joris_object_get_double(json_object *file, char *target);
int joris_object_get_int(json_object *file, char *target);
json_object *joris_object_get_object(json_object *json, char **items);
char *joris_object_get_string(json_object *file, char *target);

// Setters
void joris_object_set_array(json_object *file, char *target, char *type, char
*value);
void joris_object_set_double(json_object *file, char *target, double value);
void joris_object_set_int(json_object *file, char *target, int value);
void joris_object_set_object(json_object *file, char *target);
void joris_object_set_string(json_object *file, char *target, char *value);
void joris_object_set_array_double(char *value, json_object *child);
void joris_object_set_array_int(char *value, json_object *child);
void joris_object_set_array_string(char *value, json_object *child);

static const array_type_t array_type[] = {
        {"double", &joris_object_set_array_double},
        {"int", &joris_object_set_array_int},
        {"string", &joris_object_set_array_string},
        {NULL, NULL}
};

#endif // LIB_JORIS_2018_JORIS_H
