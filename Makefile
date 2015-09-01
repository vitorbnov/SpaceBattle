all:
	g++ -std=c++11 -Wall -g -Iinclude -c LUtil.cpp -o obj/Debug/LUtil.o
	g++ -std=c++11 -Wall -g -Iinclude -c main.cpp -o obj/Debug/main.o
	g++ -std=c++11 -Wall -g -Iinclude -c src/Aircraft.cpp -o obj/Debug/src/Aircraft.o
	g++ -std=c++11 -Wall -g -Iinclude -c src/Asteroid.cpp -o obj/Debug/src/Asteroid.o
	g++ -std=c++11 -Wall -g -Iinclude -c src/Dot.cpp -o obj/Debug/src/Dot.o
	g++ -std=c++11 -Wall -g -Iinclude -c src/Game.cpp -o obj/Debug/src/Game.o
	g++ -std=c++11 -Wall -g -Iinclude -c src/Gun.cpp -o obj/Debug/src/Gun.o
	g++ -std=c++11 -Wall -g -Iinclude -c src/Item.cpp -o obj/Debug/src/Item.o
	g++ -std=c++11 -Wall -g -Iinclude -c src/Polygon.cpp -o obj/Debug/src/Polygon.o
	g++ -std=c++11 -Wall -g -Iinclude -c src/Shot.cpp -o obj/Debug/src/Shot.o
	g++  -o bin/Debug/SpaceBattle obj/Debug/LUtil.o obj/Debug/main.o obj/Debug/src/Aircraft.o obj/Debug/src/Asteroid.o obj/Debug/src/Dot.o obj/Debug/src/Game.o obj/Debug/src/Gun.o obj/Debug/src/Item.o obj/Debug/src/Polygon.o obj/Debug/src/Shot.o  -lGL -lGLU -lglut  -lGL -lX11 

