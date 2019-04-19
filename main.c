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
    joris_object_set_string(create, "window.title", "Window Title");
    joris_object_set_array(create, "window.size", "1920.0,1080.0", "double");
    joris_object_set_double(create, "window.ratio", 1.5);
    joris_object_set_int(create, "window.mainScene", 1);
    joris_file_set("tests/file/create.json", create);
    printf("window: %s", json_object_to_json_string_ext(window,
            JSON_C_TO_STRING_PRETTY));
    return (0);
}