/*
** EPITECH PROJECT, 2019
** object_set_object.c
** File description:
** LIB_Joris_2018
*/

#include <json.h>
#include "lib.h"
#include "joris.h"

void joris_object_set_object(json_object *file, char *target)
{
    char **items = NULL;
    int len = 0;
    char *key = NULL;
    json_object *parent = NULL;
    json_object *child = NULL;

    if (target) {
        items = str_split(target, ".");
        len = str_len_list(items);
        key = items[len - 1];
        items[len - 1] = NULL;
        parent = joris_object_get_object(file, items);
        if (parent) {
            child = json_object_new_object();
            json_object_object_add(parent, key, child);
        }
        items[len - 1] = key;
        str_free_list(items);
    }
}