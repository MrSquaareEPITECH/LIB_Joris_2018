/*
** EPITECH PROJECT, 2019
** object_get_string.c
** File description:
** LIB_Joris_2018
*/

#include "json.h"
#include "joris_getters.h"
#include "my.h"

char *joris_object_get_string(json_object *object, char *target)
{
    char *string = NULL;
    char **items = NULL;
    json_object *json = NULL;

    if (target) {
        items = my_strsplit(target, ".");
        json = joris_object_get_object(object, items);
        string = (char *) json_object_get_string(json);
    }
    return (string);
}