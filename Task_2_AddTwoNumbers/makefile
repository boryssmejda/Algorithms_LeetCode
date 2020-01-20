CC=g++
CPPFLAGS= -g -std=c++17 -Wall -pedantic -Wextra -Wshadow -Wpointer-arith

list: main.o
	$(CC) $(CPPFLAGS) $< -o $@ 

main.o: main.cpp
	$(CC) $(CPPFLAGS) $^ -c

clean:
	rm -f main.o list