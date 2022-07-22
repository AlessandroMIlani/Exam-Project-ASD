#ifndef GENRIC_DATA
#define GENRIC_DATA
#define INITIAL_CAPACITY 1000000

//type declaration for generic data types 
typedef struct _GenericArray {
	void** array;
	unsigned long el_num;
	unsigned long size;
}GenericArray;

/**
 * @param ord_array the array with the elements to be inserted
 * @param position the position where the element is to be inserted
 * @param val the value to be inserted
 *
 * @return void
 *
 * It inserts the element in the array at the position specified by the integer
 * If the position is out of bounds it prints an error message and exits the program
 */
void insert(GenericArray*, int, void*);

/**
 * @param ord_array the array with the elements to be swapped
 * @param first the first position to be swapped
 * @param second the second position to be swapped
 *
 * @return void

 * It swaps the elements at the positions specified by the integers
 * If the positions are out of bounds it prints an error message and exits the program
 */
void swap(GenericArray*, int, int);

/**
 * @param ord_array the array with the elements to be moved
 * @param position the original position of the element
 * @param next_position the position where the element is to be moved
 *
 * @return void
 *
 * It moves the element at the position specified by the first integer to the position specified by the second integer
 * If the positions are out of bounds it prints an error message and exits the program
 */
void move(GenericArray*, int, int);

/**
 * @param ord_array the array with the elements to be added
 * @param element the element to be added
 *
 * @return void
 *
 * It adds the element to the end of the array
 */
void array_add(GenericArray*, void*);

/**
 * @param size the size of the array to be created
 *
 * @return GenericArray*
 *
 * It creates a new generic array with the size specified by the integer or the default size if the integer is __INT_MAX__
 */
GenericArray* array_create(int);

/**
 * @param ord_array array from which the elements are get
 * @param position the position of the element to be returned
 *
 * @return void* Pointer to the element
 *
 * It returns the pointer to the element at the position specified by the integer
 */
void* array_get(GenericArray*, int);

/**
 * @param ord_array the array to check
 *
 * @return int
 *
 * return 1 if the array is empty, 0 otherwise
 */
int array_is_empty(GenericArray*);

/**
 * @param ord_array the array of which I want to know the number of elements
 *
 * @return int the number of elements in the array
 *
 * Return the number of elements in the array
 */
int array_elements(GenericArray*);

#endif
