/*
** EPITECH PROJECT, 2018
** json_creator.c
** File description:
** No description
*/

#include <stdio.h>
#include <json.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "lib.h"
#include "my_jsonc.h"

void json_creator(char *filepath, json_object *file)
{
    int fd = 0;
    const char *json_string = NULL;
    size_t len;

    fd = open(filepath, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd != -1) {
        json_string = json_object_to_json_string_length(file,
                JSON_C_TO_STRING_PRETTY, &len);
        write(fd, json_string, len);
    }
    close(fd);
}