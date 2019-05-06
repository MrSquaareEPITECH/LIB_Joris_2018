/*
** EPITECH PROJECT, 2019
** object_get_object.c
** File description:
** LIB_Joris_2018
*/

#include "json.h"
#include "joris_getters.h"
#include "my.h"

static json_object *joris_object_get_object_r(json_object *object, char **items)
{
    if (*items) {
        json_object_object_get_ex(object, *items, &object);
        object = joris_object_get_object_r(object, ++items);
    }
    return (object);
}

json_object *joris_object_get_object(json_object *object, char *target)
{
    json_object *obj = NULL;
    char **items = NULL;

    if (object) {
        items = my_strsplit(target, ".");
        if (items)
            obj = joris_object_get_object_r(object, items);
        my_arrfree((void **) items);
    }
    return (obj);
}