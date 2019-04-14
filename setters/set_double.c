/*
** EPITECH PROJECT, 2018
** set_double.c
** File description:
** No description
*/

#include <json.h>
#include "lib.h"
#include "my_jsonc.h"

void json_set_double(json_object *file, char *target, char *key, double value)
{
    char **args = NULL;
    json_object *json = NULL;

    if (target) {
        args = str_split(target, ".");
        json = json_get_object(file, args, 0);
        json_object_object_add(json, key, json_object_new_double(value));
        json_object_deep_copy(json, &file, json_c_shallow_copy_default);
    }
}