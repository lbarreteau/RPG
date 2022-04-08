##
## EPITECH PROJECT, 2021
## Project Makefile
## File description:
## This script is the default project Makefile.
##

SRC_MAIN	=	main.c

SRC			=	screens/main_screen/menu_screen.c					\
				screens/main_screen/menu_init_struct.c 				\
				screens/main_screen/menu_set.c 						\
				screens/main_screen/menu_draw.c 					\
				screens/main_screen/menu_free.c 					\
				screens/main_screen/menu_event.c 					\
				screens/level1_screen/level1_screen.c 				\
				screens/level1_screen/level1_set.c 					\
				screens/level1_screen/level1_free.c 				\
				screens/level1_screen/level1_init_struct.c 			\
				screens/level1_screen/level1_event.c 				\
				screens/level1_screen/level1_draw.c 				\
				screens/settings_screen/settings_screen.c 			\
				screens/settings_screen/settings_set.c 				\
				screens/settings_screen/settings_draw.c 			\
				screens/settings_screen/settings_free.c 			\
				screens/settings_screen/settings_event.c 			\
				screens/settings_screen/settings_init_struct.c		\
				tools/init_screen_struct.c 							\
				tools/color_gestion.c 								\
				tools/set_screen.c 									\
				tools/open_and_read_file.c							\
				tools/str_to_word_array.c							\
				tools/init_things.c 								\
				tools/free_things.c

OBJ			=	$(SRC:%.c=%.o) $(SRC_MAIN:%.c=%.o)

NAME   		=	my_rpg

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Wshadow -I../includes -g

LDFLAGS		+=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME)

$(NAME): 	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@ mv $(NAME) ../$(NAME)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) ../$(NAME)

re:			fclean all

.PHONY: all clean fclean re
