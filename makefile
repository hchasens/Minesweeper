make: src/main.c src/def.h src/scores.c src/aux.c src/menu.c
	gcc -Wall -o minesweeper src/main.c src/def.h src/scores.c src/aux.c src/menu.c
	#for future use
	#if /bin/gcc != null
		#gcc -Wall -o minesweeper src/main.c src/def.h src/scores.c src/aux.c src/menu.c
	#else
		#clang -Wall -o minesweeper src/main.c src/def.h src/scores.c src/aux.c src/menu.c
run: minesweeper
	./minesweeper

clean:
	rm minesweeper
