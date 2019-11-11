cc = g++
cflag = -c -Wall
cdep = -lX11

headers := XKeyboard.h XKeyboardGroups.h XKeyboardMod.h
sources := XKeyboard.cpp XKeyboardGroups.cpp XKeyboardMod.cpp main.cpp
objects := $(sources:.cpp=.o)
target  := xkeyboard-check
path 	:= /usr/local/bin

all: clean $(target)

$(target): $(objects)
	$(cc) $(objects) -o $(target) $(cdep)

$(objects): %.o: %.cpp $(headers)
	$(cc) $(cflag) $(sources) $(headers) $(cdep)

clean:
	rm -rf *.o *.gch $(target)

install:
	install $(target) $(path)

uninstall:
	rm -rf /usr/local/bin/$(target)
