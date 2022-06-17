appfile := main
CXX := g++
CXXFLAGS := -std=c++17

all:
	$(CXX) $(CXXFLAGS) Face.cpp -o Face.o -c
	$(CXX) $(CXXFLAGS) Cube.cpp -o Cube.o -c
	$(CXX) $(CXXFLAGS) UI.cpp -o UI.o -c
	$(CXX) $(CXXFLAGS) main.cpp Face.o Cube.o UI.o -o $(appfile)
	$(CXX) $(CXXFLAGS) easterEgg.c -lpthread -lncurses -o easterEgg

clean:
	rm *.o
	rm $(appfile)
