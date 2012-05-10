##
## Makefile
##
## Fiahil
## Fri May  4 2012

NAME	=	serializer

SRCXX	=	main.cpp

OBJXX	=	$(SRCXX:.cpp=.o)

CXXFLAGS=	-Wall -Wextra -O3 -I./include

CXX	=	g++

%.o: %.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

all:		gen $(NAME)

gen:
	bison -b Profile ProfileLoader.yxx
	bison -b Save SaveLoader.yxx
	flex ProfileScanner.lex
	flex SaveScanner.lex

$(NAME):	$(OBJXX)
	$(CXX) -o $(NAME) $(OBJXX)

debug:		CXXFLAGS = -Wall -Wextra -g -I./include
debug:		clean $(OBJXX)
	$(CXX) -o $(NAME) $(OBJXX)

clean:
	rm -f $(OBJXX)
	rm -Rf *~ *.o

fclean:		clean
	rm -f $(NAME)

re:		fclean all
