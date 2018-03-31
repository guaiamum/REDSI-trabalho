allc: clean all

all: main.o Camera.o
	g++ -o main main.o Camera.o

main.o: main.cpp
	g++ -c main.cpp

Camera.o: Model/Camera.cpp
	g++ -c Model/Camera.cpp

#******************************
#TESTING AND CLEANING
test: Camera.o
	clear
	g++ -o test test.cpp Camera.o
	./test

#******************************
# CLEANING CONSOLE AND DIRECTORY
clean:
	clear
	rm -rf *o main

.PHONY: test
