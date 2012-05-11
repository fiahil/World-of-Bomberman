##
## Makefile for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
## 
## Made by vincent lemonnier
## Login   <lemonn_v@epitech.net>
## 
## Started on  Mon Apr 23 18:20:16 2012 vincent lemonnier
## Last update Fri May 11 09:36:56 2012 vincent lemonnier
##

NAME=		bomberman

SRC=		./src/main.cpp		\
		./src/Camera.cpp	\
		./src/GamePlay.cpp	\
		./src/AObj.cpp		\
		./src/Point.cpp		\
		./src/Vector.cpp	\
		./src/Cube.cpp		\
		./src/Plane.cpp		\
		./src/Map.cpp

OBJ=		$(SRC:.cpp=.o)

INCLUDES=	-I./lib/libgdl_gl-2012.3/include

CXX=		g++

CXXFLAGS=	-Wall -W -Werror -Wextra $(INCLUDES)

LDFLAGS=	-lGL -lGLU -L./lib/libgdl_gl-2012.3/lib -lgdl_gl -Wl,--rpath=./lib/libgdl_gl-2012.3/lib,--rpath=./lib/SFML-1.6/lib

RM=		rm -f

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all