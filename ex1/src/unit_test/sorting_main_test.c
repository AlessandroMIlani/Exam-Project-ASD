#include <assert.h>
#include <stdlib.h>
#include "unity.h"
#include "../sorting_lib.h"
#include "../generic_data.h"


//Data elements that are initialized before each test
static int i1, i2, i3;
static GenericArray* dummy_array;

void setUp(void) {
	i1 = -12;
	i2 = 0;
	i3 = 4;
	dummy_array = array_create(3);
}

int compare_int(int a, int b) {
	return a < b;
}
void array_destroy(GenericArray* dummy_array) {
	free(dummy_array->array);
	free(dummy_array);
}

void tearDown() {
	array_destroy(dummy_array);
}

static void test_array_is_empty_zero_el(void) {
	TEST_ASSERT_TRUE((dummy_array));
}

static void test_array_is_empty_one_el(void) {
	array_add(dummy_array, &i1);
	TEST_ASSERT_FALSE(array_is_empty(dummy_array));
}

static void test_array_elements_zero_el(void) {
	TEST_ASSERT_EQUAL_INT(0, array_elements(dummy_array));
}

static void test_array_elements_one_el(void) {
	array_add(dummy_array, &i1);
	TEST_ASSERT_EQUAL_INT(1, array_elements(dummy_array));
}

static void test_array_add_get_three_el(void) {
	int* exp_arr[] = { &i1,&i2,&i3 };
	array_add(dummy_array, &i1);
	array_add(dummy_array, &i2);
	array_add(dummy_array, &i3);
	int** act_arr = malloc(3 * sizeof(int*));
	for (unsigned long i = 0;i < 3;i++)
		act_arr[i] = (int*)array_get(dummy_array, i);
	TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 3);
}

static void test_move(void) {
	int* exp_arr[] = { &i3,&i2,&i3 };
	array_add(dummy_array, &i1);
	array_add(dummy_array, &i2);
	array_add(dummy_array, &i3);
	int** act_arr = malloc(3 * sizeof(int*));
	move(dummy_array, 2, 0);
	for (unsigned long i = 0;i < 3;i++)
		act_arr[i] = (int*)array_get(dummy_array, i);
	TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 3);
}

static void test_swap(void) {
	int* exp_arr[] = { &i2,&i1,&i3 };
	array_add(dummy_array, &i1);
	array_add(dummy_array, &i2);
	array_add(dummy_array, &i3);
	int** act_arr = malloc(3 * sizeof(int*));
	swap(dummy_array, 0, 1);
	for (unsigned long i = 0;i < 3;i++)
		act_arr[i] = (int*)array_get(dummy_array, i);
	TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 3);
}

static void test_quick_sort(void) {
	int* exp_arr[] = { &i1,&i2,&i3 };
	array_add(dummy_array, &i2);
	array_add(dummy_array, &i3);
	array_add(dummy_array, &i1);
	quick_sort(dummy_array, compare_int);
	int** act_arr = malloc(3 * sizeof(int*));
	for (unsigned long i = 0;i < 3;i++)
		act_arr[i] = (int*)array_get(dummy_array, i);
	TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 3);
}

static void test_insertion_sort(void) {
	int* exp_arr[] = { &i1,&i2,&i3 };
	array_add(dummy_array, &i2);
	array_add(dummy_array, &i3);
	array_add(dummy_array, &i1);
	binary_insertion_sort(dummy_array, compare_int);
	int** act_arr = malloc(3 * sizeof(int*));
	for (unsigned long i = 0;i < 3;i++)
		act_arr[i] = (int*)array_get(dummy_array, i);
	TEST_ASSERT_EQUAL_PTR_ARRAY(exp_arr, act_arr, 3);
}


int main(void) {
	//test session
	UNITY_BEGIN();

	RUN_TEST(test_array_is_empty_zero_el);
	RUN_TEST(test_array_is_empty_one_el);
	RUN_TEST(test_array_elements_zero_el);
	RUN_TEST(test_array_elements_one_el);
	RUN_TEST(test_array_add_get_three_el);
	RUN_TEST(test_move);
	RUN_TEST(test_swap);
	RUN_TEST(test_quick_sort);
	RUN_TEST(test_insertion_sort);

	return UNITY_END();
}