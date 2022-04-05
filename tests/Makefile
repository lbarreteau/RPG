##
## EPITECH PROJECT, 2021
## Project Makefile
## File description:
## This script is the default project Makefile.
##

SRC_TEST	=	test_menu.c

SRC			=	../sources/screens/main_screen/menu_screen.c			\
				../sources/screens/main_screen/menu_init_struct.c 		\
				../sources/screens/main_screen/menu_set.c 				\
				../sources/screens/main_screen/menu_draw.c 				\
				../sources/screens/main_screen/menu_free.c 				\
				../sources/screens/main_screen/menu_circle_gestion.c	\
				../sources/screens/main_screen/menu_event.c 			\
				../sources/tools/open_and_read_file.c					\
				../sources/tools/str_to_word_array.c					\
				../sources/tools/init_things.c 							\
				../sources/tools/free_things.c

OBJ			=	$(SRC:%.c=%.o) $(SRC_TEST:%.c=%.o)

NAME   		=	unit_tests

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Wshadow -I../includes

LDFLAGS		+=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

TESTFLAGS		+=	--coverage -lcriterion

all:	$(NAME)

$(NAME): 	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(TESTFLAGS)
	@ mv $(NAME) ../$(NAME)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) ../$(NAME)

re:			fclean all

.PHONY: all clean fclean re
