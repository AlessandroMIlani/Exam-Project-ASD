#include "unity.h"
#include "unity_internals.h"
#include "../skiplist.h"
#include "../skiplist_aux.h"


static int i1, i2, i3, i4;
static skiplist* list;

void setUp() {
	i1 = 3;
	i2 = 1;
	i3 = 8;
	i4 = 6;
	list = create_integer_skiplist();
}

void tearDown() {
	destroy_skiplist(list);
}

static void test_order() {
	insert_list(list, &i1);
	insert_list(list, &i2);
	insert_list(list, &i3);
	insert_list(list, &i4);
	node* curr = list->head->next[0];
	int* array_of_list[4];
	int* actual[4] = { &i2,&i1,&i4,&i3 };
	for (int i = 0;i < 4;i++) {
		array_of_list[i] = curr->data;
		curr = curr->next[0];
	}
	TEST_ASSERT_EQUAL_PTR_ARRAY(actual, array_of_list, 4);
}

static void test_empty_search() {
	TEST_ASSERT_FALSE(search_skiplist(list, &i1));
}

static void test_non_empty_missing_search() {
	insert_list(list, &i2);
	insert_list(list, &i3);
	insert_list(list, &i4);
	TEST_ASSERT_FALSE(search_skiplist(list, &i1));
}

static void test_non_empty_present_search() {
	insert_list(list, &i1);
	insert_list(list, &i2);
	insert_list(list, &i3);
	insert_list(list, &i4);
	TEST_ASSERT_TRUE(search_skiplist(list, &i1));
}

int main() {
	UNITY_BEGIN();
	RUN_TEST(test_order);
	RUN_TEST(test_empty_search);
	RUN_TEST(test_non_empty_missing_search);
	RUN_TEST(test_non_empty_present_search);

	return UNITY_END();
}
