/*
** EPITECH PROJECT, 2019
** object_set_array.c
** File description:
** LIB_Joris_2018
*/

#include <string.h>
#include "joris_getters.h"
#include "joris_setters.h"
#include "my.h"

static void array_add_values(json_object *object, char *value, int type)
{
    for (int i = 0; ARRAY_TYPE[i].type; i++)
        if (type == ARRAY_TYPE[i].type)
            ARRAY_TYPE[i].function(object, value);
}

void joris_object_set_array(json_object *object, char *target,
        char *value, int type)
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
        parent = joris_object_get_object(object, items);
        if (parent) {
            child = json_object_new_array();
            json_object_object_add(parent, key, child);
            array_add_values(child, value, type);
        }
        items[len - 1] = key;
        my_arrfree((void **) items);
    }
}