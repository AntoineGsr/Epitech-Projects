##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bsq
##

SRC	=	./src/exe_game.c	\
		./src/create_my_window.c	\
		./src/manage_mouse_click.c	\
		./src/close_window.c	\
		./src/display_my_window.c	\
		./src/init_struct_sprite.c	\
		./src/init_struct_mouse.c	\
		./src/init_struct_back.c	\
		./src/init_struct_music.c	\
		./src/exec_struct_mouse.c	\
		./src/exec_struct_back.c	\
		./src/exec_struct_bird.c	\
		./src/exec_music.c	\
		./src/move_rect.c	\
		./src/restart_sprite.c	\
		./src/speed_sprite.c	\
		./src/moving_sprite_bird.c	\
		./src/analyse_events.c	\
		./src/start_menu.c	\
		./src/restart_game.c	\
		./src/main.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	my_hunter

CFLAGS	=	-I./include/ -I./src/ -g

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


