main: main.o MyTime.o 
	g++ -o main main.o MyTime.o 
main.o: main.cpp MyTime.cpp MyTime.h
	g++ -c main.cpp
MyTime.o: MyTime.cpp MyTime.h
	g++ -c MyTime.cpp
.PHONY: clean
clean: 
	rm -rf *.o main