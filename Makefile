##
## Makefile for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
## 
## Made by vincent lemonnier
## Login   <lemonn_v@epitech.net>
## 
## Started on  Mon Apr 23 18:20:16 2012 vincent lemonnier
## Last update Fri May 18 13:47:55 2012 vincent lemonnier
##

NAME		= bomberman

SRC		= ./src/main.cpp	\
		./src/Camera.cpp	\
		./src/Menu.cpp		\
		./src/MyGame.cpp	\
		./src/AObj.cpp		\
		./src/Point.cpp		\
		./src/Vector.cpp	\
		./src/Cube.cpp		\
		./src/Plane.cpp		\
		./src/Map.cpp		\
		./src/APlayer.cpp	\
		./src/Human.cpp		\
		./src/AI.cpp		\
		./src/Config.cpp	\
		./src/Profile.cpp	\
		./src/Match.cpp		\
		./src/AMenu.cpp		\
		./src/Pyramid.cpp	\
		./src/MenuManager.cpp	\
		./src/ContentColor.cpp	\
		./src/Bomb.cpp		\
		./src/ExplodedBomb.cpp	\
		./src/Tag.cpp		\
		./src/DirWalker.cpp	\
		./src/ProfileManager.cpp

OBJ		= $(SRC:.cpp=.o)

INCLUDES	= -I./lib/libgdl_gl-2012.3/include

CXX		= g++

CXXFLAGS	= -Wall -Wextra $(INCLUDES)

LDFLAGS		= -lGL -lGLU -L./lib/libgdl_gl-2012.3/lib -lgdl_gl -Wl,--rpath=./lib/libgdl_gl-2012.3/lib,--rpath=./lib/SFML-1.6/lib

RM		= rm -rf

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
