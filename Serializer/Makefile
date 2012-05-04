##
## Makefile
##
## Fiahil
## Fri May  4 2012

NAME	=	serializer

SRCXX	=	$(wildcard ./*.cpp)

OBJXX	=	$(SRCXX:.cpp=.o)

CXXFLAGS=	-Wall -Wextra -O3 -I./include

CXX	=	g++

%.o: %.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

all:		$(NAME)

$(NAME):	$(OBJXX)
	$(CXX) -o $(NAME) $(OBJXX)

debug:		CXXFLAGS = -Wall -Wextra -g -I./include
debug:		clean $(OBJXX)
	$(CXX) -o $(NAME) $(OBJXX)

clean:
	rm -f $(OBJXX)
	rm -Rf *~

fclean:		clean
	rm -f $(NAME)

re:		fclean all
