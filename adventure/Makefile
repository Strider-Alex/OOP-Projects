author = Yang Kefan
objects = main.o player.o room.o prison.o lobby.o cave.o map.o game.o
app = adventure
cc = g++
std = c++0x
app: $(objects)
	$(cc) -std=$(std) $(objects) -o $(app)
main.o: main.cpp game.h
	$(cc) -std=$(std) -c main.cpp
player.o: player.cpp player.h
	$(cc) -std=$(std) -c player.cpp
room.o: room.cpp room.h
	$(cc) -std=$(std) -c room.cpp
lobby.o: lobby.h room.h
	$(cc) -std=$(std) -c lobby.cpp
prison.o: prison.h room.h
	$(cc) -std=$(std) -c prison.cpp
cave.o: cave.h room.h
	$(cc) -std=$(std) -c cave.cpp
map.o: map.cpp map.h room.h lobby.h cave.h prison.h
	$(cc) -std=$(std) -c map.cpp
game.o: game.cpp game.h map.h room.h player.h
	$(cc) -std=$(std) -c game.cpp
clean:
	rm $(app) *.o
