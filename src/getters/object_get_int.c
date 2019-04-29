/*
** EPITECH PROJECT, 2019
** object_get_int.c
** File description:
** LIB_Joris_2018
*/

#include <json.h>
#include "joris.h"
#include "my.h"

int joris_object_get_int(json_object *file, char *target)
{
    int number = 0;
    char **items = NULL;
    json_object *json = NULL;

    if (target) {
        items = my_strsplit(target, ".");
        json = joris_object_get_object(file, items);
        number = json_object_get_int(json);
    }
    return (number);
}