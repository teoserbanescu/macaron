build:
	gcc main.cpp -lglut -lGLU -lGL -o tea.out -Wall
run:
	./tea.out
clear:
	rm tea.out
