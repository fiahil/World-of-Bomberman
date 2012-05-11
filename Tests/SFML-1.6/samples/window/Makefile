EXEC = window
OBJ  = Window.o

all: $(EXEC)

window: $(OBJ)
	g++ $(LDFLAGS) -o ./$@ $(OBJ) -L/usr/lib64/ -lsfml-window -lsfml-system -lGLU -lGL

%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf ./$(EXEC)
