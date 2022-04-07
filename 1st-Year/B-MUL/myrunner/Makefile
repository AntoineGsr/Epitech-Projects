##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## my_runner
##

SRC	=	./src/error_gestion.c	\
		./src/helper_gestion.c	\
		./src/create_my_window.c	\
		./src/chained_list_obstacles.c	\
		./src/create_objects_game.c	\
		./src/create_object.c	\
		./src/create_music.c	\
		./src/filepath_bck.c	\
		./src/open_game_map.c	\
		./src/analyse_events.c	\
		./src/gestion_page.c	\
		./src/press_page.c	\
		./src/menu_page.c	\
		./src/game_page.c	\
		./src/display_my_window.c	\
		./src/parallax_effect.c	\
		./src/obstacles_gestion.c	\
		./src/destroy_objects_game.c	\
		./src/destroy_object.c	\
		./src/manage_mouse_click.c	\
		./src/manage_key_pressed.c	\
		./src/manage_mouse_move.c	\
		./src/home_pause_page.c	\
		./src/charact_animation.c	\
		./src/restart_clocks.c	\
		./src/gameend_page.c	\
		./src/gestion_music.c	\
		./src/mouse_move_first_menu.c	\
		./src/mouse_move_ingame.c	\
		./src/mouse_move_endgame.c	\
		./src/mouse_click_menu.c	\
		./src/mouse_click_pause.c	\
		./src/mouse_click_end.c	\
		./src/mouse_click_home.c	\
		./src/text_gestion.c	\
		./src/main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_runner

CFLAGS	=	-I./include/ -I./src/

LDFLAGS =	-L./lib/ -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ) lib/libmy.a
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) ./lib/my/*~
	$(RM) *~
	$(RM) $(OBJ)
	$(MAKE) -C ./lib/my/ clean

fclean:	clean
	$(RM) $(NAME)
	$(RM) ./lib/libmy.a
	$(MAKE) -C ./lib/my/ fclean

re:	fclean all

lib/libmy.a:
	$(MAKE) -C ./lib/my/

.Phony: all clean fclean re


