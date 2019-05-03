/*
** EPITECH PROJECT, 2019
** file_create.c
** File description:
** LIB_Joris_2018
*/

#include <fcntl.h>
#include "json.h"
#include <unistd.h>
#include "joris_file.h"

json_object *joris_file_create(char *path)
{
    json_object *json = NULL;
    const char *json_string = NULL;
    size_t len = 0;
    int fd = 0;

    if (path) {
        json = json_object_new_object();
        fd = open(path, O_CREAT | O_WRONLY, 0755);
        if (fd != -1) {
            json_string = json_object_to_json_string_length(json,
                    JSON_C_TO_STRING_PRETTY, &len);
            write(fd, json_string, len);
        }
        close(fd);
    }
    return (json);
}