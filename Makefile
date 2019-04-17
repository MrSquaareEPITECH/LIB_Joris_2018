##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for LIB_Joris_2018
##

NAME			=		a.out
LIB_NAME		=		libjoris.a
TEST_NAME		=		tests/unit_tests

CC				=		gcc
AR				=		ar rcs
RM				=		rm -rf

MAIN_SRC		=		main.c

PROJ_SRC		=		joris.c							\
						file/file_create.c				\
						file/file_get.c					\
						file/file_set.c					\
						getters/object_get_array.c		\
						getters/object_get_double.c		\
						getters/object_get_int.c		\
						getters/object_get_object.c		\
						getters/object_get_string.c		\
						lib/str_count.c					\
						lib/str_cpy.c					\
						lib/str_free.c					\
						lib/str_len.c					\
						lib/str_split.c					\
						setters/object_set_array.c		\
						setters/object_set_double.c		\
						setters/object_set_int.c		\
						setters/object_set_object.c		\
						setters/object_set_string.c		\

TEST_SRC		=		tests/test_getters.c			\
						tests/test_setters.c			\

MAIN_OBJ		=		$(MAIN_SRC:.c=.o)

PROJ_OBJ		=		$(PROJ_SRC:.c=.o)

TEST_OBJ		=		$(TEST_SRC:.c=.o)

TEST_COV		=		$(PROJ_SRC:.c=.gcda)	\
						$(PROJ_SRC:.c=.gcno)	\
						$(TEST_SRC:.c=.gcda)	\
						$(TEST_SRC:.c=.gcno)	\

INCLUDE_DIR		=		"include/"
JSON_C_DIR		=		"lib/json-c/"

CFLAGS			+=		-I $(INCLUDE_DIR)
CFLAGS			+=		-W -Wall -Wextra -g3
CFLAGS			+=		-I $(JSON_C_DIR)

LDFLAGS			+=		-L $(JSON_C_DIR) -ljson-c

all:			build_json_c $(NAME)

build_json_c:
				bash "scripts/build_json_c.sh"

all_clean:		clean tests_clean

all_fclean:		fclean tests_fclean

$(NAME):		$(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean

tests_run:		CFLAGS += -fprofile-arcs -ftest-coverage
tests_run:		$(PROJ_OBJ) $(TEST_OBJ)
				$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) -lgcov -lcriterion
				$(TEST_NAME)

tests_clean:	clean
				$(RM) $(TEST_OBJ)
				$(RM) $(TEST_COV)

tests_fclean:	tests_clean
				$(RM) $(TEST_NAME)

tests_re:		tests_fclean tests_run

tests_sweet:	tests_run tests_clean

tests_sh:       sweet

.PHONY:         all all_clean all_fclean clean fclean re sweet tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh