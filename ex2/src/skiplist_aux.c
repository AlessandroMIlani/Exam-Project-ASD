#include "skiplist_aux.h"
#include "skiplist.h"
#include"skiplist_aux.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

skiplist* create_integer_skiplist() {
	return create_list(compare_int);
}

int compare_int(void* val, void* comp) {
	int a = *(int*)val;
	int b = *(int*)comp;
	return a - b;
}

void printlist_int(skiplist* list) {
	node* curr = list->head->next[0];
	while (curr != NULL) {
		printf("%d\n", *(int*)curr->data);
		curr = curr->next[0];
	}
}

skiplist* create_string_skiplist() {
	return create_list(compare_string);
}

int compare_string(void* val, void* comp) {
	return strcmp(val, comp);
}

void printlist_string(skiplist* list) {
	node* curr = list->head->next[0];
	while (curr != NULL) {
		printf("%s\n", (char*)curr->data);
		curr = curr->next[0];
	}
}