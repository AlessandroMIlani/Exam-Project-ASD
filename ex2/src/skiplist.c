#include "skiplist.h"
#include <stdlib.h>
#include<stdio.h>
#include<time.h>

skiplist* create_list(int(*compare)(void*, void*)) {
	skiplist* res = malloc(sizeof(skiplist));
	res->head = malloc(sizeof(node));
	res->max_level = 0;
	res->head->data = NULL;
	res->head->next = malloc(sizeof(node*) * MAX_HEIGHT);
	for (int i = 0;i < MAX_HEIGHT;i++) {
		res->head->next[i] = NULL;
	}
	res->head->size = MAX_HEIGHT;
	res->compare = compare;
	return res;
}

static node* create_node(void* data) {
	node* res = malloc(sizeof(node));
	res->size = random_level();
	res->next = malloc(sizeof(node*) * res->size);
	res->data = data;
	return res;
}

static int random_level() {
	int level = 1;
	while (rand() % 2 && level < MAX_HEIGHT) {
		level++;
	}
	return level;
}

void insert_list(skiplist* list, void* elem) {
	node* new = create_node(elem);
	if (new->size > list->max_level) {
		list->max_level = new->size;
	}
	node* curr = list->head;
	for (int i = list->max_level - 1;i >= 0;i--) {
		if (curr->next[i] == NULL || list->compare(elem, curr->next[i]->data) < 0) {
			if (i < new->size) {
				new->next[i] = curr->next[i];
				curr->next[i] = new;
			}
		}
		else {
			curr = curr->next[i];
			i++;
		}
	}
}

int search_skiplist(skiplist* list, void* elem) {
	node* curr = list->head;
	for (int i = list->max_level - 1;i >= 0; i--) {
		while (curr->next[i] != NULL && list->compare(elem, curr->next[i]->data) > 0) {
			curr = curr->next[i];
		}
	}
	if (curr->next[0] == NULL) { return 0; }
	curr = curr->next[0];
	if (list->compare(elem, curr->data) == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

void destroy_skiplist(skiplist* list) {
	node* curr = list->head;
	while (curr->next[0] != NULL) {
		node* next = curr->next[0];
		free(curr->next);
		free(curr);
		curr = next;
	}
	free(list);
}
