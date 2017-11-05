all: bin/main

bin/main: ifndir build/btree.o build/avltree.o build/dictionary.o build/main.o
	g++ -std=c++11 -Wall -Werror -I src/header build/btree.o build/avltree.o build/dictionary.o build/main.o -o bin/main -g -O0

build/btree.o: ifndir src/btree.cpp
	g++ -std=c++11 -Wall -Werror -I src/header -c src/btree.cpp -o build/btree.o -g -O0

build/main.o: ifndir src/main.cpp
	g++ -std=c++11 -Wall -Werror -I src/header -c src/main.cpp -o build/main.o -g -O0

build/avltree.o: ifndir src/avltree.cpp
	g++ -std=c++11 -Wall -Werror -I src/header -c src/avltree.cpp -o build/avltree.o -g -O0

build/dictionary.o: ifndir src/dictionary.cpp
	g++ -std=c++11 -Wall -Werror -I src/header -c src/dictionary.cpp -o build/dictionary.o -g -O0

ifndir:
	mkdir build -p
	mkdir bin -p

.PHONY: clean

clean:
	rm build/* bin/*