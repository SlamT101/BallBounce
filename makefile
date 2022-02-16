all: compile link

compile:
	g++ -I src/include -c main.cpp
link:
	g++ Main.o -o main -L src/Lib -l sfml-graphics -l sfml-window -l sfml-system