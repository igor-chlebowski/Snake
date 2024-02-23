main: main.cpp
	g++ -c main.cpp Game.cpp Player.cpp 
	g++ main.cpp Game.cpp Player.cpp  -lsfml-graphics -lsfml-window -lsfml-system


