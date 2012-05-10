##
## Makefile
##
## Fiahil
## Fri May  4 2012

NAME	=	serializer

SRCXX	=	main.cpp			\
		./Profile/lex.yy.cpp		\
		./Profile/ProfileLoader.tab.cpp	\
		./Save/lex.yy.cpp		\
		./Save/SaveLoader.tab.cpp

OBJXX	=	$(SRCXX:.cpp=.o)

CXXFLAGS=	-Wall -Wextra -O3 -I./Save -I./Profile -I ./

CXX	=	g++

%.o: %.cpp
	$(CXX) -o $@	-c $<	$(CXXFLAGS)

all:		gen $(NAME)

gen:
	@cd ./Profile &&		\
	bison ProfileLoader.ypp &&	\
	flex -o lex.yy.cpp ProfileScanner.lex &&	\
	echo "Profile Loader OK" &&	\
	echo "Profile Scanner OK"

	@cd ./Save &&			\
	bison SaveLoader.ypp &&		\
	flex -o lex.yy.cpp SaveScanner.lex &&	\
	echo "Save Loader OK" &&	\
	echo "Save Scanner OK"

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

re:		fclean all
