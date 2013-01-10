CXX=g++
LD=g++
DTEST=-DTEST
CFLAGS=-Wall -pedantic -Wno-long-long

all: program

program: main.o utils.o gradientdescent.o conjugategradients.o simplematrix.o simplevector.o compressedmatrix.o
	$(LD) -o non main.o utils.o gradientdescent.o conjugategradients.o simplematrix.o simplevector.o compressedmatrix.o

test: tests.o utils.o gradientdescent.o conjugategradients.o simplematrix.o simplevector.o compressedmatrix.o
	$(LD) -o test tests.o utils.o gradientdescent.o conjugategradients.o simplematrix.o simplevector.o compressedmatrix.o

main.o: main.cpp
	$(CXX) $(CFLAGS) -c -o main.o main.cpp

utils.o: utils.cpp
	$(CXX) $(CFLAGS) -c -o utils.o utils.cpp

gradientdescent.o: gradientdescent.cpp
	$(CXX) $(CFLAGS) -c -o gradientdescent.o gradientdescent.cpp

conjugategradients.o: conjugategradients.cpp
	$(CXX) $(CFLAGS) -c -o conjugategradients.o conjugategradients.cpp

simplematrix.o: simplematrix.cpp
	$(CXX) $(CFLAGS) -c -o simplematrix.o simplematrix.cpp

simplevector.o: simplevector.cpp
	$(CXX) $(CFLAGS) -c -o simplevector.o simplevector.cpp

compressedmatrix.o: compressedmatrix.cpp
	$(CXX) $(CFLAGS) -c -o compressedmatrix.o compressedmatrix.cpp

tests.o: tests.cpp
	$(CXX) $(CFLAGS) $(DTEST) -c -o tests.o tests.cpp

clean:
	rm -f non test main.o tests.o utils.o gradientdescent.o conjugategradients.o simplematrix.o simplevector.o compressedmatrix.o
