##
## Makefile
##
## Fiahil
## Fri May  4 2012

NAME	=	serializer

SRCXX	=	main.cpp		\
		Packman.cpp

OBJXX	=	$(SRCXX:.cpp=.o)	\
		lex.yy.cpp		\
		Loader.tab.cpp


CXXFLAGS=	-Wall -Wextra -O3 -I./

CXX	=	g++

%.o: %.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

all:		$(NAME)

gen:
	bison Loader.ypp
	flex -o lex.yy.cpp Scanner.lex

$(NAME):	gen $(OBJXX)
	$(CXX) -o $(NAME) $(OBJXX)

debug:		CXXFLAGS = -Wall -Wextra -g
debug:		clean $(OBJXX)
	$(CXX) -o $(NAME) $(OBJXX)

clean:
	rm -f $(OBJXX)
	rm -Rf *~ *.o

fclean:		clean
	rm -f $(NAME)
	@rm -f Loader.tab.cpp Loader.tab.hpp
	@rm -f lex.yy.cpp location.hh position.hh stack.hh

re:		fclean all
