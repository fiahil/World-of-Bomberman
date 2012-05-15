##
## Makefile
##
## Fiahil
## Fri May  4 2012

NAME	=	serializer

SRCXX	=	Loader.tab.cpp		\
		lex.yy.cpp		\
		main.cpp		\
		Packman.cpp		\
		../src/Profile.cpp	\
		../src/Config.cpp	\
		../src/Match.cpp

OBJXX	=	$(SRCXX:.cpp=.o)

CXXFLAGS=	-Wall -Wextra -O3 -I./ -I../src -I../lib/libgdl_gl-2012.3/include

CXX	=	g++

%.o: %.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

all:		$(NAME)

$(NAME):	$(OBJXX)
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

lex.yy.o:	lex.yy.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

Loader.tab.o:	Loader.tab.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

lex.yy.cpp:	Scanner.lex Loader.tab.cpp
	flex -o lex.yy.cpp Scanner.lex

Loader.tab.cpp:	Loader.ypp
	bison Loader.ypp
