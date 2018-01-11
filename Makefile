all: bin/main

bin/main: ifndir build/btree.o build/avltree.o build/dictionary.o build/main.o
	g++ -std=c++11 -pthread -Wl,--no-as-needed -Wall -I src/header build/btree.o build/avltree.o build/dictionary.o build/main.o -o bin/main -time
	

build/btree.o: ifndir src/btree.cpp
	g++ -std=c++11 -Wall -I src/header -c src/btree.cpp -o build/btree.o -time

build/main.o: ifndir src/main.cpp
	g++ -std=c++11 -Wall -I src/header -c src/main.cpp -o build/main.o -time

build/avltree.o: ifndir src/avltree.cpp
	g++ -std=c++11 -Wall -I src/header -c src/avltree.cpp -o build/avltree.o -time

build/dictionary.o: ifndir src/dictionary.cpp
	g++ -std=c++11 -pthread -Wl,--no-as-needed -Wall -I src/header -c src/dictionary.cpp -o build/dictionary.o -time

ifndir:
	mkdir build -p
	mkdir bin -p

.PHONY: clean

clean:
	rm build/* bin/*