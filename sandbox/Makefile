appfile := main
CXX := g++

all:
	$(CXX) Face.cpp -o Face.o -c
	$(CXX) Cube.cpp -o Cube.o -c
	$(CXX) main.cpp Face.o Cube.o -o $(appfile)

clean:
	rm *.o
	rm $(appfile)
