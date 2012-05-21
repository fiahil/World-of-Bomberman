##
## Makefile
##
## Fiahil
## Fri May  4 2012

NAME	=	../lib/libserial/libserial.a

SRCXX	=	Loader.tab.cpp		\
		lex.yy.cpp		\
		Unpackman.cpp		\
		Packman.cpp

OBJXX	=	$(SRCXX:.cpp=.o)

CXXFLAGS=	-Wall -Wextra -O3 -I./ -I../src -I../lib/libgdl_gl-2012.3/include

LDFLAGS =

CXX	=	g++

%.o: %.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

all:		$(NAME)

$(NAME):	$(OBJXX)
	ar rc $(NAME) $(OBJXX)
	ranlib $(NAME)

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
