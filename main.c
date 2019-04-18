/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** LIB_Joris_2018
*/

#include <json.h>
#include <stdio.h>
#include "joris.h"

int main(void)
{
    char *array[] = {"window", NULL};
    json_object *create = joris_file_create("tests/file/create.json");
    json_object *data = joris_file_get("tests/file/data.json");
    json_object *window = joris_object_get_object(data, array);

    (void) window;
    joris_object_set_object(create, "window");
    return (0);
}