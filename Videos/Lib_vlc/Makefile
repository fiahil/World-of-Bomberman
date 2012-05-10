## 
## Makefile for exe in /tmp/Makefile
## 
## Made by nicolas magere
## Login   <magere_n@epitech.net>
## 
## Started on  Thu May  3 16:03:40 2012 nicolas magere
## Last update Thu May  3 16:12:47 2012 nicolas magere
## 

NAME=		exe

SRC=		$(wildcard = ./*.c)

OBJ=		$(SRC:.c=.o)

CFLAGS=		-W -Wall -Wextra
LDFLAGS=	-lvlc

GCC=		gcc

RM=		rm -rf

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) *~

fclean:		clean
		$(RM) $(NAME)

re:		fclean all