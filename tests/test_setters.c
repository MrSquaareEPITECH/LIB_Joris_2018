/*
** EPITECH PROJECT, 2018
** test_setters.c
** File description:
** No description
*/

#include <criterion/criterion.h>
#include "joris.h"
#include "json.h"

Test (joris_object_set_array, test_object_set_array)
{
    char *path = "tests/file/create_array.json";
    json_object *create = joris_file_create(path);
    json_object *data = NULL;
    array_list *array = NULL;
    double actual = 1920.0;
    double expected = 1920.0;

    joris_object_set_object(create, "window");
    joris_object_set_array(create, "window.size", "1920.0,1080.0", "double");
    joris_file_set(path, create);
    data = joris_file_get(path);
    array = joris_object_get_array(data, "window.size");
    (void) array;
    cr_assert_eq(actual, expected);
}

Test (joris_object_set_double, test_object_set_double)
{
    char *path = "tests/file/create_double.json";
    json_object *create = joris_file_create(path);
    json_object *data = NULL;
    double actual = 0;
    double expected = 1.5;

    joris_object_set_object(create, "window");
    joris_object_set_double(create, "window.ratio", 1.5);
    joris_file_set(path, create);
    data = joris_file_get(path);
    actual = joris_object_get_double(data, "window.ratio");
    cr_assert_eq(actual, expected);
}

Test (joris_object_set_int, test_object_set_int)
{
    char *path = "tests/file/create_int.json";
    json_object *create = joris_file_create(path);
    json_object *data = NULL;
    int actual = 0;
    int expected = 1;

    joris_object_set_object(create, "window");
    joris_object_set_int(create, "window.mainScene", 1);
    joris_file_set(path, create);
    data = joris_file_get(path);
    actual = joris_object_get_int(data, "window.mainScene");
    cr_assert_eq(actual, expected);
}

Test (joris_object_set_string, test_object_set_string)
{
    char *path = "tests/file/create_string.json";
    json_object *create = joris_file_create(path);
    json_object *data = NULL;
    char *actual = NULL;
    char *expected = "Window Title";

    joris_object_set_object(create, "window");
    joris_object_set_string(create, "window.title", "Window Title");
    joris_file_set(path, create);
    data = joris_file_get(path);
    actual = joris_object_get_string(data, "window.title");
    cr_assert_str_eq(actual, expected);
}