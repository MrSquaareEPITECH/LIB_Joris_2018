##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for LIB_Joris_2018
##

NAME			=		a.out
LIB_NAME		=		libjoris.so
TEST_NAME		=		tests/unit_tests

CC				=		gcc
RM				=		rm -rf

MAIN_SRC		=		main.c

PROJ_SRC		=		file/file_create.c							\
						file/file_get.c								\
						file/file_set.c								\
						getters/object_get_array.c					\
						getters/object_get_double.c					\
						getters/object_get_int.c					\
						getters/object_get_object.c					\
						getters/object_get_string.c					\
						setters/object_set_array.c					\
						setters/object_set_double.c					\
						setters/object_set_int.c					\
						setters/object_set_object.c					\
						setters/object_set_string.c					\
						setters/array/object_set_array_double.c		\
						setters/array/object_set_array_int.c		\
						setters/array/object_set_array_string.c		\

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
LIB_MY_DIR		=		"lib/my/"
LIB_JSONC_DIR	=		"lib/jsonc/"

CFLAGS			+=		-I $(INCLUDE_DIR)
CFLAGS			+=		-W -Wall -Wextra
CFLAGS			+=		-I $(LIB_MY_DIR)/include -I $(LIB_JSONC_DIR)

LDFLAGS			+=		-L $(LIB_MY_DIR) -Wl,-R $(LIB_MY_DIR) -lmy
LDFLAGS			+=		-L $(LIB_JSONC_DIR) -Wl,-R $(LIB_JSONC_DIR) -ljson-c

all:			lib_my lib_jsonc $(NAME)

all_clean:		lib_my_clean clean lib_clean tests_clean

all_fclean:		lib_my_fclean fclean lib_fclean tests_fclean

lib_update:
				git submodule update --init --recursive --remote

.ONESHELL:
lib_jsonc:
ifneq ("$(wildcard ./lib/jsonc/libjson-c.so)","")
else
				cd lib/jsonc
				sh autogen.sh
				./configure
				cmake .
				make
endif

lib_my:
ifneq ("$(wildcard ./lib/my/libmy.so)","")
else
				cd $(LIB_MY_DIR) && $(MAKE) lib_re
endif

lib_my_clean:
				$(MAKE) -C $(LIB_MY_DIR) lib_clean

lib_my_fclean:
				$(MAKE) -C $(LIB_MY_DIR) lib_fclean

$(NAME):		$(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS)

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean

lib:			CFLAGS += -fPIC
lib:			LDFLAGS += -shared
lib:			lib_my lib_jsonc $(PROJ_OBJ)
				$(CC) $(PROJ_OBJ) -o $(LIB_NAME) $(LDFLAGS) $(LDLIBS)

lib_clean:
				$(RM) $(PROJ_OBJ)

lib_fclean:		lib_clean
				$(RM) $(LIB_NAME)

lib_re:			lib_fclean lib

lib_sweet:		lib lib_clean

tests_run:		CFLAGS += -fprofile-arcs -ftest-coverage
tests_run:		lib_my lib_jsonc $(PROJ_OBJ) $(TEST_OBJ)
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

.PHONY:         all all_clean all_fclean clean fclean re sweet lib lib_clean lib_fclean lib_re lib_sweet tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh