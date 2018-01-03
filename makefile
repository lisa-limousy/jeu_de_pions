all: compil

compil: init.o main.o
	gcc main.o init.o -o game -lm
	
%.o: %.c
	gcc -o $@ -c - Wall -ansi $<

	@echo Compilation finie

clean:
	rm -r *.o