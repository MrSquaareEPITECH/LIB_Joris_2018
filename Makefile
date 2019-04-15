##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for LIB_MyJSONC_2018
##

NAME			=		a.out
TEST_NAME		=		tests/unit_tests

CC				=		gcc

RM				=		rm -rf

MAIN_SRC		=		main.c

PROJ_SRC		=		my_jsonc.c					\
						getters/get_array.c			\
						getters/get_double.c		\
						getters/get_int.c			\
						getters/get_object.c		\
						getters/get_string.c		\
						setters/set_array.c			\
						setters/set_double.c		\
						setters/set_int.c			\
						setters/set_string.c		\
						lib/str_count.c				\
						lib/str_cpy.c				\
						lib/str_free.c				\
						lib/str_len.c				\
						lib/str_split.c				\
						file/json_loaders.c			\
						file/json_creator.c			\

TEST_SRC		=		tests/test_src.c			\

MAIN_OBJ		=		$(MAIN_SRC:.c=.o)

PROJ_OBJ		=		$(PROJ_SRC:.c=.o)

TEST_OBJ		=		$(TEST_SRC:.c=.o)

INCLUDE_DIR		=		"include/"
LIB_DIR			=		"lib/"
JSON_C_DIR		=		"lib/json-c/"

CFLAGS			+=		-I $(INCLUDE_DIR)
CFLAGS			+=		-W -Wall -Wextra
CFLAGS			+=		-I $(JSON_C_DIR)

LDFLAGS			+=		-L $(JSON_C_DIR) -ljson-c

all:			json_c_build $(NAME)

.ONESHELL:
json_c_build:
				bash "scripts/build_json_c.sh"

$(NAME):		$(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)
				$(RM) $(JSON_C_DIR)

re:				fclean all

sweet:			all clean

tests_run:		$(PROJ_OBJ) $(TEST_OBJ)
				$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(CFLAGS) $(LDFLAGS) $(LDLIBS) --coverage -lcriterion
				$(TEST_NAME)

tests_clean:	clean
				$(RM) $(TEST_OBJ)
				$(RM) *.gcda
				$(RM) *.gcno

tests_fclean:	tests_clean
				$(RM) $(TEST_NAME)

tests_sweet:	tests_run tests_clean

tests_sh:       sweet

.PHONY:         all clean fclean re sweet tests_run tests_clean tests_fclean tests_sweet tests_sh