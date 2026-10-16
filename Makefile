lab1: src/main.cpp src/Ship.cpp src/Submarine.cpp src/Motorboat.cpp src/Sailboat.cpp src/Keeper.cpp src/utils/Utils.cpp src/utils/String.cpp
	g++ -std=c++11 -Wall -Wextra -g -o src/main.cpp src/Ship.cpp src/Submarine.cpp src/Motorboat.cpp src/Sailboat.cpp src/Keeper.cpp src/utils/Utils.cpp src/utils/String.cpp

clean:
	rm -f lab1