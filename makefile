all: game

game: init.o main.o
	gcc $^ -o $@ -lm
	@echo Compilation finie
	
%.o: %.c
	gcc -o $@ -c -Wall $<

clean:
	rm -rf *.o

mrproper: clean all

re: mrproper
