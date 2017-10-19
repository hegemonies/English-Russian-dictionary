all: bin/main

bin/main: build/btree.o build/main.o
	g++ -std=c++11 -Wall -Werror -I src/header build/btree.o build/main.o -o bin/main

build/btree.o: src/btree.cpp
	g++ -std=c++11 -Wall -Werror -I src/header -c src/btree.cpp -o build/btree.o

build/main.o: src/main.cpp
	g++ -std=c++11 -Wall -Werror -I src/header -c src/main.cpp -o build/main.o


.PHONY: clean

clean:
	rm build/* bin/*