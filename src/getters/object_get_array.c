/*
** EPITECH PROJECT, 2019
** object_get_array.c
** File description:
** LIB_Joris_2018
*/

#include <json.h>
#include "joris.h"
#include "my.h"

array_list *joris_object_get_array(json_object *file, char *target)
{
    array_list *array = NULL;
    char **items = NULL;
    json_object *json = NULL;

    if (target) {
        items = my_strsplit(target, ".");
        json = joris_object_get_object(file, items);
        array = json_object_get_array(json);
    }
    return (array);
}