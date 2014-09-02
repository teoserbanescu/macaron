build:
	gcc altul.c vector.c -lglut -lGLU -lGL -lm -o cub.out -Wall
run:
	./cub.out
clear:
	rm cub.out
