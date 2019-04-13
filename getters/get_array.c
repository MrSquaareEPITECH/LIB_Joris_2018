/*
** EPITECH PROJECT, 2019
** get_array.c
** File description:
** LIB_MyJSONC_2018
*/

#include <json.h>
#include "lib.h"
#include "my_jsonc.h"

void **json_get_array(json_object *file, char *target)
{
    void **array = 0;
    char **args = NULL;
    json_object *json = NULL;
    array_list *array_l = NULL;

    if (target) {
        args = str_split(target, ".");
        json = json_get_object(file, args, 0);
        array_l = json_object_get_array(json);
        array = (array_l) ? array_l->array : NULL;
    }
    return (array);
}