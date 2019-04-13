/*
** EPITECH PROJECT, 2019
** get_object.c
** File description:
** LIB_MyJSONC_2018
*/

#include <json_object.h>
#include "my_jsonc.h"

json_object *json_get_object(json_object *json, char **array, int index)
{
    if (array[index]) {
        json_object_object_get_ex(json, array[index], &json);
        json = json_get_object(json, array, index + 1);
    }
    return (json);
}