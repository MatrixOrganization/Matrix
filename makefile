CXX=g++
EXEC=exeMatrix

exeMatrix: Main.o Matrix.o
	$(CXX) -Wall -o $(EXEC) Main.o Matrix.o

main.o: Main.cpp Matrix.h
	$(CXX) -Wall -o Main.o -c Matrix.cpp

matrix.o: Matrix.cpp
	$(CXX) -Wall -o Matrix.o -c Matrix.cpp

clean:
	rm -rf *.o
	rm -rf *.exe
	rm -rf exeMatrix
begin:
	clear && make exeMatrix && make ./$(EXEC)
