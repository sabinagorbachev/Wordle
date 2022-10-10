CXX=g++
#CXXFLAGS=-std=c++14 -MMD
CXXFLAGS=-std=c++14 -g -Wall -MMD
OBJECTS=main.o wordle.o
DEPENDS=$(OBJECTS:.o=.d)
EXEC=wordle


${EXEC}: ${OBJECTS}
		${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

main.o: main.cc wordle.h
wordle.o: wordle.cc wordle.h

clean:
		rm ${DEPENDS} ${OBJECTS} ${EXEC}

.PHONY: clean
