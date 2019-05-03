/*
** EPITECH PROJECT, 2019
** object_get_array.c
** File description:
** LIB_Joris_2018
*/

#include "json.h"
#include "joris_getters.h"
#include "my.h"

array_list *joris_object_get_array(json_object *object, char *target)
{
    array_list *array = NULL;
    json_object *json = NULL;

    if (target) {
        json = joris_object_get_object(object, target);
        array = json_object_get_array(json);
    }
    return (array);
}