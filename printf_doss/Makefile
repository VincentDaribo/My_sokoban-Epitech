##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Made by Vincent Daribo
##

SRC	=	my_printf.c 	\
		my_put_hex.c 	\
		conv_int.c 	\
		my_put_oct.c 	\
		my_put_nbr.c 	\
		my_strlen.c 	\
		my_putstr.c 	\
		my_putchar.c 	\
		my_put_bin.c 	\
		my_put_u.c 	\
		my_put_plus.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all :	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..
	cp my.h ../includes
clean :
	rm -f $(OBJ) *~ *.gcno *.gcda

fclean : clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re : fclean all
