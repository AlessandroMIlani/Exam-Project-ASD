#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"skiplist_aux.h"
#include"skiplist.h"

int string_compare(void* val, void* comp) {
	return strcmp(val, comp);
}

void check_error(FILE* txt, FILE* out, skiplist* dictionary) {
	char word[100];
	while (fscanf(txt, "%s", word) != EOF) {
		int tmp = strlen(word) - 1;
		//first letter to lowercase
		word[0] = tolower(word[0]);
		if (((int)word[tmp] >= 32 && (int)word[tmp] <= 48) || ((int)word[tmp] >= 58 && (int)word[tmp] <= 64)) {
			word[strlen(word) - 1] = '\0';
		}
		if (search_skiplist(dictionary, word) == 0) {
			fprintf(out, "%s\n", word);
		}
	}
}

int main(int argc, char const* argv[]) {
	time_t start_time = time(NULL);
	if (argc < 3) {
		printf("Usage: main_ex2 <file_name_dictionary> <file_name_tocorrect>\n");
		exit(EXIT_FAILURE);
	}
	clock_t pre = clock();

	skiplist* dictionary = create_list(string_compare);
	FILE* file = fopen(argv[1], "r");
	char word[100];
	printf("Started reading dictionary\n");
	while (fscanf(file, "%s", word) != EOF) {
		char* save = (char*)malloc(sizeof(char) * strlen(word) + 1);
		strcpy(save, word);
		insert_list(dictionary, save);
	}
	fclose(file);
	printf("Finished reading dictionary\n");

	FILE* file2 = fopen(argv[2], "r");
	FILE* file3 = fopen("Error.txt", "w");
	printf("Started reading file %s\n", argv[2]);

	check_error(file2, file3, dictionary);
	printf("Finished reading file \nStart cleaning memoery\n\n");
	fclose(file2);
	fclose(file3);
	destroy_skiplist(dictionary);
	clock_t post = clock();

	printf("time: %f\n", (double)(post - pre) / CLOCKS_PER_SEC);
	printf("Start time: %s", ctime(&start_time));
	time_t end_time = time(NULL);
	printf("End time: %s", ctime(&end_time));
	return 0;
}


