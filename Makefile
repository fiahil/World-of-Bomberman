##
## Makefile for Bomberman in /home/lemonn_v/Projects/C++/Bomberman
## 
## Made by vincent lemonnier
## Login   <lemonn_v@epitech.net>
## 
## Started on  Mon Apr 23 18:20:16 2012 vincent lemonnier
##

NAME		= bomberman

SRC		= ./src/main.cpp	 \
		./src/Sound.cpp		 \
		./src/AIView.cpp	 \
		./src/Camera.cpp	 \
		./src/Bomberman.cpp	 \
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
		./src/SaveManager.cpp	 \
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
		./src/SettingsChoose.cpp \
		./src/Settings.cpp	 \
		./src/SkinChoose.cpp	 \
		./src/TeamMenu.cpp	 \
		./src/MenuPause.cpp	 \
		./src/MenuStats.cpp	 \
		./src/Stat.cpp		 \
		./src/GameResult.cpp	 \
		./src/Loading.cpp	 \
		./src/Tag.cpp

OBJ		= $(SRC:.cpp=.o)

INCLUDES	= -I./lib/libgdl_gl-2012.3/include -I./lib/libfmodex/inc -I./src -I./Serializer -I/usr/include/opencv -I./lib/SFML-2.0/include -I./lib/SFML-2.0/include/SFML/Window

CXX		= g++

CXXFLAGS	= -Wall -Wextra -O3 -DNDEBUG $(INCLUDES)

LDFLAGS		= -lGL -lGLU -lgdl_gl -lserial -lfmodex		\
		  -lopencv_imgproc -lopencv_highgui		\
		  -lsfml-window-s -lsfml-system-s		\
		  -lX11 -lrt -lXrandr				\
		-L./lib/SFML-2.0/lib/				\
		-L./lib/libgdl_gl-2012.3/lib -L./lib/libserial	\
		-L./lib/libfmodex/lib 				\
		-Wl,--rpath=./lib/libgdl_gl-2012.3/lib,--rpath=./lib/SFML-1.6/lib,--rpath=./lib/libfmodex/lib

RM		= rm -rf
DUST		= *~ src/*~ Serializer/*~

all:		gen $(NAME)

$(NAME):	$(OBJ)
		$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

gen:
		make all -C ./Serializer

clean:
		$(RM) $(OBJ) $(DUST)
		make clean -C ./Serializer

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

libclean:
		make fclean -C ./Serializer

modelclean:
		$(RM) Ressources/models/*.fbm*
