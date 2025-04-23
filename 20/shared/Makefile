CXX = g++-13
CXXFLAGS = -Wall -Wextra

all: main.o liba.so
	${CXX} main.o -o main -L . -l a

main.o: main.cpp
	${CXX} -c main.cpp -o main.o ${CXXFLAGS}

liba.so: a.cpp
	${CXX} -fPIC --shared a.cpp -o liba.so ${CXXFLAGS}

clean:
	rm -f *.o *.so main
