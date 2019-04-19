/*
** EPITECH PROJECT, 2018
** test_setters.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include "joris.h"
#include <json.h>

Test (joris_object_set_array, test_object_set_array)
{
    json_object *create = joris_file_create("tests/file/create_array.json");
    joris_object_set_object(create, "window");
    joris_object_set_array(create, "window.array");
    joris_file_set("tests/file/create_array.json", create);
    json_object *data = joris_file_get("tests/file/create_array.json");
    array_list *tab = joris_object_get_array(data, "window.array");
    cr_assert_eq(11, json_object_get_int(tab->array[0]));
}

Test (joris_object_set_double, test_object_set_double)
{
    json_object *create = joris_file_create("tests/file/create_double.json");
    joris_object_set_object(create, "window");
    joris_object_set_double(create, "window.damage", 51.4);
    joris_file_set("tests/file/create_double.json", create);
    json_object *data = joris_file_get("tests/file/create_double.json");
    double i = joris_object_get_double(data, "window.damage");
    cr_assert_eq(51.4, i);
}

Test (joris_object_set_int, test_object_set_int)
{
    json_object *create = joris_file_create("tests/file/create_int.json");
    joris_object_set_object(create, "window");
    joris_object_set_int(create, "window.life", 39);
    joris_file_set("tests/file/create_int.json", create);
    json_object *data = joris_file_get("tests/file/create_int.json");
    int i = joris_object_get_int(data, "window.life");
    cr_assert_eq(39, i);
}

Test (joris_object_set_string, test_object_set_string)
{
    json_object *create = joris_file_create("tests/file/create_string.json");
    joris_object_set_object(create, "window");
    joris_object_set_string(create, "window.title", "RobertoPG");
    joris_file_set("tests/file/create_string.json", create);
    json_object *data = joris_file_get("tests/file/create_string.json");
    char *i = joris_object_get_string(data, "window.title");
    cr_assert_str_eq("RobertoPG", i);
}