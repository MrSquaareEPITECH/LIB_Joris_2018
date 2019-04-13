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
						getters/get_float.c			\
						getters/get_int.c			\
						getters/get_object.c		\
						getters/get_string.c		\
						lib/str_count.c				\
						lib/str_cpy.c				\
						lib/str_len.c				\
						lib/str_split.c				\
						loaders/json_loaders.c		\

TEST_SRC		=		tests/test_src.c			\

MAIN_OBJ		=		$(MAIN_SRC:.c=.o)

PROJ_OBJ		=		$(PROJ_SRC:.c=.o)

TEST_OBJ		=		$(TEST_SRC:.c=.o)

INCLUDE_DIR		=		"include/"
LIB_DIR			=		"lib/my/"

CFLAGS			+=		-I $(INCLUDE_DIR)
CFLAGS			+=		-W -Wall -Wextra

LDLIBS			+=		-ljson-c

all:			$(NAME)

$(NAME):		$(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)

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