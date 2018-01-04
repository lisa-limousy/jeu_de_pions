all: game

game: init.o main.o
	gcc -g $^ -o $@ -lm
	@echo Compilation finie
	
%.o: %.c
	gcc -g -o $@ -c -Wall $<

clean:
	rm -rf *.o

mrproper: clean all

re: mrproper
