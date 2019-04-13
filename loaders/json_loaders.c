/*
** EPITECH PROJECT, 2019
** file_loaders.c
** File description:
** LIB_MyJSONC_2018
*/

#include <json-c/json.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my_jsonc.h"

json_object *json_load(char *path)
{
    json_object *json = NULL;
    struct stat st = {0};
    int fd = stat(path, &st);
    char *buffer = NULL;

    if (fd != -1) {
        buffer = malloc(sizeof(char) * (st.st_size + 1));
        fd = open(path, O_RDONLY);
        read(fd, buffer, st.st_size);
        json = json_tokener_parse(buffer);
        close(fd);
    }
    return (json);
}