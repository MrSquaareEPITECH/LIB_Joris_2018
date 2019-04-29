/*
** EPITECH PROJECT, 2019
** object_get_object.c
** File description:
** LIB_Joris_2018
*/

#include <json.h>
#include "joris.h"

json_object *joris_object_get_object(json_object *json, char **items)
{
    if (*items) {
        json_object_object_get_ex(json, *items, &json);
        json = joris_object_get_object(json, ++items);
    }
    return (json);
}