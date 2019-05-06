/*
** EPITECH PROJECT, 2019
** file_get.c
** File description:
** LIB_Joris_2018
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "json.h"
#include "joris_file.h"

json_object *joris_file_get(const char *path)
{
    json_object *object = NULL;

    object = json_object_from_file(path);
    return (object);
}