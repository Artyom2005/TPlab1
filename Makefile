lab1: main.cpp Ship.cpp Submarine.cpp Motorboat.cpp Sailboat.cpp Keeper.cpp utils/Utils.cpp utils/String.cpp
	g++ -std=c++11 -Wall -Wextra -g -o lab1 main.cpp Ship.cpp Submarine.cpp Motorboat.cpp Sailboat.cpp Keeper.cpp utils/Utils.cpp utils/String.cpp

clean:
	rm -f lab1