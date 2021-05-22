appfile := main
CXX := g++

all:
	$(CXX) Face.cpp -o Face.o -c
	$(CXX) main.cpp Face.o -o $(appfile)

clean:
	rm *.o
	rm $(appfile)
