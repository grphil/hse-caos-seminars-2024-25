CXX = g++-13
CXXFLAGS = -Wall -Wextra

all: main.o a.o
	${CXX} main.o a.o -o main

main.o: main.cpp
	${CXX} -c main.cpp -o main.o ${CXXFLAGS}

a.o: a.cpp
	${CXX} -c a.cpp -o a.o ${CXXFLAGS}

clean:
	rm -f *.o main