##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

DEBUG	=	-g

FLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

MYLIB	=	-L lib/ -lcrim

SRC	=	src/*.c

SRCB	=	bonus/*.c

NAME	=	radar

NAMEB	=	radar

all: $(NAME)

$(NAME):	$(SRC)
	make -C lib/ && make clean -C lib/
	gcc -o $(NAME) $(SRC) $(FLAGS) $(MYLIB) -g3

check:
	make -C lib/ && make clean -C lib/
	gcc -o $(NAME) $(SRC) $(FLAGS) $(MYLIB) $(DEBUG)

bonus:	$(SRCB)
	make -C lib/ && make clean -C lib/
	gcc -o $(NAMEB) $(SRCB) $(FLAGS) $(MYLIB)

clean:
	rm -f *~
	rm -f *.o

fclean:	clean
	make fclean -C lib/
	rm -f $(NAME)

re: fclean all
