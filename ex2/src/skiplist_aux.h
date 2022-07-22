#ifndef AUX
#define AUX
#include"skiplist.h"

/**
 * @return void
 *
 * Utility funxtions used to create a skiplsit of integer values, with a
 * provided compare function. It shall be destroyed by destroy_list function.
 */
skiplist* create_integer_skiplist();

/**
 * @param val value to comapre
 * @param comp comapred value
 *
 * @return int
 *
 * Accepts two integer values and returns a positive value if val is greater than comp,
 * a negative conversely and nil if values are equal.
 */
int compare_int(void* val, void* comp);

/**
 * @param list to be printed
 *
 * @return void
 *
 * Prints to standard output all of the integer values stored in an integer skiplsit.
 */
void printlist_int(skiplist* list);

/**
 * @return void
 *
 * Utility funxtions used to create a skiplsit of char* values, with a
 * provided compare function. It shall be destroyed by destroy_list function.
 */
skiplist* create_string_skiplist();

/**
 * @param val value to comapre
 * @param comp comapred value
 *
 * @return int
 *
 * Accepts two char* values and returns a positive value if val is greater than comp,
 * a negative conversely and nil if values are equal.
 */
int compare_string(void* val, void* comp);

/**
 * @param list to be printed
 *
 * @return void
 *
 * Prints to standard output all of the integer values stored in a String skiplsit.
 */
void printlist_string(skiplist* list);


#endif