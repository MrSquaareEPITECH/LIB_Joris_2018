/*
** EPITECH PROJECT, 2018
** test_getters.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include "joris.h"
#include "json.h"

Test (joris_object_get_array, test_object_get_array)
{
    char *path = "tests/file/data.json";
    json_object *data = joris_file_get(path);
    array_list *array = joris_object_get_array(data, "window.size");
    double actual = 1920.0;
    double expected = 1920.0;

    (void) array;
    cr_assert_eq(actual, expected);
}

Test (joris_object_get_double, test_object_get_double)
{
    char *path = "tests/file/data.json";
    json_object *data = joris_file_get(path);
    double actual = joris_object_get_double(data, "window.ratio");
    double expected = 1.5;

    cr_assert_eq(actual, expected);
}

Test (joris_object_get_int, test_object_get_int)
{
    char *path = "tests/file/data.json";
    json_object *data = joris_file_get(path);
    int actual = joris_object_get_int(data, "window.mainScene");
    int expected = 1;

    cr_assert_eq(actual, expected);
}

Test (joris_object_get_string, test_object_get_string)
{
    char *path = "tests/file/data.json";
    json_object *data = joris_file_get(path);
    char *actual = joris_object_get_string(data, "window.title");
    char *expected = "Window Title";

    cr_assert_str_eq(actual, expected);
}