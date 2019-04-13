/*
** EPITECH PROJECT, 2019
** get_string.c
** File description:
** LIB_MyJSONC_2018
*/

#include <json_object.h>
#include "lib.h"
#include "my_jsonc.h"

char *json_get_string(json_object *file, char *target)
{
    char *string = NULL;
    char **args = NULL;
    json_object *json = NULL;

    if (target) {
        args = str_split(target, ".");
        json = json_get_object(file, args, 0);
        string = (char *) json_object_get_string(json);
    }
    return (string);
}