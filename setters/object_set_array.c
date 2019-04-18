/*
** EPITECH PROJECT, 2019
** object_set_array.c
** File description:
** LIB_Joris_2018
*/

#include <json.h>
#include <string.h>
#include "joris.h"
#include "set_array.h"
#include "my.h"

void add_values(char *type, char *value, json_object *child)
{
    for (int i = 0; array_type[i].type; i++)
        if (strcmp(type, array_type[i].type) == 0)
            array_type[i].function(value, child);
}

void joris_object_set_array(json_object *file, char *target, char *type, char
*value)
{
    char **items = NULL;
    int len = 0;
    char *key = NULL;
    json_object *parent = NULL;
    json_object *child = NULL;

    if (target) {
        items = my_strsplit(target, ".");
        len = my_arrlen((void **) items);
        key = items[len - 1];
        items[len - 1] = NULL;
        parent = joris_object_get_object(file, items);
        if (parent) {
            child = json_object_new_array();
            json_object_object_add(parent, key, child);
            add_values(type, value, child);
        }
        items[len - 1] = key;
        my_arrfree((void **) items);
    }
}