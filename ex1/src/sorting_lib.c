#include "sorting_lib.h"
#include "generic_data.h"
#include <stdlib.h>

#define RAND(min,max) ((rand()% (max - min +1))+min)

void binary_insertion_sort(GenericArray* pointer, int (*compare)(void*, void*)) {
	for (int i = 1;i < pointer->el_num;++i) {
		void* val = (pointer->array)[i];
		int placement = binary_search(pointer, val, 0, i - 1, compare);
		int j = i - 1;
		while (placement <= j) {
			move(pointer, j, j + 1);
			j--;
		}
		pointer->array[placement] = val;
	}
}

int binary_search(GenericArray* pointer, void* val, int start, int end, int (*compare)(void*, void*)) {
	int mid = (start + end) / 2;
	if (end <= start) {
		return(compare(val, pointer->array[start])) ? start + 1 : start;
	}
	else if (compare(val, pointer->array[mid])) {
		return binary_search(pointer, val, mid + 1, end, compare);
	}
	else {
		return binary_search(pointer, val, start, mid - 1, compare);
	}
}

void quick_sort(GenericArray* pointer, int (*compare)(void*, void*),int (*pivot)(int l,int r)) {
	quick_sort_rec(pointer, 0, pointer->el_num - 1, compare,pivot);
}

void quick_sort_rec(GenericArray* pointer, int l, int r, int (*compare)(void*, void*),int (*pivot)(int l,int r)) {
	if (l < r) {
		int p = pivot(l, r);
		swap(pointer, l, p);
		p = partition(pointer, &l, &r, compare);
		quick_sort_rec(pointer, l, p, compare,pivot);
		quick_sort_rec(pointer, p + 1, r, compare,pivot);
	}
}

int rand_partition(int l, int r) {
	return RAND(l, r);
}

int leftmost_partition(int l,int r){
	return l;
}

int rightmost_partition(int l,int r){
	return r;
}

int centerof_partition(int l,int r){
	return (l+r)/2;
}

int partition(GenericArray* pointer, int* l, int* r, int (*compare)(void*, void*)) {
  	int i=*l-1;
  	int j=*r+1;  
  	void* x = pointer->array[i+1];
	while (1) {
		do {
			i++;
		} while (compare(x, (pointer->array)[i]));
		do {
			j--;
		} while (compare((pointer->array)[j], x));
		if (i >= j)
			return j;
		swap(pointer, i, j);
	}
}
