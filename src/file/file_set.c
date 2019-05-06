/*
** EPITECH PROJECT, 2019
** file_set.c
** File description:
** LIB_Joris_2018
*/

#include <fcntl.h>
#include <unistd.h>
#include "json.h"
#include "joris_file.h"

int joris_file_set(const char *path, json_object *json)
{
    int code = 0;

    code = json_object_to_file_ext(path, json, JSON_C_TO_STRING_PRETTY);
    return (code);
}