##
## EPITECH PROJECT, 2024
## make
## File description:
## make
##

SRC	=	*.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libcrim.a

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -c $(SRC) -I../include/
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
