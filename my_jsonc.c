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
    json_set_int(file, "parent.child", "damage", 23);
    json_set_double(file, "parent.child", "life", 49.5);
    json_set_string(file, "parent.child", "name", "Roger");
    json_create("tests/data/create.json", file);
    return (0);
}