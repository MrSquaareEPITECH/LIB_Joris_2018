/*
** EPITECH PROJECT, 2019
** my_json.h
** File description:
** LIB_MyJSONC_2018
*/

#ifndef LIB_MYJSONC_2018_MY_JSON_H
#define LIB_MYJSONC_2018_MY_JSON_H

#include <json-c/json.h>

// Getters
json_object *get_object(json_object *json, char **array, int index);

// Loaders
json_object *json_load(char *path);

#endif //LIB_MYJSONC_2018_MY_JSON_H
