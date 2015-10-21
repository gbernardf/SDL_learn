CC=g++
CFLAGS=-c -Wall -std=c++11
LIBS = -lSDL2 -lSDL2_ttf -lSDL2_image


all: game

game: main.o functions.o Sprite.o Game.o GameState.o TitleScreen.o GameStateManager.o
	$(CC) main.o functions.o Sprite.o Game.o GameState.o TitleScreen.o GameStateManager.o -o game $(LIBS)

main.o: main.cpp functions.h \
	GameStateManager.h \
	GameState.h \
	Game.h \
	Sprite.h \
	TitleScreen.h
	$(CC) $(CFLAGS) main.cpp $(LIBS)


functions.o: functions.cpp functions.h
	$(CC) $(CFLAGS) functions.cpp $(LIBS)


Sprite.o: Sprite.cpp Sprite.h \
		functions.h
	$(CC) $(CFLAGS) Sprite.cpp $(LIBS)


Game.o: Game.cpp Game.h \
		GameState.h \
		functions.h \
		Sprite.h \
		TitleScreen.h
	$(CC) $(CFLAGS) Game.cpp $(LIBS)


GameState.o: GameState.cpp GameState.h \
		functions.h
	$(CC) $(CFLAGS) GameState.cpp $(LIBS)


TitleScreen.o: TitleScreen.cpp TitleScreen.h \
		GameState.h \
		functions.h \
		Sprite.h
	$(CC) $(CFLAGS) TitleScreen.cpp $(LIBS)


GameStateManager.o: GameStateManager.cpp GameStateManager.h \
		functions.h \
		GameState.h \
		Game.h \
		Sprite.h \
		TitleScreen.h
	$(CC) $(CFLAGS) GameStateManager.cpp $(LIBS)


clean:
	rm -rf *.o game