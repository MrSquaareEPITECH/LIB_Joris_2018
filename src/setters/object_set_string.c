/*
** EPITECH PROJECT, 2019
** object_set_string.c
** File description:
** LIB_Joris_2018
*/

#include "json.h"
#include "joris_getters.h"
#include "joris_setters.h"
#include "my.h"

void joris_object_set_string(json_object *object, char *target, char *value)
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
            child = json_object_new_string(value);
            json_object_object_add(parent, key, child);
        }
        items[len - 1] = key;
        my_arrfree((void **) items);
    }
}