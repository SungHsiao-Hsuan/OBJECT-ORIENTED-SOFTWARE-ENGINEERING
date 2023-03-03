all: main

main : hw1.o passenger.o bus.o
	g++ -std=c++11 -o main hw1.o passenger.o bus.o

hw1.o: hw1.cpp
	g++ -std=c++11 -c hw1.cpp

passenger.o: passenger.cpp
	g++ -std=c++11 -c passenger.cpp

bus.o: bus.cpp
	g++ -std=c++11 -c bus.cpp

