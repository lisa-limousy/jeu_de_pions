all: game

game: init.o main.o
	gcc $^ -o $@ -lm
	
%.o: %.c
	gcc -o $@ -c -Wall $<
	@echo Compilation finie

clean:
	rm -rf *.o

mrproper: clean all

re: mrproper
