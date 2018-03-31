all:
	g++ -o main main.cpp Model/Camera.cpp

test:
	g++ -o test test.cpp Model/Camera.cpp
