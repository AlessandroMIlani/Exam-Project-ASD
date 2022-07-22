#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "generic_data.h"
#include "sorting_lib.h"

typedef struct _record {
	int id;
	char* field1;
	int field2;
	float field3;
}record;

static void load_array(const char* file_name, GenericArray* array, int elem_num) {
	FILE* fp;
	fp = fopen(file_name, "r");
	if (fp == NULL) {
		printf("Error opening file %s\n", file_name);
		exit(1);
	}
	printf("\nLoading array from file %s...\n", file_name);
	for (int i = 0;i < elem_num;++i) {
		record* rec = (record*)malloc(sizeof(record));
		rec->field1 = (char*)malloc(sizeof(char) * 30);
		if (fscanf(fp, "%d,%[^,],%'d,%f", &(rec->id), rec->field1, &(rec->field2), &(rec->field3)) == EOF) {
			break;
		}
		array_add(array, rec);
	}
	fclose(fp);
}



int compare_string(const void* a, const void* b) {
	if (strcmp(((record*)b)->field1, ((record*)a)->field1) < 0) {
		return 1;
	}
	else
		return 0;
}

int compare_int(const void* a, const void* b) {
	return ((record*)a)->field2 > ((record*)b)->field2;
}

int compare_float(const void* a, const void* b) {
	return ((record*)a)->field3 > ((record*)b)->field3;
}

void start_order(const char* file_name, int (*compare)(void*, void*), int sort_type, int elem_num, char* file_name_out) {
	if (elem_num == -1)
		elem_num = __INT_MAX__;
	GenericArray* array = array_create(elem_num);
	load_array(file_name, array, elem_num);
	printf("Array loaded\n");
	clock_t pre_sort = clock();
	array_sort(array, compare, sort_type);
	clock_t post_sort = clock();
	printf("Sorting time: %f\n", (double)(post_sort - pre_sort) / CLOCKS_PER_SEC);
	print_array_on_file(array, file_name_out);
	printf("Array Saved\nStarting cleanup...\n");
	free_array(array);
}

int(*get_pivot())(){
	printf("Select pivot type: \n1) Random \n2) Center \n3) Leftmost \n4)Rightmost\n");
	int choice;
	scanf("%d",&choice);
	switch (choice) {
		case 1:
			return rand_partition;
		case 2:
			return centerof_partition;
		case 3:
			return leftmost_partition;
		case 4:
			return rightmost_partition;
		default:
			error("Invalid pivot type");
			exit(1);
	}
}

void array_sort(GenericArray* array, int (*compare)(void*, void*), int sort_type) {
	switch (sort_type) {
	case 1:
		printf("Sorting array with quicksort\n");
		quick_sort(array, compare,get_pivot());
		break;
	case 2:
		printf("Sorting array with insertion sort\n");
		binary_insertion_sort(array, compare);
		break;
	default:
		printf("\n Wrong sort type");
		exit(EXIT_FAILURE);
		break;
	}
}


void print_array(GenericArray* array) {
	record* record_p;
	for (int i = 0; i < array->el_num; i++) {
		record_p = (record*)array_get(array, i);
		printf("%d,%s,%d,%f\n", record_p->id, record_p->field1, record_p->field2, record_p->field3);
	}
}

void print_array_on_file(GenericArray* array, char* file_name) {
	record* record_p;
	FILE* fp;
	printf("Saving array on file %s\n", file_name);
	fp = fopen(file_name, "w");
	if (fp == NULL) {
		fprintf(stderr, "main: unable to open the file");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < array->el_num; i++) {
		record_p = (record*)array_get(array, i);

		fprintf(fp, "<%d,%s,%d,%f>\n", record_p->id, record_p->field1, record_p->field2, record_p->field3);
	}
	fclose(fp);
}


void free_array(GenericArray* array) {
	for (int i = 0; i < array->el_num; i++) {
		record* record_p = (record*)array_get(array, i);
		free(record_p->field1);
		free(record_p);
	}
}


int main(int argc, char const* argv[])
{
	//save start time
	time_t start_time = time(NULL);

	if (argc < 2) {
		printf("Usage: sorting_main <file_name>\n");
		exit(EXIT_FAILURE);
	}
	int field_to_order;
	int sorting_type;
	int elem_num;
	char file_name[20];

	printf("Select field to order: \n 1) string \n 2) int \n 3) float \n");
	scanf("%d", &field_to_order);

	printf("Select sorting type: \n 1) Quick Sort \n 2) insertion sort \n");
	scanf("%d", &sorting_type);

	printf("Number of elements to order, for use all file-> -1: \n");
	scanf("%d", &elem_num);

	printf("\nChoose file name: \n");
	scanf("%s", file_name);


	switch (field_to_order)
	{
	case 1:
		start_order(argv[1], compare_string, sorting_type, elem_num, file_name);
		break;
	case 2:
		start_order(argv[1], compare_int, sorting_type, elem_num, file_name);
		break;
	case 3:
		start_order(argv[1], compare_float, sorting_type, elem_num, file_name);
		break;
	default:
		printf("Error input");
		exit(EXIT_FAILURE);
	}

	printf("Start time: %s", ctime(&start_time));
	time_t end_time = time(NULL);
	printf("End time: %s", ctime(&end_time));
	return 0;
}
