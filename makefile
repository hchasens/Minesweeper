make: main.c def.h scores.c aux.c menu.c
	gcc -Wall -o minesweeper main.c def.h scores.c aux.c menu.c


# run hasadependency:lab10
# lab10 comesfromthefirst line, the compilation

run: minesweeper
	./minesweeper

clean:
	rm minesweeper
