#ifndef SKIPLIST
#define SKIPLIST

#define MAX_HEIGHT 32

typedef struct _Node {
	struct _Node** next;
	unsigned int size;
	void* data;
}node;

typedef struct _Skiplist {
	node* head;
	unsigned int max_level;
	int (*compare)(void*, void*);
}skiplist;

/**
 * @param comapre Function pointer returning an integer with two void pointers as inputs
 *
 * @return skiplist* pointer to the skiplist allocated in the heap
 *
 * Creates a skiplist datat stucture in the heap and return a pointer to it.
 * it must receive a compare function for the desired data type wich must return
 * a postitve value if the value of the first vois pointer is greater than the
 * second, a negative converseòy and zero if the elements are equal 
 */
skiplist* create_list(int(*compare)(void*, void*));

/**
 * @param list Pointer to the skiplist where the element is being inserted
 * @param elem void pointer to the generic data which is being inserted
 *
 * @return void
 *
 * SInsets the data pointed by elem into the skiplsit pointed by list.
 */
void insert_list(skiplist* list, void* elem);

/**
 * @param list Pointer to the skiplist where the element is being searched
 * @param elem void pointer to the generic data which is being searched
 *
 * @return int
 *
 * Searchs the value pointed by elem in the skiplsit pointed by list. Returns 1
 * if the element is present int he list and 0 otherwise.
 */
int search_skiplist(skiplist* list, void* elem);

/**
 * @param list Pointer to the skiplist where the element is being searched
 *
 * @return void
 *
 * To be used on pointers generated by create_list functions(more are provided
 * in the dkiplsit_aux files), frees all of the memmoery allocated to the
 * list pointed by list.
 */
void destroy_skiplist(skiplist* list);

/**
 * @return int
 *
 * Returns a probabilistic value determined by a geometric random variable
 * correspondig to the lenght of the array of pointers, pointing to other nodes,
 * node generated by the create_node. This function is static and is only called
 * by array_create.
 */
static int random_level(void);

/**
 * @param data a void pointer to generic data
 *
 * @return node*
 *
 * Allocates memory to a anes node and returns a pointer to it, the value of
 * the node is set by the value othe void pointer parameter, and it's size
 * determined by the random level function. This function is satsic and is only
 * by insert_list.
 */
static node* create_node(void*);

#endif