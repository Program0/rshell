#marlo zeroth 861309346 mzero001@ucr.edu
#emmilio segovia 

all:rshell

CC=g++
CC_FLAGS=-Wall -Werror -ansi -pedantic
EXEC=rshell.out
SOURCES=$(wildcard *.cpp)
OBJECTS=$(SOURCES:.cpp=.o)




$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

clean:
	rm -f $(EXEC) $(OBJECTS)