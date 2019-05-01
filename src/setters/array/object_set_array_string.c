/*
** EPITECH PROJECT, 2018
** set_array_string.c
** File description:
** No description
*/

#include "json.h"
#include "joris_setters.h"
#include "my.h"

void joris_object_set_array_string(json_object *object, char *value)
{
    json_object *json_value = NULL;
    char **items = NULL;

    items = my_strsplit(value, ",");
    if (items) {
        for (int i = 0; items[i]; i++) {
            json_value = json_object_new_string(items[i]);
            json_object_array_add(object, json_value);
        }
    }
    my_arrfree((void **) items);
}