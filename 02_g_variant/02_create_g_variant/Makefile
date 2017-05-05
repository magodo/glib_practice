objects = main.o

flags := $(shell pkg-config --libs --cflags glib-2.0)
main :
	g++ --std=c++0x -g -O0 main.cpp $(flags)

.PHONY : clean
clean : 
	rm $(objects)
