all: bin/main

bin/main: build/btree.o build/main.o ifndir
	g++ -std=c++11 -Wall -Werror -I src/header build/btree.o build/main.o -o bin/main

build/btree.o: src/btree.cpp ifndir
	g++ -std=c++11 -Wall -Werror -I src/header -c src/btree.cpp -o build/btree.o

build/main.o: src/main.cpp ifndir
	g++ -std=c++11 -Wall -Werror -I src/header -c src/main.cpp -o build/main.o

ifndir:
	mkdir build -p
	mkdir bin -p

.PHONY: clean

clean:
	rm build/* bin/*