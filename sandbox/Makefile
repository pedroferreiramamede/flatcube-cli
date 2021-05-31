appfile := main
CXX := g++

all:
	$(CXX) -std=c++0x Face.cpp -o Face.o -c
	$(CXX) -std=c++0x Cube.cpp -o Cube.o -c
	$(CXX) -std=c++0x UI.cpp -o UI.o -c
	$(CXX) -std=c++0x main.cpp Face.o Cube.o UI.o -o $(appfile)

clean:
	rm *.o
	rm $(appfile)
