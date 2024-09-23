all:
	g++ -I src/include -L src/lib -o main code/main.cpp code/screen.cpp code/swarm.cpp code/particle.cpp -lmingw32 -lSDL2main -lSDL2