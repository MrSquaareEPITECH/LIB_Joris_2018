##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile for LIB_Joris_2018
##

NAME			=		a.out
LIB_NAME		=		libjoris.so
TEST_NAME		=		tests/unit_tests

NO_COLOR		=		\e[0;0m
GREEN_COLOR		=		\e[0;32m
RED_COLOR		=		\e[0;31m
GREEN_B_COLOR	=		\e[1;32m
RED_B_COLOR		=		\e[1;31m

CC				=		gcc
RM				=		rm -rf

MAIN_SRC		=		main.c

PROJ_SRC		=		src/file/file_create.c							\
						src/file/file_get.c								\
						src/file/file_set.c								\
						src/getters/object_get_array.c					\
						src/getters/object_get_double.c					\
						src/getters/object_get_int.c					\
						src/getters/object_get_object.c					\
						src/getters/object_get_string.c					\
						src/setters/object_set_array.c					\
						src/setters/object_set_double.c					\
						src/setters/object_set_int.c					\
						src/setters/object_set_object.c					\
						src/setters/object_set_string.c					\
						src/setters/array/object_set_array_double.c		\
						src/setters/array/object_set_array_int.c		\
						src/setters/array/object_set_array_string.c		\

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
CFLAGS			+=		-I $(LIB_MY_DIR)/include
CFLAGS			+=		-I $(LIB_JSONC_DIR)

LDFLAGS			+=		-L $(LIB_MY_DIR) -Wl,-R "$(PWD)/$(LIB_MY_DIR)" -lmy
LDFLAGS			+=		-L $(LIB_JSONC_DIR) -Wl,-R "$(PWD)/$(LIB_JSONC_DIR)" -ljson-c

MAKEFLAGS		+=		--silent

%.o:			%.c
				$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $< \
				&& echo "$< $(GREEN_COLOR)successfully compiled$(NO_COLOR)" \
				|| { echo "$< $(RED_COLOR)couldn't be compiled$(NO_COLOR)"; exit 1; }

all:			$(NAME)

all_clean:		clean lib_clean tests_clean

all_fclean:		lib_all_fclean fclean lib_fclean tests_fclean

lib_all:		lib_my lib_jsonc

lib_all_fclean:	lib_my_fclean lib_jsonc_fclean

lib_all_re:		lib_all_fclean lib_all

lib_my:
ifneq ("$(wildcard ./lib/my)","")
else
				git clone git@git.epitech.eu:/guillaume.bonnet@epitech.eu/LIB_MyLIB_2018 $(LIB_MY_DIR)
				rm -rf $(LIB_MY_DIR)/.git
endif
ifneq ("$(wildcard ./lib/my/libmy.so)","")
else
				cd $(LIB_MY_DIR) && $(MAKE) lib_re
endif

lib_my_fclean:
				$(RM) $(LIB_MY_DIR)

.ONESHELL:
lib_jsonc:
ifneq ("$(wildcard ./lib/jsonc)","")
else
				git clone https://github.com/json-c/json-c.git $(LIB_JSONC_DIR)
				rm -rf $(LIB_JSONC_DIR)/.git
endif
ifneq ("$(wildcard ./lib/jsonc/libjson-c.so)","")
else
				cd $(LIB_JSONC_DIR)
				sh autogen.sh
				./configure
				cmake .
				make
endif

lib_jsonc_fclean:
				$(RM) $(LIB_JSONC_DIR)

$(NAME):		lib_all $(MAIN_OBJ) $(PROJ_OBJ)
				$(CC) $(MAIN_OBJ) $(PROJ_OBJ) -o $(NAME) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(NAME) couldn't be created$(NO_COLOR)"; exit 1; }

clean:
				$(RM) $(MAIN_OBJ) $(PROJ_OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

sweet:			all clean

debug:			CFLAGS += -g3
debug:			sweet

lib:			CFLAGS += -fPIC
lib:			LDFLAGS += -shared
lib:			lib_all $(PROJ_OBJ)
				$(CC) $(PROJ_OBJ) -o $(LIB_NAME) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(LIB_NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(LIB_NAME) couldn't be created$(NO_COLOR)"; exit 1; }

lib_clean:
				$(RM) $(PROJ_OBJ)

lib_fclean:		lib_clean
				$(RM) $(LIB_NAME)

lib_re:			lib_fclean lib

lib_sweet:		lib lib_clean

tests_run:		CFLAGS += -fprofile-arcs -ftest-coverage
tests_run:		LDLIBS += -lgcov -lcriterion
tests_run:		lib_all $(PROJ_OBJ) $(TEST_OBJ)
				$(CC) $(PROJ_OBJ) $(TEST_OBJ) -o $(TEST_NAME) $(LDFLAGS) $(LDLIBS) \
				&& echo "$(GREEN_B_COLOR)$(TEST_NAME) successfully created$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)$(TEST_NAME) couldn't be created$(NO_COLOR)"; exit 1; }
				$(TEST_NAME) \
				&& echo "$(GREEN_B_COLOR)Unit tests passed successfully$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)Unit tests did not pass successfully$(NO_COLOR)"; exit 1; }

tests_clean:	clean
				$(RM) $(TEST_OBJ)
				$(RM) $(TEST_COV)

tests_fclean:	tests_clean
				$(RM) $(TEST_NAME)

tests_re:		tests_fclean tests_run

tests_sweet:	tests_run tests_clean

tests_sh:       sweet
				sh tests/tests.sh $(NAME) \
				&& echo "$(GREEN_B_COLOR)Functional tests passed successfully$(NO_COLOR)" \
				|| { echo "$(RED_B_COLOR)Functional tests did not pass successfully$(NO_COLOR)"; exit 1; }

.PHONY:         all all_clean all_fclean clean fclean re sweet debug lib lib_clean lib_fclean lib_re lib_sweet tests_run tests_clean tests_fclean tests_re tests_sweet tests_sh