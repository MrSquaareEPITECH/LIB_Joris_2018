/*
** EPITECH PROJECT, 2019
** object_get_object.c
** File description:
** LIB_Joris_2018
*/

#include "json.h"
#include "joris_getters.h"

json_object *joris_object_get_object(json_object *object, char **items)
{
    if (*items) {
        json_object_object_get_ex(object, *items, &object);
        object = joris_object_get_object(object, ++items);
    }
    return (object);
}