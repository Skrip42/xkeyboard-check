cc = g++
cflag = -c -Wall
cdep = -lX11

headers := XKeyboard.h XKeyboardGroups.h XKeyboardMod.h
sources := XKeyboard.cpp XKeyboardGroups.cpp XKeyboardMod.cpp main.cpp
objects := $(sources:.cpp=.o)
target  := keyboard-state

all: clean $(target)

$(target): $(objects)
	$(cc) $(objects) -o $(target) $(cdep)

$(objects): %.o: %.cpp $(headers)
	$(cc) $(cflag) $(sources) $(headers) $(cdep)

clean:
	rm -rf *.o *.gch $(target)
