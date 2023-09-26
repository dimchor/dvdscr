SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
IMGUI_FLAGS = -lImGui-SFML
FLAGS = $(SFML_FLAGS) $(IMGUI_FLAGS)

output: main.o Picture.o Exception.o
	g++ main.o Picture.o Exception.o -o dvdscr $(FLAGS)

main.o: main.cpp
	g++ -c main.cpp

Picture.o: Picture.cpp
	g++ -c Picture.cpp

Exception.o: Exception.cpp
	g++ -c Exception.cpp

clean:
	rm *.o
