all: levenshtein.o

levenshtein.o: levenshtein.cpp levenshtein.hpp
	g++ -std=c++11 -c levenshtein.cpp

tests: tests.exe
	./tests.exe

tests.exe: levenshtein.o tests.o
	g++ -std=c++11 -o tests.exe tests.o levenshtein.o

tests.o: tests.cpp
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f levenshtein.o
	rm -f tests.o
	rm -f tests.exe

