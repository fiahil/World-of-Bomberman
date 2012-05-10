##
## Makefile
##
## Fiahil
## Fri May  4 2012

NAME	=	serializer

SRCXX	=	main.cpp	\
		lex.yy.cpp	\
		Loader.tab.cpp

OBJXX	=	$(SRCXX:.cpp=.o)

CXXFLAGS=	-Wall -Wextra -O3 -I./

CXX	=	g++

%.o: %.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

all:		gen $(NAME)

gen:
	@bison Loader.ypp &&			\
	flex -o lex.yy.cpp Scanner.lex &&	\
	echo "Loader OK"

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
	@rm -f Loader.tab.cpp lex.yy.cpp location.hh position.hh stack.hh

re:		fclean all
