##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Made by Vincent Daribo
##

SRC	=	src/main.c 	\
		src/manage_file.c 	\
		src/my_strcmp.c 	\
		src/game_win.c 		\
		src/character_movements.c 	\
		src/launch_and_end.c 	\
		src/str_to_arr.c 	\
		src/manage_arr.c 	\
		src/pos_list.c 		\
		src/win_or_lose.c 	\

all :
	make -C printf_doss
	gcc -o my_sokoban $(SRC) -L. -lmy -g3 -lncurses -Wall -Wextra


clean :
	rm -rf *.o *~
	rm -rf /printf_doss/*.o printf_doss/*~
	rm -rf includes/*~ src/*~

fclean : clean
	rm -rf my_sokoban
	make fclean -C printf_doss
re : fclean all
