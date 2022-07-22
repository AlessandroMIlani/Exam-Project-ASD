#MAKEFILE Ex1 
CC = gcc
CFLAG = -Wall -O3 
INCLUDES = src/*.h
COMMON_DEPS = $(INCLUDES)


all : mkdir sort test

# create bin e build folder
mkdir:
	mkdir -p bin
	mkdir -p build

# compile all files 
sort: build/sorting_lib.o build/generic_data.o build/sorting_main.o $(COMMON_DEPS)
	$(CC) $(CFLAG) build/sorting_lib.o build/generic_data.o build/sorting_main.o -o bin/sort

# compile sorting_lib.c
build/sorting_lib.o: 
	$(CC) $(CFLAG) -c src/sorting_lib.c -o build/sorting_lib.o

# compile generic_data.c
build/generic_data.o: 
	$(CC) $(CFLAG) -c src/generic_data.c -o build/generic_data.o

# compile sorting_main.c 
build/sorting_main.o: 
	$(CC) $(CFLAG) -c src/sorting_main.c -o build/sorting_main.o


test: build/sorting_lib.o build/generic_data.o build/sorting_main_test.o build/unity.o $(COMMON_DEPS)
	$(CC) $(CFLAG) build/sorting_lib.o build/generic_data.o build/sorting_main_test.o build/unity.o -o bin/test

build/unity.o: 
	$(CC) $(CFLAG) -c src/unit_test/unity.c -o build/unity.o

build/sorting_main_test.o: 
	$(CC) $(CFLAG) -c src/unit_test/sorting_main_test.c -o build/sorting_main_test.o

# clean all files 
clean:
	rm -rf build/* bin/*

