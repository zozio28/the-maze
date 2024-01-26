LDFLAGS= -lncursesw

exe: clean maze.o game.o tree.o location.o player.o menu.o main.o
	gcc player.o maze.o game.o tree.o location.o menu.o main.o -o exe ${LDFLAGS}

maze.o: maze.c maze.h
	gcc -c -Wall maze.c -o maze.o ${LDFLAGS}

game.o: game.c game.h
	gcc -c -Wall game.c -o game.o ${LDFLAGS}

tree.o: tree.c tree.h
	gcc -c -Wall tree.c -o tree.o ${LDFLAGS}

location.o: location.c location.h
	gcc -c -Wall location.c -o location.o ${LDFLAGS}

player.o: player.c player.h
	gcc -c -Wall player.c -o player.o ${LDFLAGS}

menu.o: menu.c menu.h
	gcc -c -Wall menu.c -o menu.o ${LDFLAGS}
	
main.o: main.c maze.h
	gcc -c -Wall main.c -o main.o ${LDFLAGS}

clean:
	rm -f *.o