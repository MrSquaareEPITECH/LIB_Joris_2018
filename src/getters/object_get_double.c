/*
** EPITECH PROJECT, 2019
** object_get_double.c
** File description:
** LIB_Joris_2018
*/

#include "json.h"
#include "joris_getters.h"
#include "my.h"

double joris_object_get_double(json_object *object, char *target)
{
    double number = 0;
    json_object *json = NULL;

    if (object && target) {
        json = joris_object_get_object(object, target);
        number = json_object_get_double(json);
    }
    return (number);
}