##
## EPITECH PROJECT, 2021
## Project Makefile
## File description:
## This script is the default project Makefile.
##

SRC_MAIN	=	main.c

SRC		=	screens/main_screen/menu_screen.c								\
			screens/main_screen/menu_init_struct.c 							\
			screens/main_screen/menu_set.c 									\
			screens/main_screen/menu_draw.c 								\
			screens/main_screen/menu_free.c 								\
			screens/main_screen/menu_event.c 								\
			screens/level1_screen/level1_screen.c 							\
			screens/level1_screen/level1_set.c 								\
			screens/level1_screen/level1_free.c 							\
			screens/level1_screen/level1_init_struct.c 						\
			screens/level1_screen/move_player.c								\
			screens/level1_screen/level1_event.c 							\
			screens/level1_screen/level1_draw.c 							\
			screens/level1_screen/set_player.c								\
			screens/how_to_play_screen/how_to_play_screen.c 				\
			screens/how_to_play_screen/how_to_play_set.c 					\
			screens/how_to_play_screen/how_to_play_free.c 					\
			screens/how_to_play_screen/how_to_play_init_struct.c 			\
			screens/how_to_play_screen/how_to_play_event.c 					\
			screens/how_to_play_screen/how_to_play_draw.c 					\
			screens/settings_screen/settings_screen.c 						\
			screens/settings_screen/settings_set.c 							\
			screens/settings_screen/settings_draw.c 						\
			screens/settings_screen/settings_free.c 						\
			screens/settings_screen/settings_event.c 						\
			screens/settings_screen/settings_init_struct.c					\
			screens/settings_screen/volume_settings/volume_events.c 		\
			screens/settings_screen/fps_settings/fps_events.c 				\
			screens/settings_screen/controls_settings/controls_events.c		\
			screens/settings_screen/color_text_settings/color_text_events.c \
			screens/inventory_screen/inventory_set.c 						\
			screens/inventory_screen/inventory_free.c 						\
			screens/inventory_screen/inventory_init_struct.c 				\
			screens/inventory_screen/inventory_event.c 						\
			screens/inventory_screen/inventory_draw.c 						\
			screens/inventory_screen/events/move_items.c 					\
			screens/inventory_screen/events/mouse_events.c 					\
			screens/inventory_screen/inventory_set_slot.c 					\
			screens/level1_screen/init_collisions.c      					\
			screens/level1_screen/modif_collisions_pos.c 					\
			screens/level1_screen/collisions_up_and_down.c 					\
			screens/level1_screen/collisions_left_and_right.c 				\
			screens/level1_screen/pick_up_item.c 							\
			screens/level1_screen/set_items.c 								\
			screens/level1_screen/set_stats.c 								\
			screens/level1_screen/check_stats.c 							\
      		screens/level1_screen/all_collisions.c 							\
			screens/fight_screen/fight_screen.c 							\
			screens/fight_screen/set_attack.c 								\
			screens/fight_screen/check_collisions_fireball.c 				\
			screens/fight_screen/set_ennemy_fight.c 						\
			screens/fight_screen/set_fight_screen.c 						\
			screens/fight_screen/set_player_fight.c							\
			screens/fight_screen/free_fight_screen.c 						\
			screens/fight_screen/event_management_fight_screen.c 			\
			screens/fight_screen/draw_fight_screen.c 						\
			tools/init_screen_struct.c 										\
			tools/color_gestion.c 											\
			tools/set_screen.c 												\
			tools/open_and_read_file.c										\
			tools/str_to_word_array.c										\
			tools/init_things.c 											\
			tools/free_things.c												\
			tools/put_pixel_line.c											\
			tools/water.c													\
			tools/snow.c

OBJ			=	$(SRC:%.c=%.o) $(SRC_MAIN:%.c=%.o)

NAME   		=	my_rpg

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -Wshadow -I../includes -g

LDFLAGS		+=	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all:	$(NAME)

$(NAME): 	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)
	@ mv $(NAME) ../$(NAME)

debug : all
		$(CC) $(DEBUG) -o $(NAME) $(SRC_MAIN) $(SRC) $(LDFLAGS) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) ../$(NAME)

re:			fclean all

.PHONY: all clean fclean re
