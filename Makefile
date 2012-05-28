##
## Makefile for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
## 
## Made by vincent lemonnier
## Login   <lemonn_v@epitech.net>
## 
## Started on  Mon Apr 23 18:20:16 2012 vincent lemonnier
## Last update Mon May 28 12:01:35 2012 nicolas magere
##

NAME		= bomberman

SRC		= ./src/main.cpp	 \
		./src/AIView.cpp	 \
		./src/Camera.cpp	 \
		./src/Menu.cpp		 \
		./src/MyGame.cpp	 \
		./src/AObj.cpp		 \
		./src/Point.cpp		 \
		./src/Vector.cpp	 \
		./src/Cube.cpp		 \
		./src/Surface.cpp	 \
		./src/Plane.cpp		 \
		./src/Map.cpp		 \
		./src/APlayer.cpp	 \
		./src/Human.cpp		 \
		./src/AI.cpp		 \
		./src/Config.cpp	 \
		./src/Profile.cpp	 \
		./src/Match.cpp		 \
		./src/Pyramid.cpp	 \
		./src/ContentColor.cpp	 \
		./src/Bomb.cpp		 \
		./src/Bonus.cpp		 \
		./src/ExplodedBomb.cpp	 \
		./src/DirWalker.cpp	 \
		./src/ProfileLoader.cpp	 \
		./src/ProfileManager.cpp \
		./src/MapManager.cpp	 \
		./src/GameManager.cpp	 \
		./src/TextEdit.cpp	 \
		./src/MenuManager.cpp	 \
		./src/AMenu.cpp		 \
		./src/MainMenu.cpp	 \
		./src/Credits.cpp	 \
		./src/LoadProfile.cpp	 \
		./src/LoadSave.cpp	 \
		./src/LoadMap.cpp	 \
		./src/GameChoose.cpp	 \
		./src/MenuIA.cpp	 \
		./src/MenuMap.cpp	 \
		./src/NewProfile.cpp	 \
		./src/MenuProfile.cpp	 \
		./src/Settings.cpp	 \
		./src/Tag.cpp

OBJ		= $(SRC:.cpp=.o)

INCLUDES	= -I./lib/libgdl_gl-2012.3/include -I./src -I./Serializer

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 $(INCLUDES)

LDFLAGS		= -lGL -lGLU -lgdl_gl -lserial			\
		-L./lib/libgdl_gl-2012.3/lib -L./lib/libserial	\
		-Wl,--rpath=./lib/libgdl_gl-2012.3/lib,--rpath=./lib/SFML-1.6/lib

RM		= rm -rf

all:		gen $(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

gen:
		make all -C ./Serializer

clean:
		$(RM) $(OBJ)
		make clean -C ./Serializer

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

libclean:
		make fclean -C ./Serializer
