#ifndef SOTRING_LIB
#define SOTRING_LIB

#include <stddef.h>
#include<stdlib.h>
#include<stdio.h>
#include "generic_data.h"

/**
 * @param pointer Pointer to the array to be sorted
 * @param compare Function pointer to the comparison function
 *
 * @return void
 *
 * Sort the array with a basic insertion sort algorithm, but the placement of the
 * elements is done with a binary search.
 */
void binary_insertion_sort(GenericArray*, int (*compare)(void*, void*));

/**
 * @param pointer Pointer to the array to be sorted
 * @param compare Function pointer to the comparison function
 *
 * @return the positoin of the element in the array
 *
 * It accepts as input a pointer to a generic array, a pointer, two integers and a compare function
 * search algorithm to find the position of the element in the sorted range of the array
 */
static int binary_search(GenericArray*, void*, int, int, int (*compare)(void*, void*));

/**
 * @param pointer Pointer to a generic array
 * @param l the left index of the range to be sorted
 * @param r the right index of the range to be sorted
 * @param compare Pointer to a function that compares two elements
 *
 * @return void
 *
 * Recursively sorts the array from the position specified by the first integer to the position specified by the second integer
 */
void quick_sort_rec(GenericArray*, int, int, int (*compare)(void*, void*));

/**
 * @param pointer to a generic array
 * @param compare function to compare two elements
 * @param pivot chosen function to determine the pivot
 *
 * @return void
 *
 * It's a mask function for call the quick sort from the main function
 */
void quick_sort(GenericArray*, int(*compare)(void*, void*));

/**
 * @param pointer to a generic array
 * @param l the left index of the range to be sorted
 * @param r the right index of the range to be sorted
 * @param compare a pointer to a compare function
 * @param pivot chosen function to determine the pivot
 *
 * @return the index of the next pivot element
 *
 * Compare the elemnet in the rage [l,r] with the pivot and move them to the right position
 */
int partition(GenericArray*, int*, int*, int (*compare)(void*, void*));

/**
 * @param int l the left index of the range to be sorted
 * @param int r the right index of the range to be sorted
 *
 * @return int the index of the pivot
 *
 * picks a random element in the range [l,r], move it to the right position and use it as the pivot
 *
 */
int rand_partition(int, int);

/**
 * @param int l the left index of the range to be sorted
 * @param int r the right index of the range to be sorted
 *
 * @return int the index of the pivot
 *
 * picks pivot as the leftmost element in the partition
 *
 */
int leftmost_partition(int,int);

/**
 * @param int l the left index of the range to be sorted
 * @param int r the right index of the range to be sorted
 *
 * @return int the index of the pivot
 *
 * picks pivot as the rightmost element in the partition
 *
 */
int rightmost_partition(int,int);

/**
 * @param int l the left index of the range to be sorted
 * @param int r the right index of the range to be sorted
 *
 * @return int the index of the pivot
 *
 * picks pivot as the midle element in the partition
 *
 */
int centerof_partition(int,int);

#endif
