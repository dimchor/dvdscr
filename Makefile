SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
IMGUI_FLAGS = -lImGui-SFML
FLAGS = $(SFML_FLAGS) $(IMGUI_FLAGS)

output: main.o
	g++ main.o -o dvdscr $(FLAGS)

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o
