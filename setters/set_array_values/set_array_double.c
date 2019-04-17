/*
** EPITECH PROJECT, 2018
** set_array_double.c
** File description:
** No description
*/

#include <json.h>
#include <joris.h>
#include <lib.h>

void set_array_double(char *value, json_object *child)
{
    json_object *json_value = NULL;
    char **items = NULL;
    double val = 0;

    items = str_split(value, ",");
    if (items) {
        for (int i = 0; items[i]; i++) {
            val = atof(items[i]);
            json_value = json_object_new_double(val);
            json_object_array_add(child, json_value);
        }
    }
}