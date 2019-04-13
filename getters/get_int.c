/*
** EPITECH PROJECT, 2019
** get_int.c
** File description:
** LIB_MyJSONC_2018
*/

#include <json_object.h>
#include "lib.h"
#include "my_jsonc.h"

int json_get_int(json_object *file, char *target)
{
    int number = 0;
    char **args = NULL;
    json_object *json = NULL;

    if (target) {
        args = str_split(target, ".");
        json = json_get_object(file, args, 0);
        number = json_object_get_int(json);
    }
    return (number);
}