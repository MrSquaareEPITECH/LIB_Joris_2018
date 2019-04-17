/*
** EPITECH PROJECT, 2018
** set_array_int.c
** File description:
** No description
*/

#include <json.h>
#include <joris.h>
#include <lib.h>

void joris_object_set_array_int(char *value, json_object *child)
{
    json_object *json_value = NULL;
    char **items = NULL;
    int val = 0;

    items = str_split(value, ",");
    if (items) {
        for (int i = 0; items[i]; i++) {
            val = my_atoi(items[i]);
            json_value = json_object_new_int(val);
            json_object_array_add(child, json_value);
        }
    }
}