/*
** EPITECH PROJECT, 2019
** file_set.c
** File description:
** LIB_Joris_2018
*/

#include <fcntl.h>
#include <json.h>
#include <unistd.h>
#include "joris.h"

void joris_file_set(char *path, json_object *json)
{
    const char *json_string = NULL;
    size_t len = 0;
    int fd = 0;

    if (path) {
        fd = open(path, O_WRONLY, 0755);
        if (fd != -1) {
            json_string = json_object_to_json_string_length(json,
                    JSON_C_TO_STRING_PRETTY, &len);
            write(fd, json_string, len);
        }
        close(fd);
    }
}