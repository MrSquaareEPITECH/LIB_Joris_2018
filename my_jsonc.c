/*
** EPITECH PROJECT, 2019
** my_jsonc.c
** File description:
** LIB_MyJSONC_2018
*/

#include <stdio.h>
#include <json-c/json.h>
#include "lib.h"
#include "my_jsonc.h"

int my_jsonc(void)
{
    json_object *file = json_load("tests/data/data.json");
    char **array = str_split("window.title", ".");
    json_object *title = get_object(file, array, 0);

    printf("title: %s" "\n", json_object_get_string(title));
    return (0);
}