/*
** EPITECH PROJECT, 2019
** joris_file.h
** File description:
** LIB_Joris_2018
*/

#ifndef LIB_JORIS_2018_JORIS_FILE_H
#define LIB_JORIS_2018_JORIS_FILE_H

#include "json.h"

json_object *joris_file_create(const char *path);
json_object *joris_file_get(const char *path);
int joris_file_set(const char *path, json_object *json);

#endif // LIB_JORIS_2018_JORIS_FILE_H
