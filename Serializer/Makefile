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

all:		gen $(NAME)

gen:
	bison Parser.y
	flex Scanner.lex

$(NAME):	$(OBJXX)
	$(CXX) -o parser.o	-c Parser.tab.c $(CXXFLAGS)
	$(CXX) -o scanner.o	-c lex.yy.cc $(CXXFLAGS)
	$(CXX) -o $(NAME) parser.o scanner.o $(OBJXX)

debug:		CXXFLAGS = -Wall -Wextra -g -I./include
debug:		clean $(OBJXX)
	$(CXX) -o $(NAME) $(OBJXX)

clean:
	rm -f $(OBJXX)
	rm -Rf *~ *.o

fclean:		clean
	@rm -f Parser.tab.c Parser.tab.h location.hh position.hh stack.hh lex.yy.cc
	rm -f $(NAME)

re:		fclean all
