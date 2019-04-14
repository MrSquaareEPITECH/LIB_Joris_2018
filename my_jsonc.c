/*
** EPITECH PROJECT, 2019
** my_jsonc.c
** File description:
** LIB_MyJSONC_2018
*/

#include <stdio.h>
#include <json.h>
#include "lib.h"
#include <stdlib.h>
#include "my_jsonc.h"

int my_jsonc(void)
{
    json_object *file = json_load("tests/data/data.json");
    void **array = json_get_array(file, "parent.child.array");
    double dbl = json_get_double(file, "parent.child.double");
    int itg = json_get_int(file, "parent.child.int");
    char *string = json_get_string(file, "parent.child.string");
    json_creator("tests/data/create.json", file);

    for (int i = 0; array[i] != NULL; ++i)
        printf("array[%d]: %s" "\n", i, json_object_get_string(array[i]));
    printf("double: %lf" "\n", dbl);
    printf("int: %d" "\n", itg);
    printf("string: %s" "\n", string);
    return (0);
}