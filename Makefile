build:
	gcc altul.c -lglut -lGLU -lGL -o cub.out -Wall
run:
	./cub.out
clear:
	rm cub.out
