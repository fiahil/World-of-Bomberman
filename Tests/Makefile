##
## Makefile for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
## 
## Made by vincent lemonnier
## Login   <lemonn_v@epitech.net>
## 
## Started on  Mon Apr 23 18:20:16 2012 vincent lemonnier
## Last update Fri May 11 19:19:11 2012 nicolas magere
##

NAME=		bomberman

SRC=		main.cpp	\
		Camera.cpp	\
		MyGame.cpp

OBJ=		$(SRC:.cpp=.o)

INCLUDES=	-I./libgdl_gl-2012.1/include

CXX=		g++

CXXFLAGS=	-Wall -W -Werror -Wextra $(INCLUDES)

LDFLAGS=	-lGL -lGLU -L./libgdl_gl-2012.1/lib -lgdl_gl -Wl,--rpath=./libgdl_gl-2012.1/lib,--rpath=./SFML-1.6/lib

RM=		rm -f

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all