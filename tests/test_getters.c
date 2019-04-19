/*
** EPITECH PROJECT, 2018
** test_getters.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include "joris.h"
#include <json.h>

Test (joris_object_get_array, test_object_get_array)
{
    json_object *data = joris_file_get("tests/file/data.json");

    array_list *tab = joris_object_get_array(data, "window.array");
    cr_assert_eq(18, json_object_get_int(tab->array[0]));
}

Test (joris_object_get_double, test_object_get_double)
{
    json_object *data = joris_file_get("tests/file/data.json");

    double i = joris_object_get_double(data, "window.width");
    cr_assert_eq(1080.0, i);
}

Test (joris_object_get_int, test_object_get_int)
{
    json_object *data = joris_file_get("tests/file/data.json");

    int i = joris_object_get_int(data, "window.mainScene");
    cr_assert_eq(12, i);
}

Test (joris_object_get_string, test_object_get_string)
{
    json_object *data = joris_file_get("tests/file/data.json");

    char *string = joris_object_get_string(data, "window.title");
    cr_assert_str_eq("RobertoPG", string);
}