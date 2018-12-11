
all: main.o
	g++ main.cpp -o count

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm count main.o

