## 
## Makefile for exe in /home/magere_n/work/projets_tek2/bomberman/Git/Bomberman/Profile/Makefile
## 
## Made by nicolas magere
## Login   <magere_n@epitech.net>
## 
## Started on  Thu May 10 11:53:59 2012 nicolas magere
## Last update Thu May 10 11:54:16 2012 nicolas magere
## 

NAME=		exe

SRC=		$(wildcard = ./*.cpp)

OBJ=		$(SRC:.cpp=.o)

CXXFLAGS=	-Wall -Wextra

CC=		g++

RM=		rm -rf

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) *~

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
