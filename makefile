exe: clean maze.o main.o
	gcc maze.o main.o -o exe

maze.o: maze.c maze.h
	gcc -c -Wall maze.c -o maze.o

main.o: main.c maze.h
	gcc -c -Wall main.c -o main.o

clean:
	rm -f *.o