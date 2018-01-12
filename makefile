all: game

game: main.o init.o play.o gestion.o
	gcc main.o init.o play.o gestion.o
	
main.o: main.c init.h play.h
	gcc -c main.c -Wall

init.o: init.c init.h
	gcc -c init.c -Wall

play.o: play.c init.h play.h
	gcc -c play.c -Wall
    
gestion.o: gestion.c init.h play.h gestion.h
	gcc -c gestion.c -Wall


