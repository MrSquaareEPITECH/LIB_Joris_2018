/*
** EPITECH PROJECT, 2019
** object_set_string.c
** File description:
** LIB_Joris_2018
*/

#include <stdlib.h>
#include "json.h"
#include "joris_getters.h"
#include "joris_setters.h"
#include "my.h"

void joris_object_set_string(json_object *object, char *target, char *value)
{
    char *key = target;
    char *parent_target = my_strdup(target);
    char *parent_end = NULL;
    json_object *parent = object;
    json_object *child = NULL;

    if (target) {
        parent_end = my_strrchr(parent_target, '.');
        if (parent_end) {
            parent_end[0] = '\0';
            key = parent_end + 1;
            parent = joris_object_get_object(object, parent_target);
        }
        child = json_object_new_string(value);
        json_object_object_add(parent, key, child);
        free(parent_target);
    }
}