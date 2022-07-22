#include "generic_data.h"
#include<stdlib.h>
#include<stdio.h>

void insert(GenericArray* ord_array, int position, void* val) {
	if (position < ord_array->el_num) {
		(ord_array->array)[position] = val;
	}
	else {
		printf("insert:array out of bounds acess");
		exit(EXIT_FAILURE);
	}
}

void swap(GenericArray* ord_array, int first, int second) {
	if (first < ord_array->el_num && second < ord_array->el_num) {
		void* temp = (ord_array->array)[first];
		(ord_array->array)[first] = (ord_array->array)[second];
		(ord_array->array)[second] = temp;
	}
	else {
		printf("swap:array out of bounds acess");
		exit(EXIT_FAILURE);
	}
}

void move(GenericArray* ord_array, int position, int next_position) {
	if (position < ord_array->el_num && next_position < ord_array->el_num) {
		(ord_array->array)[next_position] = (ord_array->array)[position];
	}
	else {
		printf("move:array out of bounds acess");
		exit(EXIT_FAILURE);
	}
}

void array_add(GenericArray* ord_array, void* element) {
	if (ord_array == NULL) {
		fprintf(stderr, "array_add: array parameter cannot be NULL");
		exit(EXIT_FAILURE);
	}
	if (element == NULL) {
		fprintf(stderr, "array_add: element parameter cannot be NULL");
	}
	if (ord_array->el_num >= ord_array->size) {
		ord_array->array = (void**)realloc(ord_array->array, 2 * (ord_array->size) * sizeof(void*));
		if (ord_array->array == NULL) {
			fprintf(stderr, "array: unable to reallocate memory to host the new element");
			exit(EXIT_FAILURE);
		}
		ord_array->size = ord_array->size * 2;
	}
	(ord_array->array)[ord_array->el_num] = element;
	ord_array->el_num++;
}

//sostituisco num_elements con una costante 
GenericArray* array_create(int size) {
	GenericArray* result = (GenericArray*)malloc(sizeof(GenericArray));
	if (result == NULL) {
		fprintf(stderr, "array_create: malloc function has failed");
		exit(EXIT_FAILURE);
	}
	if (size == __INT_MAX__) {
		result->array = (void**)malloc(INITIAL_CAPACITY * sizeof(void*));
		result->size = INITIAL_CAPACITY;
	}
	else {
		result->array = (void**)malloc(size * sizeof(void*));
		result->size = size;
	}
	if (result->array == NULL) {
		fprintf(stderr, "array_create: malloc function has failed");
		exit(EXIT_FAILURE);
	}

	result->el_num = 0;
	return result;
}

void* array_get(GenericArray* ord_array, int index) {
	if (ord_array == NULL) {
		fprintf(stderr, "array_get: array parameter cannot be NULL");
		exit(EXIT_FAILURE);
	}
	if (index >= ord_array->el_num) {
		fprintf(stderr, "array_get: Index %lu is out of the array bounds", ord_array->el_num);
		exit(EXIT_FAILURE);
	}
	return (ord_array->array)[index];
}

int array_is_empty(GenericArray* ord_array) {
	if (ord_array == NULL) {
		fprintf(stderr, "array_is_empty: array parameter cannot be NULL");
		exit(EXIT_FAILURE);
	}
	if (ord_array->el_num == 0) {
		return 1;
	}
	return 0;
}

int array_elements(GenericArray* ord_array) {
	if (ord_array == NULL) {
		fprintf(stderr, "array_size: array parameter cannot be NULL");
		exit(EXIT_FAILURE);
	}
	return ord_array->el_num;
}


