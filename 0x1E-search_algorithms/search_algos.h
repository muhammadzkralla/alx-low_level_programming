#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H
#include <stdio.h>

int linear_search(int *array, size_t size, int value);
int binary_search(int *array, size_t size, int value);
void print_array(int *array, int l, int r);
int do_binary_search(int *array, size_t size, int value);
int jump_search(int *array, size_t size, int value);
int continue_search(int *array, size_t size
		, int value, size_t currentIdx, size_t jump);

#endif
