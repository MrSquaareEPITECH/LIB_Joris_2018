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

json_object *joris_file_create(const char *path)
{
    json_object *object = NULL;
    int fd = 0;

    if (path) {
        fd = open(path, O_CREAT | O_WRONLY, 0644);
        if (fd != -1) {
            object = json_object_new_object();
            json_object_to_fd(fd, object, JSON_C_TO_STRING_PRETTY);
        }
        close(fd);
    }
    return (object);
}