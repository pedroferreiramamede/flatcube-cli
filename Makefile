appfile := main
CXX := g++

all:
	$(CXX) -std=c++17 Face.cpp -o Face.o -c
	$(CXX) -std=c++17 Cube.cpp -o Cube.o -c
	$(CXX) -std=c++17 UI.cpp -o UI.o -c
	$(CXX) -std=c++17 main.cpp Face.o Cube.o UI.o -o $(appfile)

clean:
	rm *.o
	rm $(appfile)
