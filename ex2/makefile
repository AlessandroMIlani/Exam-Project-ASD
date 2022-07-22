#MAKEFILE Ex2
CC = gcc
CFLAG = -Wall -O3 
INCLUDES = src/*.h
COMMON_DEPS = $(INCLUDES)


all :  mkdir main_ex2 test

main : mkdir main_ex2

test : mkdir unit_test

# create obj e build folder
mkdir:
	mkdir -p build
	mkdir -p obj

main_ex2: obj/main_skip.o obj/skiplist_aux.o obj/skiplist.o
	$(CC) $(CFLAG) obj/main_skip.o obj/skiplist.o obj/skiplist_aux.o -o build/main_ex2

obj/main_skip.o: src/main_skip.c 
	$(CC) $(CFLAG) -c src/main_skip.c -o obj/main_skip.o

obj/skiplist_aux.o: src/skiplist.c
	$(CC) $(CFLAG) -c src/skiplist_aux.c -o obj/skiplist_aux.o

obj/skiplist.o: src/skiplist.c
	$(CC) $(CFLAG) -c src/skiplist.c -o obj/skiplist.o

obj/unit_testing.o: src/unit_test/unit_testing.c
	$(CC) $(CFLAG) -c src/unit_test/unit_testing.c -o obj/unit_testing.o

unit_test: obj/skiplist.o obj/skiplist_aux.o obj/unit_testing.o obj/unity.o 
	$(CC) $(CFLAG) obj/skiplist.o obj/skiplist_aux.o obj/unit_testing.o obj/unity.o -o build/test

obj/unity.o: 
	$(CC) $(CFLAG) -c src/unit_test/unity.c -o obj/unity.o

clean : 
	rm ./obj/*
	rm ./build/*
