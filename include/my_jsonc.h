/*
** EPITECH PROJECT, 2019
** my_json.h
** File description:
** LIB_MyJSONC_2018
*/

#ifndef LIB_MYJSONC_2018_MY_JSON_H
#define LIB_MYJSONC_2018_MY_JSON_H

#include <json_object.h>

// Getters
void **json_get_array(json_object *file, char *target);
double json_get_double(json_object *file, char *target);
int json_get_int(json_object *file, char *target);
json_object *json_get_object(json_object *json, char **array, int index);
char *json_get_string(json_object *file, char *target);

// File
void json_create(char *filepath, json_object *file);
json_object *json_load(char *path);

// Setters
void json_set_int(json_object *file, char *target, char *key, int value);
void json_set_double(json_object *file, char *target, char *key, double value);
void json_set_array(json_object *file, char *target, char *key);
void json_set_string(json_object *file, char *target, char *key, const char
*string);

#endif //LIB_MYJSONC_2018_MY_JSON_H
