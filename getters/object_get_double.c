/*
** EPITECH PROJECT, 2019
** object_get_double.c
** File description:
** LIB_Joris_2018
*/

#include <json.h>
#include "lib.h"
#include "joris.h"

double joris_object_get_double(json_object *file, char *target)
{
    double number = 0;
    char **items = NULL;
    json_object *json = NULL;

    if (target) {
        items = str_split(target, ".");
        json = joris_object_get_object(file, items);
        number = json_object_get_double(json);
    }
    return (number);
}