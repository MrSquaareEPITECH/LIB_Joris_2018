/*
** EPITECH PROJECT, 2019
** object_set_array.c
** File description:
** LIB_Joris_2018
*/

#include <stdlib.h>
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
    char *key = target;
    char *parent_target = NULL;
    char *parent_end = NULL;
    json_object *parent = object;
    json_object *child = NULL;

    if (object && target) {
        parent_target = my_strdup(target);
        parent_end = my_strrchr(parent_target, '.');
        if (parent_end) {
            parent_end[0] = '\0';
            key = parent_end + 1;
            parent = joris_object_get_object(object, parent_target);
        }
        child = json_object_new_array();
        json_object_object_add(parent, key, child);
        array_add_values(child, value, type);
        free(parent_target);
    }
}