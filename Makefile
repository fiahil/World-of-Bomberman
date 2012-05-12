##
## Makefile for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
## 
## Made by vincent lemonnier
## Login   <lemonn_v@epitech.net>
## 
## Started on  Mon Apr 23 18:20:16 2012 vincent lemonnier
## Last update Sat May 12 17:38:44 2012 nicolas magere
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
		./src/Match.cpp

OBJ		= $(SRC:.cpp=.o)

INCLUDES	= -I./lib/libgdl_gl-2012.3/include

CXX		= g++

CXXFLAGS	= -Wall -W -Werror -Wextra $(INCLUDES)

LDFLAGS		= -lGL -lGLU -L./lib/libgdl_gl-2012.3/lib -lgdl_gl -Wl,--rpath=./lib/libgdl_gl-2012.3/lib,--rpath=./lib/SFML-1.6/lib

RM		= rm -rf
DUST		= ./*~ Gameplay/*~ lib/*~ Ressources/*~ Serializer/*~ src/*~ TestEvent/*~ Tests/*~ Videos/*~

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ)
		$(RM) $(DUST)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all