SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system
IMGUI_FLAGS = -lImGui-SFML
LFLAGS = $(SFML_FLAGS) $(IMGUI_FLAGS)
CFLAGS = -std=c++20

output: main.o Picture.o Exception.o Utilities.o Settings.o
	g++ main.o Picture.o Exception.o Utilities.o Settings.o -o dvdscr $(LFLAGS)

main.o: main.cpp
	g++ -c main.cpp $(CFLAGS)

Picture.o: Picture.cpp
	g++ -c Picture.cpp $(CFLAGS)

Exception.o: Exception.cpp
	g++ -c Exception.cpp $(CFLAGS)

Utilities.o: Utilities.cpp
	g++ -c Utilities.cpp $(CFLAGS)

Settings.o: Settings.cpp
	g++ -c Settings.cpp $(CFLAGS)

clean:
	rm *.o
