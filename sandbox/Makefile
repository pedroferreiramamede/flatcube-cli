appfile := main
CXX := g++

all:
	$(CXX) Face.cpp -o Face.o -c
	$(CXX) Cube.cpp -o Cube.o -c
	$(CXX) UI.cpp -o UI.o -c
	$(CXX) main.cpp Face.o Cube.o UI.o -o $(appfile)

clean:
	rm *.o
	rm $(appfile)
